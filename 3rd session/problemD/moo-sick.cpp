
#include <iostream>
#include <algorithm>
#include <vector>

#define INF 20001

using namespace std;

int main()
{
    int N, C; // N number of notes played, legth of the sequence
    cin >> N;
    int notes[N];
    for (int i = 0; i < N; i++)
    {
        cin >> notes[i];
    }

    cin >> C;
    int seq[C];
    for (int i = 0; i < C; i++)
    {
        cin >> seq[i];
    }
    sort(seq, seq + C);

    int window[C];

    int res;
    int diff;
    for (int i = 0; i < C; i++)
    {
        window[i] = notes[i];
    }
    int result_N = 0;
    vector<int> result;
    // The idea : sort the sequence and for all windows sort the window ( this sort will not cost much as the initial window is )
    for (int i = 1; i < N - C + 2; i++)
    {
        sort(window, window + C);

        res = 1;
        diff = window[0] - seq[0];
        for (int i = 0; i < C; i++)
        {
            if (diff != window[i] - seq[i])
            {
                res = 0;
                break;
            }
        }

        if (res)
        {
            result.push_back(i);
            result_N++;
        }
        // update window; we can use a queue here, but the window is small so we can just shift the elements
        // pop the first element and push the next one to enter
        for (int j = 0; j < C; j++)
        {
            window[j] = notes[i + j];
        }
    }
    if (result_N == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << result_N << endl;
        for (int i = 0; i < result_N; i++)
        {
            cout << result[i] << endl;
        }
    }
    return 0;
}