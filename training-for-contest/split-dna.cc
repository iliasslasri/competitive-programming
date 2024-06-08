#include <iostream>

using namespace std;

int N;
long long split(long long *L, int start, int end);
int main(){


    cin >> N;
    long long L[N];
    for (int i=0; i<N; i++){
        cin >> L[i];
    }

    long long E = split(L, 0, N);
    cout << E;
    return 0;
}

long long split(long long *L, int start, int end){
    long long E = N*10e14;
    long long  ss = 0;
    if(end - start == 1){
        return 0;
    } else if(end - start == 2){
        return L[start] + L[end-1];
    }
    for(int i=start; i<end; i++){
        ss+= L[i];
    }
    long long e=0;
    for(int i=start; i<end-1; i++){
        int s1 = split(L, start, i+1);
        int s2 = split(L, i+1, end);
        e =  ss + s1 + s2;
        if(e < E){E=e;}
    }

    return E;
}