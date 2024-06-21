#include <iostream>
#include <set>
#include <map>

#include <queue>


using namespace std;
int N, M;

set<pair<int, int>> get_neigbors(pair<int, int> a){
    if(a.first == 1){
        if(a.second == 1){
            return set<pair<int, int>>{{1,2}, {2,1}};
        }else if(a.second == N){
            return set<pair<int, int>>{{1,N-1}, {2,N}};
        } else {
            return set<pair<int, int>>{{1,a.second-1}, {2,a.second}, {1, a.second+1}};
        }
    } else if(a.first == N){
        if(a.second == 1){
            return set<pair<int, int>>{{N-1,1}, {N,2}};
        }else if(a.second == N){
            return set<pair<int, int>>{{N,N-1}, {N-1,N}};
        } else {
            return set<pair<int, int>>{{N,a.second-1}, {N-1,a.second}, {N, a.second+1}};
        }
    }else {
        return set<pair<int, int>>{{a.first,a.second-1}, {a.first,a.second+1}, {a.first-1, a.second}, {a.first+1, a.second}};
    }
    return {0,0};
}
int main(){
    cin >> N >> M;
    int x,y,a,b;
    map<pair<int,int>, set<pair<int,int>>> MAP;
    for(int i=0; i<M; i++){
        cin >> x >> y >> a >> b;
        auto index = MAP.find({a,b});
        if(index == MAP.end()){
            MAP.insert({{a,b}, set<pair<int, int>>{{x, y}}});
        } else {
            (index->second).insert({x,y});
        }
    }

    queue<pair<int, int>> qq;
    set<pair<int, int>> visited;
    set<pair<int, int>> possible;
    int vis = 0;
    qq.push({1,1});
    vis+=1;

    while(!qq.empty()){
        pair<int,int> ex = qq.front();
        qq.pop();
        visited.insert(ex);
        auto index = MAP.find(ex);

        for (auto itr = index->second.begin(); itr != index->second.end(); itr++) {
             possible.insert(*itr);
        }
        set<pair<int, int>> neigbors = get_neigbors(ex);
        cout << "what\n";
        for(auto neigbor : neigbors){        
            cout << "x " << neigbor.first << " y " << neigbor.second <<endl;
            if (possible.find(neigbor) != possible.end()){
                if(visited.find(neigbor) == visited.end()){
                    qq.push(neigbor);
                    vis+=1;
                }
            }
        }
    }
    cout << vis << endl;
    return 0;
}