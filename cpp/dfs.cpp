#include <bits/stdc++.h>
using namespace std;

vector<int> visited; 
map<int, vector<int>> adj_list;             
void dfs(int node){                           // 3 color dfs
    visited[node] = 1;                        // 1=> visiting
    for(auto c: adj_list[node]){              // 2=> done visiting
        if(visited[c] == 0){                  // 0=>not yet visited
            dfs(c);
        }
    }
    visited[node] = 2;
}

