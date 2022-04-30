// ALDS1_9_B Maximum Heap
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_B

#include <iostream>
using namespace std;

#define MAX 2000000

int H, A[MAX + 1];

void maxHeapify(int i) {
	int l, r, largest;
	l = 2 * i;
	r = 2 * i + 1;

	// 왼쪽 자식, 자신, 오른쪽 자식에서 최대인 값을 선택합니다.
	if (l <= H && A[l] > A[i]) largest = l;
	else largest = i;
	if (r <= H && A[r] > A[largest]) largest = r;

	if (largest != i) {
		swap(A[i], A[largest]);
		maxHeapify(largest);
	}
}

int main() {
	cin >> H;

	for (int i = 1; i <= H; i++) cin >> A[i];

	for (int i = H / 2; i >= 1; i--) maxHeapify(i);

	for (int i = 1; i <= H; i++) {
		cout << " " << A[i];
	}
	cout << endl;

	return 0;
}
