#include<bits/stdc++.h>
using namespace std;

int n, k, q;        // n = lenght of array, q = no. of queries, k = max power of 2 less than equal to n
vector<long long>arr;
vector<vector<long long>>st;
vector<int>log_table;

void create_sparse_table(){

    k = log2(n);
    st.assign(n, vector<long long>(k+1, 0));

    // preprocessing segements of length 1
    for(int i = 0; i < n; ++i)
        st[i][0] = arr[i];

    // preprocessing reamining segments
    for(int j = 1; j <= k; ++j){
        for(int i = 0; i + (1 << j) <= n; ++i){
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);      // min query
            // st[i][j] = max(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);   // max query
        }
    }

    log_table.assign(n+1, 0);
    for(int i = 2; i <= n; ++i)
        log_table[i] = log_table[i/2] + 1;
}

long long query(int l, int r){
    int j = log_table[r-l+1];
    return min(st[l][j], st[r - (1 << j) + 1][j]);   // for min query
    // return max(st[l][j], st[r - (1 << j) + 1][j]);   // for max query
}

int main(){

    cin >> n;
    arr.assign(n, 0);
    for(int i = 0; i < n; ++i)cin >> arr[i];
    
    create_sparse_table();

    // queries
    // loop over and perform each query one by one

    return 0;
}
