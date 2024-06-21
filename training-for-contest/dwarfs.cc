#include <iostream>

using namespace std;

int main(){
    int V[7];
    for (int i=0; i<7; i++){
        cin >> V[i];
    }

    // boucle 
    int above, under;
    for (int j=0; j<7; j++){
        above = 0;
        under = 0;
        for(int k=0; k<7; k++){
            if(j!=k){
                if(V[j] > V[k]){
                    above+=1;
                } else if(V[j] < V[k]){
                    under +=1;
                }
            }
        }

        if(above <= 3 && under <= 3){
            cout << V[j];
            return 0;
        }
    }

    return 0;
}