#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> mp;
vector<vector<int>> dist;

// Function to find distance from node s to node ix
void distance(int s, int ix) {
	// Declare a queue to store the node and its distance from start node as a
	// pair
	queue<pair<int, int>> q;
	q.push({s, 0});
	dist[ix][s] = 0;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		for (int n : mp[p.first]) {
			if (dist[ix][n] != -1) { continue; }
			dist[ix][n] = p.second + 1;
			q.push({n, dist[ix][n]});
		}
	}
}

int main() {
	int B, E, P, N, M;
	cin >> B >> E >> P >> N >> M;
	dist.assign(4, vector<int>(N + 1, -1));
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		mp[--u].push_back(--v);
		mp[v].push_back(u);
	}

	distance(0, 0);      // finding the distance of every node from node 0
	distance(1, 1);      // finding the distance of every node from node 1
	distance(N - 1, 2);  // finding the distance of every node from node N - 1

	int min_energy = INT32_MAX;
	for (int i = 0; i < N; i++) {
		int energy = dist[0][i] * B + dist[1][i] * E + dist[2][i] * P;
		min_energy = min(min_energy, energy);
	}
	cout << min_energy << endl;
}