#include <string>
#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << ": " << (x) << "\n";

int main(){
    int N;
    double p ;
    cin >> N >> p;
    vector<pair<int, double>> a(N);
    for(int i =0; i<N; i++){
        cin >> a[i].first >> a[i].second;
    }
    int i = 0;
    int min = 1e5;
    while(i < N){
        if(a[i].second >= p && a[i].first < min){
            min = a[i].first;
        }
        i++;
    }
    cout << min << "\n";
    return 0;
}