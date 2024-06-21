#include <iostream>
#include <map>

using namespace std;

int N;
map<pair<int, int>, long long > myset; 
long long split(long long *L, int start, int end);
int main(){


    cin >> N;
    long long L[N];
    for (int i=0; i<N; i++){
        cin >> L[i];
    }

    long long E = split(L, 0, N-1);
    cout << E << endl;
    return 0;
}

long long split(long long *L, int start, int end){
    long long E = N*10e14;
    long long  ss = 0;
    if(end - start == 0){
        return 0;
    } else if(end - start == 1){
        return L[start] + L[end];
    }
    
    auto index = myset.find({start, end});
    if( index != myset.end()){
        return index->second;
    }

    for(int i=start; i<=end; i++){
        ss+= L[i];
    }



    for(int i=start; i<end; i++){
        long long s1 = 0;
        long long s2 = 0;

        auto index = myset.find({start, i});
        if( index != myset.end()){
            s1 = index->second;
        }else {
            s1 = split(L, start, i);
            myset.insert({{start, i}, s1});
        }

        auto index2 = myset.find({i+1, end});
        if( index2 != myset.end()){
            s2 = index2->second;
        }else {
            s2 = split(L, i+1, end);
            myset.insert({{i+1, end}, s2});
        }
        E = min(ss + s1 + s2, E);
    }
    myset.insert({{start, end}, E});

    return E;
}