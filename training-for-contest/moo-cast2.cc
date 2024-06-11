#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dist(int x1, int x2, int y1, int y2);

vector<int> repr ; // initialized to -1
int find(int x) {
if(repr[x] < 0) return x;
return repr[x]=find(repr[x]); // path compression
}

bool unite(int a, int b) {
a = find(a);
b = find(b);
if(a==b) { return false; }
if(repr[a] > repr[b]) { swap(a,b); } // size
repr[a] += repr[b] ;
repr[b] = a;
return true;
}
int main(){
    int N;
    cin >> N;
    vector<pair<long long, pair<int,int> > > edges;
    vector<pair<int, int>> nodes;
    int x,y;
    for (int i=0; i<N; i++){
        repr.push_back(-1);
        cin >> x >> y;
        nodes.push_back({x,y});
    }
    long long distance;
    for (int i=0; i< N; i++){
        for (int j=i+1; j<N; j++){
            distance = dist(nodes[i].first, nodes[j].first, nodes[i].second, nodes[j].second);
            edges.push_back({distance, {i,j}});
        }
    }

    // for (int i=0; i< N; i++){
    //     for (int j=i+1; j<N; j++){
    //         cout << "i :" << i << ";j :" << j << "distance is "<< edges[j].first  <<endl;
    //     }
    // }
    // minimum spanning tree
    sort(edges.begin(),edges.end());
    long long min_weight_mst = 0;
    for(auto [w,p] : edges)
        if(unite(p.first,p.second)){
            // cout << w << endl;
            min_weight_mst = max(min_weight_mst, w);
        }

    cout << min_weight_mst;
    return 0;
}


long long dist(int x1, int x2, int y1, int y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}