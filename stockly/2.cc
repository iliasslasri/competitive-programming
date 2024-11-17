#include <string>
#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout  << "\n"<< #x << ": " << (x) << "\n";

int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    if(N == 1){
        cout << v[0] << "\n";
        return 0;
    }
    if(N==2){
        cout << v[0]  << " " << v[1]  << "\n";
        return 0;
    }
    sort(v.begin(), v.end());
    int n = 0;
    for(int i = 0; i < N; i++){
        n = 1;
        cout << v[i];
        while(i < N-1 && v[i] == v[i+1]-1){
            n++; i++;
        }

        if(n>2){
            cout << "-" << v[i];
        } else if(n == 2){
            cout << " " << v[i];
        }
        cout << " ";

    }
    cout << "\n";
    return 0;
}