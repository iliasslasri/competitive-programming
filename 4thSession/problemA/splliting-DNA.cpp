#include <iostream>
#include <map>

#define INF 500000000000000000

int N;
long long L[501];

using namespace std;


int e(int i, int j, map<pair<int, int>, int>& memo){
    int sum = 0;
    for (int k = i; k < j+1; k++){
        sum += L[k];
    }
    if ( i == j){
        return 0;
    } else if (i == j-1){
        return L[i]+L[j];
    } 
    if (memo.find({i, j}) != memo.end()) {
        return memo[{i, j}];
    }

    long long min_energy = INF;
    // Splitting from i to j at k, E(i, j) = E(i, k) + E(k+1, j) + sum(i, j)
    for (int k = i; k < j; k++) {
        int energy = e(i, k, memo) + e(k + 1, j, memo) + sum;
        if ( min_energy > energy){
            min_energy = energy;
        }
    }

    memo[{i, j}] = min_energy;
    return min_energy;
}


int main()
{
    map<pair<int, int>, int> memo;
    cin >> N;
    for (int i = 0; i < N; i++)
    {

        cin >> L[i];
    }

    cout << e(0, N-1, memo);
}



