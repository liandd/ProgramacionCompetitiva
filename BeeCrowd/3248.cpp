#include<bits/stdc++.h>
using namespace std;
long long merge(vector<int>& a, int left, int mid, int right) {
    int i = left, j = mid+1, k = 0;
    long long count = 0;
    vector<int> temp(right-left+1);

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            count += mid-i+1;
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }

    while (j <= right) {
        temp[k++] = a[j++];
    }

    for (int i = left, k = 0; i <= right; i++, k++) {
        a[i] = temp[k];
    }

    return count;
}

long long mergeSort(vector<int>& a, int left, int right) {
    if (left >= right) {
        return 0;
    }

    int mid = left + (right-left)/2;
    long long count = 0;

    count += mergeSort(a, left, mid);
    count += mergeSort(a, mid+1, right);
    count += merge(a, left, mid, right);

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long count = mergeSort(a, 0, n-1);

    cout << count << endl;

    return 0;
}
