#include <bits/stdc++.h>
using namespace std;

map<int, vector<pair<int, int>>>adj_list;
vector<int> visited, dist, parent;
int n;

// adj_list is represented as a map from int(node) to vector of pairs,
// where each pair is {edge_length, next_node}

void dijkstra(int node){
    dist.assign(n+1, INF);
    dist[node] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>>q;
    q.push({0, node});

    while(!q.empty()){
        pair<int, int>p = q.top();
        q.pop();
        int u = p.second, d = p.first;

        // no point visiting below node
        if(d > dist[u])continue;

        for(pair<int, int>pr: adj_list[u]){
            int v = pr.second;
            int next_d = d + pr.first;
            if(next_d < dist[v]){
                dist[v] = next_d;
                q.push({next_d, v});
            }
        }
    }
}
