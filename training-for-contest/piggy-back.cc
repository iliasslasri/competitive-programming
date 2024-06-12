#include <vector>    // For std::vector
#include <utility>   // For std::pair
#include <iostream>  // For std::cout, std::cin, etc.
#include <algorithm> // Include this if you need any algorithms
#include <set>

#define NB_NODES_MAX 40000

const int INF = 400000000;

using namespace std;

int nbEdges, nbNodes;
long long* dijkstra(int start_node, vector<int> nxt[], long long cost, long long *);

int main() {
    vector<int> nxt[NB_NODES_MAX];

    // reading B, E, P, N, M
    int B, E, P, N, M;
    cin >> B >> E >> P >> N >> M;

    for (int i = 0; i < M; i++) {
        int m, n;
        cin >> n >> m;
        nxt[n-1].push_back(m-1);
        nxt[m-1].push_back(n-1);
    }

    long long distancesA[NB_NODES_MAX];
    dijkstra(0, nxt, B, distancesA);
    long long distancesB[NB_NODES_MAX];
    dijkstra(1, nxt, E, distancesB);

    // cout << "Distances from node 1:" << endl;
    // for (int i = 0; i < N; i++) {
    //     if (distancesB[i] == INF) {
    //         cout << "Node " << i + 1 << ": INF" << endl; // Node numbering is 1-based
    //     } else {
    //         cout << "Node " << i + 1 << ": " << distancesB[i] << endl;
    //     }
    // }
    long long distances[NB_NODES_MAX];
    dijkstra(N-1, nxt, P, distances);

    long long energy = distancesB[N-1] + distancesA[N-1];
    long long temp_energy = INF;
    for(int i=0; i< N; i++){

        long long m = distancesA[i];
        long long n = distancesB[i];
        // cout << "i " << i << endl;

        // cout << "m " << m << ", n :" << n << endl;

        if(m != INF && n!= INF){
            
            // cout << "Distances from node " << endl;
            // for (int i = 0; i < N; i++) {
            //     if (distances[i] == INF) {
            //         cout << "Node " << i  << ": INF" << endl; // Node numbering is 1-based
            //     } else {
            //         cout << "Node " << i << ": " << distances[i] << endl;
            //     }
            // }

            if(distances[N-1] != INF){
                temp_energy = m+ n+ distances[i];
                energy = min(temp_energy,energy);
                
            }
        }
    }
    cout << energy << endl;
    return 0;
}


long long* dijkstra(int start_node, vector<int> nxt[], long long cost, long long *dist) {
    fill(dist, dist + NB_NODES_MAX, INF);
    set<pair<long long, int>> p_queue;
    p_queue.insert(make_pair(0, start_node));
    dist[start_node] = 0;

    while (!p_queue.empty()) {
        auto [node_dist, node] = *p_queue.begin();
        p_queue.erase(p_queue.begin());

        for (auto v : nxt[node]) {
            if (node_dist + cost < dist[v]) {
                p_queue.erase(make_pair(dist[v], v));
                dist[v] = node_dist + cost;
                p_queue.insert(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}
