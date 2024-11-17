#include <string>
#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << ": " << (x) << "\n";

int main(){
    int N;
    cin >> N;
    vector<string> pass;
    vector<double> prob;
    string str;
    double p;
    for (int i=0; i<N; i++){
        cin >> str >> p;
        pass.push_back(str);
        prob.push_back(p);
    }

    vector<pair<string, double>> v;
    for (int i=0; i<N; i++){
        v.push_back(make_pair(pass[i], prob[i]));
    }
    
    sort(v.begin(), v.end(), [](const pair<string, double> &a, const pair<string, double> &b){
        return a.second > b.second;
    });

    double expected = 0;
    for (int i=0; i<N; i++){
        expected += (i+1) * v[i].second;
    }
    cout << fixed << setprecision(4) << expected << "\n";

    return 0;
}