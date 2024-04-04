#include <iostream>
#include <map>

using namespace std;

char l[100001];
int k;
char choices[3] = {'H', 'S', 'P'};
map<pair<pair<int, int>, pair<char, int>>, int> myset;

int max_wins(int, int, char, int);
int main()
{

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    int max = 0;
    int maxi;
    for(char c:choices){
            maxi = max_wins(0, n - 1, c, k);
            if (max < maxi)
                max = maxi;
        }
    cout << max << endl;
    return 0;
}

int max_wins(int i, int j, char c, int k)
{
    // cas de base k = 0
    if (k == 0)
    { // on ne peut pas changer
        int wins = 0;
        for (int n = i; n <= j; n++){
            if (a_wins(c, l[n]))
                wins++;
        }
        return wins;
    }
    else if (i == j && k == 0)
    {
        // on ne peut pas gagner que si on peut ganger avec C
        if (a_wins(c, l[i]))
            return 1;
        else
            return 0;
    }
    else if (i == j && k > 0)
    {
        // on peut tjrs gagnger
        return 1;
    }
    // if i,j,c,k is in myset return myset[i,j,c,k]
    if (myset.find({{i, j}, {c, k}}) != myset.end()){
        return myset[{{i, j}, {c, k}}];
    }

    // recursive
    int max = 0;
    int maxi;
    // if we already have the value in the set
    if (myset.find({{i, j}, {c, k}}) != myset.end()){
        return myset[{{i, j}, {c, k}}];
    }

    for (char ch:choices){
            for (int m = i; m < j; m++){

                if (myset.find({{i, m}, {c,0}}) != myset.end() && myset.find({{m + 1, j}, {ch, k - 1}}) != myset.end()){

                    maxi = myset[{{i, m}, {c,0}}] + myset[{{m + 1, j}, {ch, k - 1}}];

                } else if (myset.find({{i, m}, {c,0}}) != myset.end()){

                    maxi = myset[{{i, m}, {c,0}}] + max_wins(m + 1, j, ch, k - 1);

                } else if (myset.find({{m + 1, j}, {ch, k - 1}}) != myset.end()){

                    maxi = max_wins(i, m, c, 0) + myset[{{m + 1, j}, {ch, k - 1}}];

                } else {

                    maxi = max_wins(i, m, c, 0) + max_wins(m + 1, j, ch, k - 1);

                }
                if (maxi > max)
                    max = maxi;
            }
        }

    return max;
}

bool a_wins(char a, char b)
{
    if (a == 'H' && b == 'S')
        return true;
    else if (a == 'S' && b == 'P')
        return true;
    else if (a == 'P' && b == 'H')
        return true;
    return false;
}