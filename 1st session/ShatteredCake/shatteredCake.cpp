#include <iostream>

using namespace std;
int main(){
    int w, n;
    if(scanf("%d\n", &w) != 1){printf("Bad input\n");};
    if (scanf("%d\n", &n) != 1){printf("Bad input\n");};
    int Surface = 0;
    int wi, li;
    while(n){
        if(scanf("%d %d\n", &wi, &li) == 2){
            Surface += wi * li;
            n-=1;
        };
    }
    printf("%d", Surface / w);
    return 0;
}