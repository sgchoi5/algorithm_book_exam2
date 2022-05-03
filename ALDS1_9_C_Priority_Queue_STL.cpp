// ALDS1_9_C Priority Queue
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C

#include <cstdio>
#include <string>
#include <queue>
using namespace std;

int main() {
	char com[20];
	// 표준 라이브러리 priority_queue를 사용합니다.
	priority_queue<int> PQ;

	while (1) {
		scanf("%s", com);
		if (com[0] == 'i') {
			int key; scanf("%d", &key); // cin보다 빠른 scanf를 사용했습니다.
			PQ.push(key);
		}
		else if (com[1] == 'x') {
			printf("%d\n", PQ.top());
			PQ.pop();
		}
		else if (com[0] == 'e') {
			break;
		}
	}

	return 0;
}
