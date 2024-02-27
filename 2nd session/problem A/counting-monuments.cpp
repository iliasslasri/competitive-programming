#include <iostream>
#include <set>
#include <string>
#include <string.h>

using namespace std;
int main()
{
    set<string> monuments;
    string monument;
    // if (std::cin.eof()){cout<<"0";}
    // cin >> monument;
    while(getline(cin, monument)){
        // cout << monument << "\n";
        // cin >> monument;
        // monuments.insert(monument);
        // if (cin.eof())break;
        // cin >> monument;
        // cout << monument << "\n";
        
        // split
        string::size_type pos;
        pos = monument.find(' ',0);
        monument = monument.substr(pos+1);
        monuments.insert(monument);   
    }
    cout << monuments.size() << "\n";
    return 0;
}