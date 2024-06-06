#include <iostream>

using namespace std;

#include <map>

map<int, string> my_map = {
    { 0, "Monday" },
    { 1, "Tuesday" },
    { 2, "Wednesday" },
    { 3, "Thursday" },
    { 4, "Friday" },
    { 5, "Saturday" },
    { 6, "Sunday" }
};

int main(){
    long long d;
    cin >> d;
    if(d==0){
        cout <<  my_map[3];
    }
    else if(d==1){
        cout <<  my_map[4];
    }
    else if(d==2){
        cout <<  my_map[5];
    } else if (d==3){
        cout <<  my_map[6];
    } else if (d==4){
        cout <<  my_map[0];
    }else if (d==5){
        cout <<  my_map[1];
    }else if (d==6){
        cout <<  my_map[2];
    }else if (d==7){
        cout <<  my_map[3];
    } else {
        cout << my_map[(d+3)%7];
    }
    cout << endl;
    return 0;
}