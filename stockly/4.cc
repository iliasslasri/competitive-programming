#include <string>
#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << ": " << (x) << "\n";

int main(){
    int N;
    vector<int> v;
    while(1){
        cin >> N;
        if(N==0) break;
        v.push_back(N);
    }
    int tests = 0;
    int n1 = 0;
    int n2 = 0;
    for(int i=0; i<v.size(); i++){
        tests = 0;
        while(n1!=0){
            n1 = n1/2;
            tests++;
        }
        while(n2!=0){
            n2 = n2/4;
            tests++;
        }
        cout << tests << endl;
    }
    return 0;
}