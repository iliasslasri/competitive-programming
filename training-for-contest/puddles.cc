#include <iostream>
#include <set>

using namespace std;
int NB_NODES_MAX = 1050 * 1050 + 1050;
int INF = 400*NB_NODES_MAX; 

set<int> next_up;
set<int> nxt(int node){
    int x = node % (501*2);
    int y = node - x*(501*2);
    next_up = {};
    if(x==0){
        if(y==0){
            next_up.insert(1);
            next_up.insert(1002); // x*1002 + y
        } else if ( y == 1002){
            next_up.insert(1001);
            next_up.insert(1002*1+1002);
        } else {
            next_up.insert(0*1002+y+1);
            next_up.insert(1*1002+y);
            next_up.insert({0*1002+y-1});
        }
    }else if(x == 1002){
        if(y==0){
            next_up.insert(1001*x + 0);
            next_up.insert(1002*x + 1);
        } else if ( y == 1002){
            next_up.insert((x-1)*1002+y);
            next_up.insert((x)*1002+y-1);
        } else {
            next_up.insert((x)*1002+y+1);
            next_up.insert((x)*1002+y-1);  
            next_up.insert((x-1)*1002+y);  
        }
    } else {
        next_up.insert((x)*1002+y+1);
        next_up.insert((x)*1002+y-1);  
        next_up.insert((x-1)*1002+y);  
        next_up.insert((x+1)*1002+y);  
    }
    return next_up;
}
int main(){
    int x, y, n;
    cin >> x >> y >> n;
    x = x + 501;
    y = y + 501;
    set<int> puddles;
    int k,l;
    for (int i=0; i<n; i++){
        cin >> k >> l;
        puddles.insert(k*1002 + l);
    }

    cout << dist[x*1002+y];
    return 0;

}