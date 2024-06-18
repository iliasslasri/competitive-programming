#include <iostream>

using namespace std;

int main(){

    int N;
    int jon[3];
    int master[3];
    cin >> N;
    cin >> jon[0]>> jon[1]>> jon[2];
    cin >> master[0]>> master[1]>> master[2];
    int n=0;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            for(int k=1; k<=N; k++){
                if((abs(jon[0] - i)  <= 2) && (abs(jon[1] - j) <= 2) && (abs(jon[2] - k)  <= 2) ){
                    n++;
                    // cout << '('<< i<<','<<j<<','<<k<<')' << endl;

                } else if((abs(master[0] - i) <= 2) && (abs(master[1] - j)  <= 2) && (abs(master[2] - k)  <= 2) ){
                    n++;
                    // cout << '('<< i<<','<<j<<','<<k<<')' << endl;
                } else {
                    // edge cases
                    if(((abs(jon[0] - i)==N-1) || (abs(jon[0] - i)==N-2)) && ((abs(jon[1] - j) ==N-1) || (abs(jon[1] - j) ==N-2)) && ((abs(jon[2] - k)  == N-1 )|| (abs(jon[2] - k)  == N-2))){
                        n++;
                    } else if(((abs(master[0] - i)==N-1) ||( abs(master[0] - i)==N-2)) && ((abs(master[1] - j) ==N-1) || (abs(master[1] - j) ==N-2)) && ((abs(master[2] - k)  == N-1) || (abs(master[2] - k)  == N-2))){
                        n++;
                    } // 0
                    else if(((abs(jon[0] - i)==N-1) || (abs(jon[0] - i)==N-2)) && (abs(jon[1] - j) <= 2) && (abs(jon[2] - k)  <= 2) ){n++;}
                    // 0,1
                    else if(((abs(jon[0] - i)==N-1) || (abs(jon[0] - i)==N-2)) && ((abs(jon[1] - j) ==N-1) || (abs(jon[1] - j) ==N-2)) &&(abs(jon[2] - k)  <= 2) ){n++;}
                    // 2
                    else if( (abs(jon[0] - i)  <= 2) && (abs(jon[1] - j) <= 2) && ((abs(jon[2] - k)  == N-1 )|| (abs(jon[2] - k)  == N-2))){n++;}
                    // 0,2
                    else if( (abs(jon[0] - i)  <= 2) && ((abs(jon[1] - j) ==N-1) || (abs(jon[1] - j) ==N-2)) && ((abs(jon[2] - k)  == N-1 )|| (abs(jon[2] - k)  == N-2))){n++;}
                    // 1,2
                    else if(((abs(jon[1] - i)==N-1) || (abs(jon[1] - i)==N-2)) && ((abs(jon[2] - j) ==N-1) || (abs(jon[2] - j) ==N-2)) &&(abs(jon[0] - k)  <= 2) ){n++;}
                    // 1
                    else if( (abs(jon[0] - i)  <= 2) && (abs(jon[2] - j) <= 2) && ((abs(jon[1] - k)  == N-1 )|| (abs(jon[1] - k)  == N-2))){n++;}
                    //

                    else if(((abs(master[0] - i)==N-1) || (abs(master[0] - i)==N-2)) && (abs(master[1] - j) <= 2) && (abs(master[2] - k)  <= 2) ){n++;}
                    // 0,1
                    else if(((abs(master[0] - i)==N-1) || (abs(master[0] - i)==N-2)) && ((abs(master[1] - j) ==N-1) || (abs(master[1] - j) ==N-2)) &&(abs(master[2] - k)  <= 2) ){n++;}
                    // 2
                    else if( (abs(master[0] - i)  <= 2) && (abs(master[1] - j) <= 2) && ((abs(master[2] - k)  == N-1 )|| (abs(master[2] - k)  == N-2))){n++;}
                    // 0,2
                    else if( (abs(master[0] - i)  <= 2) && ((abs(master[1] - j) ==N-1) || (abs(master[1] - j) ==N-2)) && ((abs(master[2] - k)  == N-1 )|| (abs(master[2] - k)  == N-2))){n++;}
                    // 1,2
                    else if(((abs(master[1] - i)==N-1) || (abs(master[1] - i)==N-2)) && ((abs(master[2] - j) ==N-1) || (abs(master[2] - j) ==N-2)) &&(abs(master[0] - k)  <= 2) ){n++;}
                    // 1
                    else if( (abs(master[0] - i)  <= 2) && (abs(master[2] - j) <= 2) && ((abs(master[1] - k)  == N-1 )|| (abs(master[1] - k)  == N-2))){n++;}
                }
            
            }
        }
    }


    cout << n <<endl;
    return 0;
}