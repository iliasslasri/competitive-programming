#include <iostream>
#include <numeric>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const long long INF = 1e18; // Corrected to long long

const int MAXNODES = 500 * 500;
typedef pair<long long, int> plli;
vector<plli> graph[MAXNODES];
long long dist1D[MAXNODES]; // Renamed to avoid conflict with 2D array

int dist[1001][1001];  // 2D array for distances
bool seen[1001][1001]; // 2D array for seen nodes

void dijkstra(int start_node)
{
    fill(dist1D, dist1D + MAXNODES, INF); // Using dist1D
    priority_queue<plli, vector<plli>, greater<plli>> p_queue;
    p_queue.push(make_pair(0, start_node));
    dist1D[start_node] = 0; // Using dist1D
    while (!p_queue.empty())
    {
        int node = p_queue.top().second;
        long long node_dist = p_queue.top().first;
        p_queue.pop();
        if (dist1D[node] == node_dist) // Using dist1D
        {
            for (auto &edge : graph[node])
            {
                int next_node = edge.first;
                long long weight = edge.second;
                if (node_dist + weight < dist1D[next_node]) // Using dist1D
                {
                    dist1D[next_node] = node_dist + weight;                // Using dist1D
                    p_queue.push(make_pair(dist1D[next_node], next_node)); // Using dist1D
                }
            }
        }
    }
}

const int OFFSET = 500;

vector<pair<int, int>> get_neighbors(pair<int, int> pos)
{
    vector<pair<int, int>> res;
    if(pos.first + 1 <=1001)
        res.push_back({pos.first + 1, pos.second});
    if(pos.second + 1 <=1001)
        res.push_back({pos.first, pos.second + 1});
    if(pos.second - 1 >= 1001)
    res.push_back({pos.first - 1, pos.second});
    res.push_back({pos.first, pos.second - 1});
    return res;
}

int main()
{
    int x, y, n;
    cin >> x >> y >> n;
    pair<int, int> end = {x, y};
    pair<int, int> start = {OFFSET, OFFSET};

    vector<pair<int, int>> nodes; // Corrected from vector<plli>

    // Initialize dist and seen
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            dist[i][j] = 1e6;   // 1e6 to denote unvisited nodes
            seen[i][j] = false; // Initialize seen to false
        }
    }

    dist[OFFSET][OFFSET] = 0; // Starting point
    int xt, yt;
    for (int i = 1; i <= n; i++)
    {
        // Create the nodes
        cin >> xt >> yt;
        nodes.push_back(make_pair(xt, yt));
        xt += OFFSET;
        yt += OFFSET;
        dist[xt][yt] = -1;   // Marking as obstacle
        seen[xt][yt] = true; // Marking as seen
    }

    // BFS
    vector<pair<int, int>> todo = {start};
    seen[start.first][start.second] = true;

    size_t id = 0; // Initialize id to 0
    bool stop = false;
    while ((id < todo.size()) && (!stop))
    {
        pair<int, int> cur = todo[id];
        vector<pair<int, int>> children = get_neighbors(cur);
        for (auto v : children)
        {
            if (v == end)
            {
                stop = true;
                seen[v.first][v.second] = true;
                dist[v.first][v.second] = dist[cur.first][cur.second] + 1;
                break;
            }
            if (!seen[v.first][v.second] && dist[v.first][v.second] != -1)
            {
                cout << "here" + v.first + v.second << endl;
                seen[v.first][v.second] = true;
                dist[v.first][v.second] = dist[cur.first][cur.second] + 1;
                todo.push_back(v);
            }
        }
        id++; // Increment id
    }

    cout << dist[end.first + OFFSET][end.second + OFFSET];
}