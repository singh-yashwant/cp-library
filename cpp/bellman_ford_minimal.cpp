// single source shortest path
// It's a naive approach, will fail on graphs having negative cycles
// reverese the condions and apply the same algorithm for max cost cycles, in that case positive cylces will be banned
// complexity is O(nm), however Dijkstra runs in O(n + m.log(m)) but can't be applied in graphs with negative weights
// therefore this algorithm

#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const LL INF = 1e18 + 5;

vector<LL> dist;
vector<tuple<LL, LL, LL>>edges;                   // store edges in {u, v, weight} format

void bellman_ford(LL node){                       // node is the source node
    dist.assign(n+1, INF);
    dist[node] = 0;
    for(int i = 1; i <= n-1; ++i){
        for(auto edge: edges){
            LL u, v, w;
            tie(u, v, w) = edge;
            dist[v] = min(dist[v], w + dist[u]);
        }
    }
}

int main(){

  //----------- fill edges vector -------------//

  LL source = 1;
  bellman_ford(source);

  return 0;
}
