#include <iostream>

using namespace std;
char grid[501][501];
char out[501 * 501];
char directions[4] = {'L', 'D', 'R', 'U'};
int diri[4] = {0, 1, 0, -1}, dirj[4] = {-1, 0, 1, 0};
int C, R;

bool dfs(int, int, int);

int main()
{
    cin >> C >> R;
    int start_i, start_j;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'R')
            {
                start_i = i;
                start_j = j;
            }
        }
    }
    dfs(start_i, start_j, 0);
    cout << out;
    return 0;
}

bool dfs(int i, int j, int prof)
{

    if (i < 0 || j < 0 || i >= R || j >= C)
    {
        return false;
    }
    else if (grid[i][j] != '.' && grid[i][j] != 'R')
    {
        return grid[i][j] == 'D';
    }

    grid[i][j] = 'V';

    // deep
    for (int k = 0; k < 4; k++)
    {
        // for the four directions we test if in the end of the recursion we get to D
        if (dfs(i + diri[k], j + dirj[k], prof + 1))
        {
            out[prof] = directions[k];
            return true;
        }
    }
    return false;
}