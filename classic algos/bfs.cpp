#include <bits/c++config.h>
#include <vector>

int seen[1000];

void bfs(int start) {
    vector<int> todo = {start} ;
    seen[start] = true ;
    for(size_t id = 0 ; id < todo.size() ; id++)
        for(auto v : nxt[todo[id]])
            if(!seen[v]) {
                seen[v] = true;
                todo.push_back(v);
            }
}