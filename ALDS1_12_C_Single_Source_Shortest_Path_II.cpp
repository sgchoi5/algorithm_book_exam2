// ALDS1_12_C Single Source Shortest Path II
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_C

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
static const int MAX = 10000;
static const int INFTY = (1<<21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n;
vector<pair<int, int> > adj[MAX]; // 인접 리스트를 사용한 가중치 방향 그래프 표현

void dijkstra() {
	priority_queue<pair<int, int> > PQ;
	int color[MAX];
	int d[MAX];
	for (int i = 0; i < n; i++) {
		d[i] = INFTY;
		color[i] = WHITE;
	}

	d[0] = 0;
	PQ.push(make_pair(0, 0));
	color[0] = GRAY;

	while (!PQ.empty()) {
		pair<int, int> f = PQ.top();
		PQ.pop();

		int u = f.second;

		color[u] = BLACK;

		// 최솟값을 추출하고, 최단 거리가 아니라면 무시
		if (d[u] < f.first * (-1))
			continue;

		for (int j = 0; j < adj[u].size(); j++) {
			int v = adj[u][j].first;
			if (color[v] == BLACK)
				continue;
			if (d[v] > d[u] + adj[u][j].second) {
				d[v] = d[u] + adj[u][j].second;
				// priority_queue는 기본적으로 크기 값을 우선하므로 -1을 곱함
				PQ.push(make_pair(d[v] * (-1), v));
				color[v] = GRAY;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
	}
}

int main(void) {
	int k, u, v, c;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> u >> k;
		for (int j = 0; j < k; j++) {
			cin >> v >> c;
			adj[u].push_back(make_pair(v, c));
		}
	}
	
	dijkstra();

	return 0;
}
