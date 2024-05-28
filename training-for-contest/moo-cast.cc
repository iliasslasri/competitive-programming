#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
vector<pair<pair<int,int>, int>> a;

long double dist(int x1, int x2, int y1, int y2);
int main(){

    int N;
    cin >> N ;
    a.resize(N);

    int i, j, d;
    for(int m=0; m< N; m++){
        cin >> i >> j >> d;
        a[m] = {{i, j}, d};
    }
    vector<vector<int>> adj;
    adj.resize(N);
    if (N == 1){
        cout << 1 << endl;
        return 0;
    }
    for ( int m=0; m< N; m++){
        for (int n=m+1; n<N; n++){
            if(dist(a[m].first.first, a[n].first.first, a[m].first.second, a[n].first.second) <= a[m].second){
                adj[m].push_back(n);
            }
            if(dist(a[m].first.first, a[n].first.first, a[m].first.second, a[n].first.second) <= a[n].second){
                adj[n].push_back(m);
            }
        }
    }

    // for (int i =0; i<N; i++){
    //     cout << i;
    //     for( auto x : adj[i]){
    //         cout << ' ' << x ; 
    //     }
    //     cout << endl;
    // }

    // iterate over all the cows and let the cast start
    int count =0, result = 0;
    for(int i=0; i<N; i++){
        if ( adj[i].size() == 0){
            continue;
        }

        queue<int> q;
        q.push(i);

        vector<bool> visited(N);
        visited[i] = true;

        count = 0;
        while(!q.empty()){
            int current = q.front();
            q.pop();
            count++;

            for (int nb : adj[current]){
                if (!visited[nb]){
                    q.push(nb);
                    visited[nb] = true;
                }
            }
        }

        if(count > result){
            result = count;
        }
    }
    cout << result << endl;
    return 0;
}

long double dist(int x1, int x2, int y1, int y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}


