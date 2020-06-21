#include <bits/stdc++.h>
using namespace std;

int tme = 1;                                      // time counter for tin and tout
vector<int> visited, t_in, t_out;                          // entrance and exit time of nodes
map<int, vector<int>>adj_list;                             // graph repsenetd as adjl list
void dfs_detailed(int node){                      // 3 color notation for nodes
    visited[node] = 1;                            // 1=> currently visiting
    t_in[node] = tme++;                           // 2=> done visiting
    for(auto c: adj_list[node]){                  // 3=> not visited yet
        if(visited[c] == 0){
            dfs_detailed(c);
        }
    }
    visited[node] = 2;    
    t_out[node] = tme++;
}