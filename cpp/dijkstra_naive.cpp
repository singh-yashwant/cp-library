#include <bits/stdc++.h>
using namespace std;

map<int, vector<pair<int, int>>>adj_list;
vector<int> visited, dist, parent;
int n;

// adj_list is represented as a map from int(node) to vector of pairs,
// where each pair is {next_node, edge_length}

void dijkstra(int node){
    visited.assign(n+1, false);
    dist.assign(n+1, INF);
    dist[node] = 0;

    for(int i = 1; i <= n; ++i){
        int v = -1;
        for(int j = 1; j <= n; ++j){
            if(!visited[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        }
        if(dist[v] == INF)
            break;
        visited[v] = true;

        for(auto u: adj_list[v]){
            if(dist[v] + u.second < dist[u.first]){
                dist[u.first] = dist[v] + u.second;
                parent[u.first] = v;
            }
        }
    }
}
