// ALDS1_4_D Allocation
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_D

#include <iostream>
using namespace std;
#define MAX 100000
typedef long long llong;

int n, k;
llong T[MAX];

// 적재량이 P인 트럭 K대에 몇 개의 짐을 실을 수 있는가?
int check(llong P) {
	int i = 0;
	for (int j = 0; j < k; j++) {
		llong s = 0;
		while (s + T[i] <= P) {
			s += T[i];
			i++;
			if (i == n)
				return n;
		}
	}
	return i;
}

llong solve() {
	llong left = 0;
	llong right = 100000 * 10000; // 짐의 개수 x 1개당 최대 중량
	llong mid;
	while (right - left > 1) {
		mid = (left + right) / 2;
		int v = check(mid); // mid == P에서 몇 개를 적재할 수 있는지 확인하기
		if (v >= n) right = mid;
		else left = mid;
	}
	return right;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> T[i];
	llong ans = solve();
	cout << ans << endl;
	return 0;
}
