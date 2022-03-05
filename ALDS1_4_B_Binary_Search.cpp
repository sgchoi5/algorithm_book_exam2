// ALDS1_4_B Binary Search
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B

#include <stdio.h>

int A[10000000], n;

/* 이진 탐색 */
int binarySearch(int key) {
	int left = 0;
	int right = n;
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if(key == A[mid]) return 1;         /* key 발견 */
		if (key > A[mid]) left = mid + 1;   /* 뒷부분 탐색 */
		else if (key < A[mid]) right = mid; /* 앞부분 탐색 */
	}
	return 0;
}

int main() {
	int i, q, k, sum = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d", &k);
		if (binarySearch(k)) sum++;
	}
	printf("%d\n", sum);

	return 0;
}
