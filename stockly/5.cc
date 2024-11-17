#include <string>
#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << ": " << (x) << "\n";

int main(){
    int B, G;
    cin >> B >> G;
    size_t n_ = B+G;
    vector<set<string>> bb{n_, set<string>()};
    string s;
    set<string> all_books;
    int nb;
    for(int i=0; i<B+G; i++){
        cin >> s >> nb;
        for(int j=0; j<nb; j++){
            cin >> s;
            bb[i].insert(s);
        }
    }

    sort(bb.begin(), bb.end(), [](set<string> a, set<string> b){
        return a.size() > b.size();
    });

    for(int i=0; i<B+G; i++){
        for(int j=i+1; j<G+B; j++){
            for(auto it=bb[i].begin(); it!=bb[i].end(); it++){
                if(bb[j].find(*it) != bb[j].end()){
                    bb[j].erase(*it);
                }
            }
        }
    }

    int count = 0;
    for(int i=0; i<B+G; i++){
        if(bb[i].size() > 0){
            count++;
        }
    }
    cout << count << "\n";

    return 0;
}