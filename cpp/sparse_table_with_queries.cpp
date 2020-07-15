#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int n, q,k;
LL series[100005];
LL st_min[100005][25], st_max[100005][25];
int log_table[100005];

void create_sparse_table(){
    k = log2(n);
    for(int i = 0; i < n; ++i){
        st_min[i][0] = series[i];
        st_max[i][0] = series[i];
    }
    
    for(int j = 1; j <= k; ++j){
        for(int i = 0; i + (1 << (j-1)) < n; ++i){
            st_max[i][j] = max(st_max[i][j-1], st_max[i + (1 << (j-1))][j-1]);
            st_min[i][j] = min(st_min[i][j-1], st_min[i + (1 << (j-1))][j-1]);
        }
    }

    for(int i = 2; i <= n; ++i)
        log_table[i] = log_table[i/2] + 1;
}

LL min_query(int l, int r){
    int j = log_table[r-l+1];
    return min(st_min[l][j], st_min[r-(1 << j)+1][j]);
}

LL max_query(int l, int r){
    int j = log_table[r-l+1];
    return max(st_max[l][j], st_max[r-(1 << j)+1][j]);
}

int main(){
    cin >> n;
    for(int i = 0; i <n; ++i)
        cin >> series[i];
    create_sparse_table();

    cin >> q;
    for(int i = 0; i < q; ++i)
        // answer queries

    return 0;
}