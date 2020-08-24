#include <bits/stdc++.h>
using namespace std;

#define RANGE(i, n) for (int i = 0; i < n; ++i)
int READ_INT(){int temp;cin>>temp;return temp;}      // read an int

const int N = 200005;

int n;                 // no of nodes
map<int, vector<int>>adj_list;
int visited[N], height[N], ancestors[N][20];  // 2D table to represent ancestors, ancestors[i][j] = 2**jth ancestor of node i

void dfs(int node, int h){
    visited[node] = true;
    height[node] = h;
    for(auto v: adj_list[node]){
        if(!visited[v]){
            ancestors[v][0] = node;
            dfs(v, h+1);
        }
    }
}

// go d steps up from a node using binary lifting
int lift(int node, int d){
    int u = node;
    while(height[node] - height[u] != d){
        int j = 20;
        while((1 << j) > height[u] || height[node] - height[ancestors[u][j]]> d)
            j--;
        u = ancestors[u][j];
    }
    return u;
}

// go up from node u to node v (v is ancestor of u)
void walk(int u, int v){
    while(u != v){
        int j = 20;
        while((1 << j) > height[u] || height[ancestors[u][j]] < height[v])
            j--;
        u = ancestors[u][j];
    }
}

// lca of node u and v
int lca(int u, int v){
    if(height[u] < height[v])
        swap(u, v);
    u = lift(u, height[u] - height[v]);
    if(u == v)return u;
    while(ancestors[u][0] != ancestors[v][0]){
        int j = 20;
        while((1 << j) > height[u] || ancestors[u][j] == ancestors[v][j])j--;
        u = ancestors[u][j];
        v = ancestors[v][j];
    }
    return ancestors[u][0];
}

int main(){
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t = READ_INT();   // number of test cases

    RANGE(x,t){

        /* read the graph and initialze the containers
        cin >> n;
        memset(visited, 0, sizeof(visited));
        memset(height, 0, sizeof(height));
        memset(ancestors, -1, sizeof(ancestors));
        adj_list.clear();
        for(int u = 1; u <= n; ++u){
            int m = READ_INT();
            RANGE(i,m){
                int v= READ_INT();
                adj_list[u].push_back(v);
                adj_list[v].push_back(u);
            }
        }
        */

        // root the tree (here rooted at 1)
        dfs(1, 0);

        // fill the ancestor table
        for(int j = 1; j < 20; ++j){
            int ht = (1 << j);
            // nodes from 1 to n, for 0 based node indexing change appropiately
            for(int i = 1; i <= n; ++i){
                if(height[i] >= ht) ancestors[i][j] = ancestors[ancestors[i][j-1]][j-1];
            }
        }

        /* answer the LCA queries
        int q = READ_INT();
        cout << "Case " << x+1 << ":" << endl;
        while(q--){
            int u, v;
            cin >> u >> v;
            cout << lca(u, v) << endl;
        }
        */
    }
    return 0;
}
