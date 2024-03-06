#include <cstdio>
#include <queue>

using namespace std;

const int NB_NODES_MAX = 1001 ;
const int INF = 1000*1000*1000;
int nbNodes, nbEdges ;
vector<int> nxt[NB_NODES_MAX], cost[NB_NODES_MAX], flow[NB_NODES_MAX] ;
int dist[NB_NODES_MAX] ;

long long dijkstra(int minFlow) {
  fill(dist,dist+NB_NODES_MAX,INF);
  priority_queue<pair<int,int>,
                 vector<pair<int,int> >,
                 greater<pair<int,int> > > p_queue ;
  dist[1] = 0;
  p_queue.push(make_pair(0,1));
  while(!p_queue.empty()) {
    auto [node_dist,node] = p_queue.top();
    p_queue.pop();
    if(dist[node] == node_dist) {
      for(size_t id = 0 ; id < nxt[node].size() ; id++) {
        const int neighbor = nxt[node][id] ;
        const int nouvDist = dist[node] + cost[node][id] ;
        if(flow[node][id] >= minFlow && nouvDist < dist[neighbor] ) {
          dist[neighbor] = nouvDist ;
          p_queue.push(make_pair(nouvDist,neighbor));
        }
      }
    }
  }
  return dist[nbNodes];
}

int main () {
  scanf("%d %d\n",&nbNodes, &nbEdges);
  for(int edge = 0 ; edge < nbEdges ; edge++ ) {
    int a,b, c,f ;
    scanf("%d %d %d %d\n",&a,&b,&c,&f);
    nxt[a].push_back(b);
    nxt[b].push_back(a);
    cost[a].push_back(c);
    cost[b].push_back(c);
    flow[a].push_back(f);
    flow[b].push_back(f);
  }

  long long bestRatio = -1 ;
  for(long long flow = 1 ; flow <= 1000 ; flow++)
    bestRatio = max(bestRatio, 1000000LL*flow / dijkstra(flow) ) ;
  printf("%lld\n",bestRatio);
  return 0;
}
