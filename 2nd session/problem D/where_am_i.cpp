#include <iostream>
#include <stdio.h>
#include <string.h>
// #include <time.h>

using namespace std;
int main(){
        // Record the start time
    // clock_t start = clock();
    int N;
    cin >> N;
    char str[N+1];
    cin >> str;
    int K = 1;
    bool var = true;
    while(K<N){
        char comp1[K+1];
        char comp2[K+1];
        for(auto i = 0; i != N-K; ++i){
            if(!var){
                break;
            }else if(i == N-K-1){
                cout << K << "\n";
                return 0;
    return 0;
            }
            else{
                strncpy(comp1, &str[i], K);
                comp1[K] = '\0';
                for(auto j = 0; j != N-K+1; ++j){
                    if(i!=j){
                        strncpy(comp2, &str[j], K);
                        comp2[K] = '\0';
                        if(!strcmp(comp1, comp2)){
                            var = false;
                            break;
                        }
                    }
                }
            }
        }
        K++;
        var = true;
    }
    cout << K << "\n";
    
    //     // Record the end time
    // clock_t end = clock();

    // // Calculate the running time in seconds
    // double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // // Print the running time
    // cout << "Running time: "<<  cpu_time_used << " seconds\n";
    return 0;
}
