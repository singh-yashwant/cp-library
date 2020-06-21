#include <bits/stdc++.h>
using namespace std;

vector<int> visited, dist; 
map<int, vector<int>> adj_list;

void bfs(int node){
    visited[node] = 1;
    dist[node] = 0;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: adj_list[u]){
            if(!visited[v]){
                visited[v] = 1;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}