#include <iostream>
#include <math.h>

using namespace std;

int main(){
    long long S = 0;
    int N, L;
    cin >> N;
    long long s = 0;
    for(int i =0; i < N; i++){

        cin >> L;
        s = 0;
        if(L == 0){break;}

        long long x[L], y[L];

        for (int j=0; j<L; j++){
            cin >> x[j] >> y[j];
        }

        for (int k = 0; k<L-1; k++){
            s += (x[k] - x[k+1]) * (y[k] + y[k+1]);
        }

        s += (x[L-1] - x[0]) * (y[L-1] + y[0]);
        S += abs(s);
    }

    cout << S/2 << endl;
}