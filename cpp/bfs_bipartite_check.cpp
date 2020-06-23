#include <bits/stdc++.h>
using namespace std;

bool bfs(int node){
    visited[node] = 1;
    color[node] = 0;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: adj_list[u]){
            if(!visited[v]){
                visited[v] = 1;
                color[v] = !color[u];
                q.push(v);
            }
        }
        for(auto v: adj_list[u]){
            if(color[u] == color[v])
              return false;
        }
    }
    return true;
}

// call bfs for all the univiseted vertices 1 by 1, and if all of them return true, the graph is bipartite
