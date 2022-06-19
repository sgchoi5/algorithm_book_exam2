// ALDS1_11_A Graph
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_A

#include<iostream>
using namespace std;
static const int N = 100;

int main() {
	int M[N][N]; // 0-기반 인접 행렬
	int n, u, k, v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) M[i][j] = 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> u >> k;
		u--; // 0-기반으로 변환
		for (int j = 0; j < k; j++) {
			cin >> v;
			v--; // 0-기반으로 변환
			M[u][v] = 1; // u와 v 사이에 에지 추가
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j) cout << " ";
			cout << M[i][j];
		}
		cout << endl;
	}

	return 0;
}
