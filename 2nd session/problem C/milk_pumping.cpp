#include <iostream>
#include <set>
#include <vector>

#define INF 1000000000

using namespace std;

int main(){
    int N, M;
    cin >> N;
    cin >> M;
    int k = M;
    int i, j;
    int adjfirst, adjsecond;
    // read the input
    set<pair<pair<int, int>, int>> nxt[N]; // ( le next, cost, flow)
    while(k--){ // line = i j c f
        cin >> i;
        cin >> j;
        cin >> adjfirst; // cost
        cin >> adjsecond; // flow
        nxt[i-1].insert(make_pair(make_pair(j-1, adjfirst), adjsecond));
        nxt[j-1].insert(make_pair(make_pair(i-1, adjfirst), adjsecond));
    }
    set<int> flows;
    // extract the flows from nxt 
    for (int i = 0; i < N; i++){
        for (auto v : nxt[i]){
            flows.insert(v.second);
        }
    }
    // Dijsktra ( we will do M dijsktra, because we have M pipes )
    k = 0;
    long long res = -1;
    for (int flow : flows){
        int start_node = 0;
        int dist[N];
        fill(dist, dist+N, INF);
        set<pair<int, int>> p_queue; // (le node, weight, flow vers ce node)
        p_queue.insert(make_pair(start_node, 0));
        dist[start_node] = 0;
        while(!p_queue.empty()) {

            auto [node_dist, node] = *p_queue.begin() ; // c++17
            p_queue.erase(p_queue.begin());

            for(auto v : nxt[node]){
                if ( v.second >= flow ){
                    if( node_dist + v.first.second < dist[v.first.first]) {
                        p_queue.erase(make_pair(dist[v.first.first],v.first.first));
                        dist[v.first.first] = (node_dist + v.first.second);
                        p_queue.insert(make_pair(dist[v.first.first],v.first.first));
                    }
                }
            }
        }
        // -- Dijsktra done -- 

        if (1000000LL * flow / dist[N-1] > res){
            res = 1000000LL * flow / dist[N-1];
        }
    }
    cout << res << endl;
    return 0;
}