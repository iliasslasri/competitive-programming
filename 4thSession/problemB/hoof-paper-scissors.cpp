#include <iostream>

using namespace std;

char l[100000];
int k;
int max_win(int, int);
int max_with_k(int, int, int);
int main()
{

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }

    cout << max_win(0, n - 1, k, ' ') << endl;
    return 0;
}

int max_win(int start, int end, int K, char C)
{
    if (K == 0)
    { // on ne peut pas changer
        int wins = 0;
        for (int i = start; i <= end; i++)
        {
            if (a_wins(C, l[i]))
                wins++;
        }
        return wins;
    }
    else if (start == end && K == 0)
    {
        // on ne peut pas gagner que si on peut ganger avec C
        if (a_wins(C, l[start]))
            return 1;
        else
            return 0;
    }
    else if (start == end && K > 0)
    {
        // on peut tjrs gagnger
        return 1;
    }

    int max = 0;
    for (char c : {'H', 'S', 'P'})
    {
        int max_with_c = max_win(start, end, K, c);
        if (max_with_c > max)
        {
            max = max_with_c;
        }
    }
}

bool a_wins(char a, char b)
{
    if (a == 'H' && b == 'S')
    {
        return true;
    }
    else if (a == 'S' && b == 'P')
    {
        return true;
    }
    else if (a == 'P' && b == 'H')
    {
        return true;
    }
    return false;
}