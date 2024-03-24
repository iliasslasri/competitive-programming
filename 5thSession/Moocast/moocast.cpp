#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
vector<pair<pair<int,int>, int>> a;

void dfs(int node, vector<int> g[], pair<int, int> state[] ,int);
long double dist(int x1, int y1, int x2, int y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int max_count = 0;

int main(){
    int N;
    cin >> N;
    a.resize(N);
    for(int i = 0; i < N; i++){
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = {make_pair(x, y), z}; // z is the distance that can be reached
    }

    vector<vector<int>> g(N, vector<int>());
    // le graph
    if (N == 1){
        cout << 1 << endl;
        return 0;
    }
    for (int i = 0; i< N; i++){
        // for each edge, see if it->second can reach another edge
        for (int j = i+1; j < N; j++){ // --- we can just check the upper triangle
            if(dist(a[i].first.first, a[i].first.second, a[j].first.first, a[j].first.second) <= a[i].second){
                g[i].push_back(j); // cow i can reach cow j
            }
            if(dist(a[i].first.first, a[i].first.second, a[j].first.first, a[j].first.second) <= a[j].second){
                g[j].push_back(i); // cow j can reach cow i
            }
        }
    }

    //the graph
    // for (int i = 0; i < N; i++){
    //     if (g[i].size() > 0){
    //         cout << i << " : ";
    //         for (int j = 0; j < (int )g[i].size(); j++){
    //             cout << g[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    // BFS is better
    int result = 0;
    int count = 0;
    for (int i = 0; i < N; i++){ // iterate over all the cows
        if(g[i].size() == 0){ // if the cow cannot reach any other cow
            continue;
        }

        queue<int> q;
        q.push(i);

        vector<bool> visited(N);
        visited[i] = true;

        count = 0;
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            count++;

            for (int nb : g[cur]){
                if (!visited[nb]){
                    q.push(nb);
                    visited[nb] = true;
                }
            }
        }

        if(count > result) 
            result = count;
    }
    cout << result << endl;
    return 0;
}