#include <string>
#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout  << "\n"<< #x << ": " << (x) << "\n";

int main(){
    array<int, 6> h;
    for (int i = 0; i < 6; i++){
        cin >> h[i];
    }
    int w1;
    int w2;
    cin >> w1 >> w2;
    sort(h.begin(), h.end(), greater<int>());

    int h1 = 0;
    int h2 = 0;
    array<int, 3> tower1;
    array<int, 3> tower2;
    int  a = 0, b = 0;
    
    for(int i=0; i<6; i++){
        if(h1 < w1 && h1 + h[i] <= w1 && a < 3){
            tower1[a] = h[i];
            h1 += h[i];
            a++;
        } else if(h2 < w2 && h2 + h[i] <= w2 && b < 3){
            tower2[b] = h[i];
            h2 += h[i];
            b++;
        }
    }

    for(int i=0; i<3; i++){
        cout << tower1[i] << " ";
    }
    for(int i=0; i<3; i++){
        cout << tower2[i] << " ";
    }
    cout << "\n";

    return 0;
}