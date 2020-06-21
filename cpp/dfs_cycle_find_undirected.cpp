#include <bits/stdc++.h>
using namespace std;

vector<int> visited, parent;
vector<vector<int>>cycles; 
map<int, vector<int>> adj_list;
bool cycle = false;             
void dfs(int node){                           // 3 color dfs
    visited[node] = 1;                        // 1=> visiting
    for(auto child: adj_list[node]){              // 2=> done visiting
        if(visited[child] == 0){                  // 0=>not yet visited
            parent[child] = node;
            dfs(child);
        }
        else if(visited[child] && child != parent[node]){
            cycle = true;
            vector<int> cycle = {child};
            while(node != child){
                cycle.push_back(node);
                node = parent[node];
            }
            cycles.push_back(cycle);
        }
    }
    visited[node] = 2;
}

