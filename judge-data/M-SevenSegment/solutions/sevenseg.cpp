/*
 * Seven Segment Solution by John Buck, GNY Regional 2021
 */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/*
 * Constants.  See problem description.
 */
#define	MAXSCALE	8
#define	MAXWIDTH	80
#define	MAXBITSTR	1000

/*
 * Valid character set segment bit patterns
 */
const unsigned char valid_charset[16] = {
	0x77,	/* 0 */
	0x24,	/* 1 */
	0x5d,	/* 2 */
	0x6d,	/* 3 */
	0x2e,	/* 4 */
	0x6b,	/* 5 */
	0x7b,	/* 6 */
	0x25,	/* 7 */

	0x7f,	/* 8 */
	0x6f,	/* 9 */
	0x3f,	/* A */
	0x7a,	/* b */
	0x53,	/* C */
	0x7c,	/* d */
	0x5b,	/* E */
	0x1b	/* F */
};

/*
 * We just make these global for ease.
 */
char ibuf[MAXBITSTR + 32];		/* Input buffer */
int S;							/* Scale factor */
int nLines = 0;					/* How many cell-lines of output we did */

/*
 * Display cell matrix.  Enough for biggest line of digits
 */
char cell[MAXSCALE * 7][MAXWIDTH + MAXSCALE*2 + 1];

/*
 * For scaling print's.  Max is 24 chars (MAXSCALE*3)
 */
                    /* 012345678901234567890123 */
const char *szDraw  = "XXXXXXXXXXXXXXXXXXXXXXXX";
const char *szSpace = "                        ";

/*
 * Map input digit pattern to valid one.  If pattern is bad, return
 * the special character with no segments (0000000)
 */
unsigned char MapChar(unsigned char c)
{
	int i;

	for (i = 0; i < sizeof(valid_charset); i++) {
		if (valid_charset[i] == c) {
			return(c);
		}
	}
	return(0);
}

/*
 * Fill in a horizontal segment.  There are only 3 possibilities:
 * x is the (scaled) column within the cell array of where this segment starts
 * seg is the segment number: 0, 3, 6
 * c is the bitstring for this digit
 */
void DoHorz(int x, int seg, int c)
{
	const char *f;
	int r, startr;

	/*
	 * Have to skip cell rows above us
	 */
	startr = (seg / 3) * (S + S * 2);
	/*
	 * If this segment is "on", then draw with X's else use spaces
	 */
	f = (c & (1 << seg)) ? szDraw : szSpace;
	/*
	 * Have to scale the number of rows out output within cell appropriately
	 */
	for (r = 0; r < S; r++) {
		/*
		 * Copy in appropriately scaled number of segment chars (X or spaces) and
		 * add character separator spaces to set up for next character
		 */
		snprintf(&(cell[startr + r][x]), MAXWIDTH + 2 - x, "%*.*s%*.*s",
			S * 3, S * 3, f, S * 2, S * 2, szSpace);
	}
}

/*
 * Fill in vertical segments on a row.  There are only 2 possibilities:
 * x is the (scaled) column within the cell array of where this segment starts
 * seg is the segment number: 1, 4
 * c is the bitstring for this digit
 */
void DoVert(int x, int seg, int c)
{
	const char *f1, *f2;
	int row, r;

	/*
	 * For each vertical segment on this row, set up the drawing charcter:
	 * That is, X if the segment is on, space if it is off
	 * f1 is the left segment, f2 is the right segment
	 */
	f1 = (c & (1 << seg)) ? szDraw : szSpace;
	f2 = (c & (1 << (seg + 1))) ? szDraw : szSpace;
	/*
	 * Determine row within cell to start at.  This is a function of the
	 * vertical segment number
	 */
	if (seg == 1) {
		/*
		 * For the first vertical segments, we only have to skip the first horizontal segment
		 * scaled appropriately
		 */
		row = S;
	} else {
		/*
		 * For the second vertical segments, we have to skip the first and second horizontal segments,
		 * and the first vertical segment, all scaled appropriately
		 */
		row = S + S*2 + S;
	}
	/*
	 * Send out scaled output rows within cell for vertical segment(s).
	 * Each vertical is done 2 times, but that has to be scaled
	 */
	for (r = 0; r < S * 2; r++) {
		/*
		 * Do the left segment, spaces between left and right segment, right segment and
		 * spaces to next character cell
		 */
		snprintf(&(cell[row + r][x]), MAXWIDTH + 2 - x, "%*.*s%*.*s%*.*s%*.*s",
			S, S, f1, S, S, szSpace, S, S, f2, S * 2, S * 2, szSpace);
	}
}

/*
 * Send the output cell row.
 * width is the max we want to print out.  This does NOT include the extra inter-character space(s).
 */
void DoFlush(int width)
{
	int r, rows = S * 7;

	/*
	 * Only leave space between rows of cells if we did one already
	 */
	if (nLines++ > 0) {
		for (r = 0; r < S; r++) {
			printf("\n");
		}

	}
	for (r = 0; r < rows; r++) {
		printf("%*.*s\n", width, width, &(cell[r][0]));
	}
}

int main()
{
	int n, width, nout, nchar;
	int x, nstate, c;
	char* s;

	if (fgets(&(ibuf[0]), sizeof(ibuf), stdin) != NULL) {
		/* We know scale factor is first thing on the line.  No error checking is needed. */
		S = ibuf[0] - '0';
		/* Calculate Max cells wide (n) - we do this iteravely due to the inter-char spacing on the line */
		for (width = n = 0; ; ) {
			/* Width of charcter */
			width += S * 3;
			/* If wont fit, we're done */
			if (width > 80) {
				break;
			}
			/* This char will fit */
			n++;
			/* If it fits exactly, we are done */
			if (width == 80) {
				break;
			}
			/* Add in inter-char spaces */
			width += S * 2;
		}
		/* How many bits were supplied */
		for (s = &(ibuf[2]); *s == '0' || *s == '1'; s++) {
		}
		nchar = s - &(ibuf[2]);
		/* Set initial state to possible non-multiple of 7 */
		nstate = nchar % 7;
		/* If not a multiple of 7, then prime the state machine with 0 bits */
		if (nstate != 0) {
			nstate = 7 - nstate;
		}
		/*
		 * This is the bit string for the next digit
		 */
		c = 0;
		for (s = &(ibuf[2]), x = nout = 0; nchar-- > 0; s++) {
			c <<= 1;
			if (*s == '1') {
				c |= 1;
			}
			nstate++;
			/*
			 * When we get 7 bits, it's time to plop the character into the cell matrix
			 */
			if (nstate == 7) {
				/* Get valid character */
				c = MapChar(c);
				/* Top horizontal segment */
				DoHorz(x, 0, c);
				/* Vertical segments */
				DoVert(x, 1, c);
				/* Middle horizontal segment */
				DoHorz(x, 3, c);
				/* Vertical segments */
				DoVert(x, 4, c);
				/* Bottom horizontal segment */
				DoHorz(x, 6, c);

				/* Finished this char, cleanup for next time and see if we have to flush */
				nstate = 0;
				c = 0;
				nout++;
				/*
				 * Did we fill this line with cells yet?
				 */
				if (nout >= n) {
					/* Output cells here using correct width, subtracting off last inter-char spaces */
					DoFlush(n*S*5 - S*2);
					/* Can't fit more chars, so restart for next row */
					x = nout = 0;
				} else {
					/* Advance starting position.  Each digit takes up 5 columns (3 + 2) (scaled appropriately) */
					x += S * 5;
				}
			}
		}
		/*
		 * If we have any characters in the cell matrix, output them now
		 */
		if (nout > 0) {
			DoFlush(nout * S * 5 - S * 2);
		}
		return(0);
	}
}
