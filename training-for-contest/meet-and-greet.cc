#include <iostream>
#include <set>

using namespace std;
set<int> seen;
int main(){
    int N, K, V;
    cin >> N >> K >> V;
    int vis;
    int visited = 0;
    for (int i=0; i<V; i++){
        cin >> vis;
        if(vis <= K){
            if(seen.find(vis) == seen.end()){
                visited ++;
                seen.insert(vis);
            }
        }
    }

    if(visited >= K){
        cout << "YES";
    }else {
        cout << "NO";
    }
return 0;

}