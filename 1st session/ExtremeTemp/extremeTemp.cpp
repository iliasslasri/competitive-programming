#include <stdio.h>
#include <string.h>
#include <stdlib.h>     /* atoi */

int main(){
    char str[30];
    int min = 50;
    int max = -50;
    int num;
    while(scanf("%s", str) != EOF){
        num = atoi(str);
        if( num < min && num >= -50 && num <= 50){
            min = num;
            
        }
        if (num > max && num <= 50 && num >= -50){
            max = num;
        }
    }
    printf("%d %d", min, max);
    return 0;
}