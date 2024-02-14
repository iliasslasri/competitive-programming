#include <string>
#include <iostream>
#include <string.h> 

using namespace std;
int main(){
    char str[1000];
    int p, q;
    int S = 0;
    int total;
    scanf("%[^\n]s", str);

    while(strcmp(str, "TOTAL")){
        scanf("%d %d \n", &p, &q);
        S += p*q;
        scanf("%[^\n]s", str);
    }

    scanf("%d", &total);
    if(total > S){
        printf("%s", "PROTEST");
    }else {
        printf("%s", "PAY");
    }
}