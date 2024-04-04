#include <iostream>
#include <vector>

#define INF 1000000
using namespace std;

int N, M; // N pastures, M cows
pair<int,int> pref[INF] {{0,0}};
int counter=0;
void parcours(vector<int>, int);
int main(){

    // Scanning input
    cin >> N >> M;
    char sd;
    int i,j;

    for(int i=0; i<N; i++){
        cin >> sd >> i >> j;
        pref[i] = {sd,j};
        pref[j] = {sd,i};
    }

    counter= counter +2;
    vector<int> L{0};
    parcours(L, 0);

    cout << counter << endl;
    return 0;
}

void parcours(vector<int> L, int i){
    // cas de base
    if(i == N){

    // cas général, si L[i] == 0, on a pas encore touché à L[i], pas de choix effectué {1, 2} représente les choix de seed
    if(L[i] == 0){

        if(pref[i].first == 'S' && pref[i].second > i){

            L[pref[i].second] = 1;
            L[i] = 1;
            parcours(L, i+1);
            counter++;

            L[pref[i].second] = 2;
            L[i] = 2;
            parcours(L,i+1);
        } else if (pref[i].first == 'D' && pref[i].second > i){
            L[pref[i].second] = 2;
            L[i] = 1;
            parcours(L, i+1);
            counter++;

            L[pref[i].second] = 1;
            L[i] = 2;
            parcours(L,i+1);
        }

    } else {
        parcours(L,i+1);
    }
}