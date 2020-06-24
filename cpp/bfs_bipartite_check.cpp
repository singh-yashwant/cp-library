#include <bits/stdc++.h>
using namespace std;

MIVI adj_list;
VI visited, color;
bool bipartite = true;

void is_bipartite(int node){
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
            if(color[u] == color[v]){
              bipartite = false;
              return;
            }
        }
    }
}



// call bfs for all the univiseted vertices one by one, and if all of them return true, the graph is bipartite

int main(){

    // --- read the graph --- //

    visited.assign(n+1, 0);
    color.assign(n+1, -1);
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            is_bipartite(i);
            if(!bipartite){
                cout << "NOT BIPARTITE\n";
                return 0;
            }
        }
    }
    cout << "BIPARTITE\n";
    return 0;
}
