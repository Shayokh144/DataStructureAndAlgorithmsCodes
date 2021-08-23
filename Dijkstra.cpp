//https://codeforces.com/contest/20/problem/C

#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

long long int distanceArr[100004];
int prevArr[100004];
vector<int>graph[100004];
map<pair<int,int>,long long int>costMap;
priority_queue<int>pq;

bool dijkastra(int src, int dest) {
	bool isFound = false;
	pq.push(src);
	long long int cost;
	while (!pq.empty()) {
		src = pq.top();
		pq.pop();
		for (int i = 0; i< graph[src].size(); i++) {

			if (src > graph[src][i]) {
				cost = costMap[{graph[src][i], src}];
			}
			else {
				cost = costMap[{src, graph[src][i]}];
			}
			if (distanceArr[graph[src][i]] < 0 || (distanceArr[src] + cost < distanceArr[graph[src][i]])) {
				distanceArr[graph[src][i]] = distanceArr[src] + cost;
				prevArr[graph[src][i]] = src;
				if (graph[src][i] == dest) {
					isFound = true;
				}
				pq.push(graph[src][i]);
			}
		}
	}
	return isFound;
}

void clearData(int n) {
	for (int i = 0; i <= n; i++) {
		distanceArr[i] = -1;
		prevArr[i] = -1;
	}
	costMap.clear();
}

void printPath(int n) {
	if (prevArr[n] != -1) {
		printPath(prevArr[n]);
	}
	cout << n << " ";
}

int main() {
	int n, m, a, b, w;
	cin >> n >> m;
	clearData(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		graph[a].push_back(b);
		graph[b].push_back(a);
		if (a < b) {
			costMap[{a, b}] = w;
		}
		else {
			costMap[{b, a}] = w;
		}
	}
	bool isFound = dijkastra(1, n);
	if (isFound) {
		// print path
		prevArr[1] = -1;
		printPath(n);
		cout << "\n";
	}
	else {
		cout << -1 << "\n";
	}

	return 0;
}
