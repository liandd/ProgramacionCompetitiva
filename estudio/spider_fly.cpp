/*
 * Fly-Spider - GNY Regional 2021 - Fred Pickel
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#undef TEST
#define EPS (.0001)
#define BACK	0
#define FRONT	1
#define BOTTOM	2
#define TOP		3
#define LEFT	4
#define RIGHT	5

#define V000	0
#define V100	1
#define V010	2
#define V110	3
#define V001	4
#define V101	5
#define V011	6
#define V111	7

typedef unsigned char BYTE;

/*
 the general idea is that we
 unfold the box in all posible ways and measure distance from spider to fly
 on the unfolded box
 we start with a face containing the spider and at each step visit all
 adjacent faces that have not yet been visited untill we reach a face
 containing the fly
 as we go from face to face we convert the coordinates of the spider and the
 ends of all edges we have crossed to the coordinates system of the next face
 when we get to the fly face we compute the distance from the spider (in fly
 coordinates to the fly

  as we cross each edge, one coordinate stays the same an one coordinate
  is new replacing the other old coordinate new = offset +- old
*/
typedef struct _trans_
{
	double offset;
	BYTE zeroInd;	// old coord set to one of its limits
	BYTE sameInd;	// coord that stays the same
	BYTE newInd;	// new coord
	BYTE newNeg;	// 1 if new = offset - old else new = offset + old
	BYTE which;		// which face old is now on give coord value for ol
	BYTE vert1Ind;	// index in verts array of one end of edge crossed
	BYTE vert2Ind;	// index in verts array of other end of edge crossed
} TRANS, *PTRANS;

typedef struct _search_node_
{
	double prevCorn1[5][3];	// corners for each edge crossed in order from spider to flay
	double prevCorn2[5][3];	// in current coord system
	double spiderTrans[3];	// spider location in current coord system
	BYTE curFace;			// current face lable
	BYTE usedFaceMask;		// bitmask of faces already visited
	BYTE depth;				// how many edges crossed on the current path
} SEARCHNODE, *PSEARCHNODE;

SEARCHNODE search[6];

double Len, Wid, Ht, bestDist;
double spider[3], fly[3];
double verts[8][3];
double baseval[6];
int spider_face, fly_face,spider_face_mask, fly_face_mask;

BYTE whichMasks[6] = {1, 2, 4, 8, 0x10, 0x20};	// conver face index to bitmaks
BYTE ignore[6] = {2, 2, 1, 1, 0, 0};	// which coord is not active in current coord system

// trans[a][b] = transformation info for going from face a to face b
TRANS trans[6][4] =
{
	{	// BACK
		{0.0, 1, 0, 2, 1, BOTTOM, V000, V100}, // z = -y, x=x
		{0.0, 1, 0, 2, 0, TOP, V010, V110},		//z = y-H, x=x
		{0.0, 0, 1, 2, 1, LEFT, V000, V010},	// z = -x, y=y
		{0.0, 0, 1, 2, 0, RIGHT, V100, V110},	// z = x - W, y=y
	},
	{	// FRONT
		{0.0, 1, 0, 2, 0, BOTTOM, V001, V101}, // z = L+y, x=x
		{0.0, 1, 0, 2, 1, TOP, V011, V111},		//z = L+H-y, x=x
		{0.0, 0, 1, 2, 0, LEFT, V001, V011},	// z = L+x, y=y
		{0.0, 0, 1, 2, 1, RIGHT, V101, V111},	// z = L+W-x, y=y
	},
	{	// BOTTOM
		{0.0, 2, 0, 1, 1, BACK, V000, V100},	// y = -z, x=x
		{0.0, 2, 0, 1, 0, FRONT, V001, V101},	// y = z - L, x=x
		{0.0, 0, 2, 1, 1, LEFT, V000, V001},	// z = z, y = -x
		{0.0, 0, 2, 1, 0, RIGHT, V100, V101},	// z = z, y=x-W
	},
	{	// TOP
		{0.0, 2, 0, 1, 0, BACK, V010, V110},	// y = H+z, x=x
		{0.0, 2, 0, 1, 1, FRONT, V011, V111},	// y = H+L-z, x=x
		{0.0, 0, 2, 1, 0, LEFT, V010, V011},	// z = z, y = H+x
		{0.0, 0, 2, 1, 1, RIGHT, V110, V111},	// z = z, y=H+W-x
	},
	{	// LEFT
		{0.0, 2, 1, 0, 1, BACK, V000, V010},	// y = y, x=-z
		{0.0, 2, 1, 0, 0, FRONT, V001, V011},	// y = y, x=z-L
		{0.0, 1, 2, 0, 1, BOTTOM, V000, V001}, // z = z, x=-y
		{0.0, 1, 2, 0, 0, TOP, V010, V011},		//z = z, x=y - H
	},
	{	// RIGHT
		{0.0, 2, 1, 0, 0, BACK, V100, V110},	// y = y, x=W+z
		{0.0, 2, 1, 0, 1, FRONT, V101, V111},	// y = y, x=W+L-z
		{0.0, 2, 0, 1, 0, BOTTOM, V100, V101}, // x = W+y, z=z
		{0.0, 2, 0, 1, 1, TOP, V110, V111},		//x = W+H-y, z=z
	},
};

// some trans and other values depend on room dimensions
// init them
int setTrans()
{
	int i;
	trans[0][1].offset = -Ht;
	trans[0][3].offset = -Wid;
	trans[1][0].offset = Len;
	trans[1][1].offset = Len+Ht;
	trans[1][2].offset = Len;
	trans[1][3].offset = Len+Wid;
	trans[2][1].offset = -Len;
	trans[2][3].offset = -Wid;
	trans[3][0].offset = Ht;
	trans[3][1].offset = Len+Ht;
	trans[3][2].offset = Ht;
	trans[3][3].offset = Ht+Wid;
	trans[4][1].offset = -Len;
	trans[4][3].offset = -Ht;
	trans[5][0].offset = Wid;
	trans[5][1].offset = Len+Wid;
	trans[5][2].offset = Wid;
	trans[5][3].offset = Ht+Wid;
	for(i = 0; i < 8 ; i++) {
		if((i & 1) != 0) {
			verts[i][0] = Wid;
		} else {
			verts[i][0] = 0.0;
		}
		if((i & 2) != 0) {
			verts[i][1] = Ht;
		} else {
			verts[i][1] = 0.0;
		}
		if((i & 4) != 0) {
			verts[i][2] = Len;
		} else {
			verts[i][2] = 0.0;
		}
	}
	baseval[0] = baseval[2] = baseval[4] = 0.0;
	baseval[1] = Len; baseval[3] = Ht;
	baseval[5] = Wid;
	return 0;
}

// apply ptrans to pIn point to get pOut pt in new coord system
int doTrans(double *pIn, double *pOut, PTRANS pTrans)
{
	pOut[pTrans->sameInd] = pIn[pTrans->sameInd];
	if(pTrans->newNeg) {
		pOut[pTrans->newInd] =
			pTrans->offset - pIn[pTrans->zeroInd];
	} else {
		pOut[pTrans->newInd] =
			pTrans->offset + pIn[pTrans->zeroInd];
	}
	pOut[pTrans->zeroInd] = baseval[pTrans->which];
	return 0;
}

// reverse trans
int undoTrans(double *pIn, double *pOut, PTRANS pTrans)
{
	pOut[pTrans->sameInd] = pIn[pTrans->sameInd];
	if(pTrans->newNeg) {
		pOut[pTrans->zeroInd] =
			pTrans->offset - pIn[pTrans->newInd];
	} else {
		pOut[pTrans->zeroInd] =
			-(pTrans->offset) + pIn[pTrans->zeroInd];
	}
	pOut[pTrans->newInd] = 0.0;
	return 0;
}

// check that input point is on a face and return a mask
// of faces it is on
int CheckOnBdy(double *p)
{
	int ret = 0;
	int val = -3;
	if((p[0] < 0.0) || (p[1] < 0.0) || (p[2] < 0.0)) {
		return -1;
	}
	if((p[0] > Wid) || (p[1] > Ht) || (p[2] > Len)) {
		return -2;
	}
	if(p[0] < EPS) {
		ret |= whichMasks[LEFT];
		val = LEFT;
	}
	else if(p[0] > Wid - EPS) {
		ret |= whichMasks[RIGHT];
		val = RIGHT;
	}
	if(p[1] < EPS) {
		ret |= whichMasks[BOTTOM];
		val = BOTTOM;
	}
	else if(p[1] > Ht - EPS) {
		ret |= whichMasks[TOP];
		val = TOP;
	}
	if(p[2] < EPS) {
		ret |= whichMasks[BACK];
		val = BACK;
	}
	else if(p[2] > Len - EPS) {
		ret |= whichMasks[FRONT];
		val = FRONT;
	}
	if(ret == 0) {
		return -3;
	}
	return (ret | (val << 8));
}

// init search tree at spider face
void SetupSearch(void)
{
	search[0].curFace = spider_face;
	search[0].depth = 0;
	search[0].usedFaceMask = whichMasks[spider_face];
	search[0].spiderTrans[0] = spider[0];
	search[0].spiderTrans[1] = spider[1];
	search[0].spiderTrans[2] = spider[2];
	bestDist = 2.0*(Len+Wid+Ht);
}

// check that the line segments p1->p2 and p3->p4 intersect
int CheckCross(double *p1, double *p2, double *p3, double *p4, int face)
{
	double pp1[2], pp2[2], pp3[2], pp4[2];
	double dx1, dx2, dy1, dy2, d1, d2, den, t1, t2;
	int ig;
	ig = ignore[face];
	switch(ig) {
	case 0:
		pp1[0] = p1[1]; pp1[1] = p1[2];
		pp2[0] = p2[1]; pp2[1] = p2[2];
		pp3[0] = p3[1]; pp3[1] = p3[2];
		pp4[0] = p4[1]; pp4[1] = p4[2];
		break;
	case 1:
		pp1[0] = p1[0]; pp1[1] = p1[2];
		pp2[0] = p2[0]; pp2[1] = p2[2];
		pp3[0] = p3[0]; pp3[1] = p3[2];
		pp4[0] = p4[0]; pp4[1] = p4[2];
		break;
	case 2:
		pp1[0] = p1[0]; pp1[1] = p1[1];
		pp2[0] = p2[0]; pp2[1] = p2[1];
		pp3[0] = p3[0]; pp3[1] = p3[1];
		pp4[0] = p4[0]; pp4[1] = p4[1];
		break;
	default:
		return 0;
	}
	dx1 = pp2[0] - pp1[0];
	dy1 = pp2[1] - pp1[1];
	dx2 = pp4[0] - pp3[0];
	dy2 = pp4[1] - pp3[1];
	d1 = pp3[0] - pp1[0];
	d2 = pp3[1] - pp1[1];
	den = dy2*dx1 - dx2*dy1;
	if(fabs(den) < EPS) {	// parallel
		return 0;
	}
	t1 = (dy2*d1 - dx2*d2)/den;
	t2 = (dy1*d1 - dx1*d2)/den;
	if((t1 < 0.0) || (t1 > 1.0) || (t2 < 0.0) || (t2 > 1.0)) {
		return 0;
	}
	return 1;
}

// check that line from spider to fly cr crosses each of the edge
// segemnts along the path
int Validate(PSEARCHNODE p)
{
	int ret, i;
	ret = 1;
	for(i = 0; i < p->depth ; i++) {
		if(CheckCross(&(fly[0]), &(p->spiderTrans[0]),
			&(p->prevCorn1[i][0]), &(p->prevCorn2[i][0]), p->curFace) == 0) {
			return 0;
		}
	}
	return 1;
}

// if current face is the fly face find dist form spider
// to fly in fly coordinate system and check that path crosses each edge segment
// if shorter tha current dist remenber i
// otherwsie
// for each adjacent face that has not been visited
// set up new search node convert everything to new coord system and recurse
void DoSearch(PSEARCHNODE pCur)
{
	BYTE curFace, nxtFace, curLev, i, j;
	PSEARCHNODE pNxt;
	PTRANS pTrans;
	double dist;
	curLev = pCur->depth;
	pNxt = &(search[curLev+1]);
	curFace = pCur->curFace;
	if(curFace == fly_face) {	// check if distance is better and valid
		dist = (pCur->spiderTrans[0] - fly[0])*(pCur->spiderTrans[0] - fly[0]);
		dist += (pCur->spiderTrans[1] - fly[1])*(pCur->spiderTrans[1] - fly[1]);
		dist += (pCur->spiderTrans[2] - fly[2])*(pCur->spiderTrans[2] - fly[2]);
		dist = sqrt(dist);
		if(dist < bestDist) {
			if(Validate(pCur)) {
				bestDist = dist;
#ifdef SAVE_PATH
				// save best path verts
#endif
			}
		}
		return;
	}
	for(i = 0; i < 4; i++) {
		pTrans = &(trans[curFace][i]);
		nxtFace = pTrans->which;
		if((pCur->usedFaceMask & whichMasks[nxtFace]) != 0) {
			// already been on this face. skip it
			continue;
		}
		// setup new search struct
		pNxt->curFace = nxtFace;
		pNxt->depth = curLev+1;
		pNxt->usedFaceMask = pCur->usedFaceMask | whichMasks[nxtFace];
		doTrans(&(pCur->spiderTrans[0]), &(pNxt->spiderTrans[0]), pTrans);
		for(j = 0; j < curLev; j++) {
			doTrans(&(pCur->prevCorn1[j][0]), &(pNxt->prevCorn1[j][0]), pTrans);
			doTrans(&(pCur->prevCorn2[j][0]), &(pNxt->prevCorn2[j][0]), pTrans);
		}
		// add segment between cur and nxt
		for(j = 0; j < 3; j++) {
			pNxt->prevCorn1[curLev][j] = verts[pTrans->vert1Ind][j];
			pNxt->prevCorn2[curLev][j] = verts[pTrans->vert2Ind][j];
		}
		DoSearch(pNxt);
	}
}

// setup spider face and do depth first search of all posible trees
double Solve(void)
{
	SetupSearch();
	DoSearch(&search[0]);
	return bestDist;
}

char inbuf[256];
int main()
{
	double ret = 0.0;
#ifdef TEST
	while(1) {
#endif
	if(fgets(&(inbuf[0]), 255, stdin) == NULL) {
		fprintf(stderr, "read failed on dimensions\n");
		return -2;
	}
	if(sscanf(&(inbuf[0]), "%lf %lf %lf",
		&Wid, &Ht, &Len) != 3) {
		fprintf(stderr, "scan failed on dimensions\n");
		return -3;
	}
	if((Len < 1.0) || (Wid < 1.0) || (Ht < 1.0) ||
		(Len > 100.0) || (Wid > 50.0) || (Ht > 30.0)) {
		fprintf(stderr, "Dimenstions out of range\n");
		return -4;
	}
	if(fgets(&(inbuf[0]), 255, stdin) == NULL) {
		fprintf(stderr, "read failed on spider\n");
		return -5;
	}
	if(sscanf(&(inbuf[0]), "%lf %lf %lf",
		&spider[0], &spider[1], &spider[2]) != 3) {
		fprintf(stderr, "scan failed on spider\n");
		return -6;
	}
	if((spider_face_mask = CheckOnBdy(&(spider[0]))) < 0) {
		fprintf(stderr, "Spider not on boundary\n");
		return -7;
	}
	spider_face = (spider_face_mask >> 8);
	spider_face_mask &= 0x3f;
	if(fgets(&(inbuf[0]), 255, stdin) == NULL) {
		fprintf(stderr, "read failed on fly\n");
		return -8;
	}
	if(sscanf(&(inbuf[0]), "%lf %lf %lf",
		&fly[0], &fly[1], &fly[2]) != 3) {
		fprintf(stderr, "scan failed on fly\n");
		return -9;
	}
	if((fly_face_mask = CheckOnBdy(&(fly[0]))) < 0) {
		fprintf(stderr, "Fly not on boundary\n");
		return -10;
	}
	fly_face = (fly_face_mask >> 8);
	fly_face_mask &= 0x3f;
	setTrans();
	if((spider_face_mask & fly_face_mask) != 0) {	// on same face, just get dist
		ret = (spider[0] - fly[0]) * (spider[0] - fly[0]);
		ret += (spider[1] - fly[1]) * (spider[1] - fly[1]);
		ret += (spider[2] - fly[2]) * (spider[2] - fly[2]);
		ret = sqrt(ret);
	} else {
		ret = Solve();
	}
	printf("%0.3lf\n", ret);
#ifdef TEST
	}
#endif
	return 0;
}



