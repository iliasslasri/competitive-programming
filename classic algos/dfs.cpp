#include <vector>

int state[1000];
vector<int> nbers[1000]; // y is in Adj[x] if an edge between node x and y exists • Pairs to represent weights

void dfs(int node){
    if(state[node] == 0){
        state[node] = 1; // in visit
        for(int nb : nbers[node]){
            dfs(nb);
        }
        state[node] = 2; // visited
    }
}