#include <string>
#include <map>
#include <iostream>
#include <string.h>

using namespace std;
int main(){
    string animal;
    int N = 0;
    map<string, int> myset;
    if(!scanf("%d\n", &N)){return 1;};
    while(getline(cin, animal)){
        if(myset.find(animal) != myset.end()){
            myset[animal] = myset[animal] + 1;
        }else{
            myset[animal] = 1;
        }
    }

    string animal_max = "NONE";
    int maxCount = 0;
    for(auto it = myset.cbegin(); it != myset.cend(); ++it){
        if( it->second > N - it->second && it->second > maxCount){
            animal_max = it->first;
            maxCount = it->second;
        }
    }
    cout << animal_max << "\n";
    return 0;
}