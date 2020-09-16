#include <bits/stdc++.h>
using namespace std;

#define RANGE(i, n) for (int i = 0; i < n; ++i)
using LL = long long;

int n, q;
vector<LL> arr, seg_tree;

// modify this function according the type of segment tree used eg, sum/min/max/xor
LL operation(LL x, LL y){
    // return x+y;
    return x^y;
    // return min(x, y);
    // return max(x, y);
}

void build(int v, int tl, int tr){
    if(tl == tr)
        seg_tree[v] = arr[tl];
    else{
        int tm = (tl + tr)/2;
        build(2*v+1, tl, tm);
        build(2*v+2, tm+1, tr);
        seg_tree[v] = operation(seg_tree[2*v+1], seg_tree[2*v+2]);
    }
}

void update(int v, int tl, int tr, int ind, LL val){
    if(tl == tr)
        seg_tree[v] = val;
    else{
        int tm = (tl + tr)/2;
        if(ind <= tm)update(2*v+1, tl, tm, ind, val);
        else update(2*v+2, tm+1, tr, ind, val);
        seg_tree[v] = operation(seg_tree[2*v+1], seg_tree[2*v+2]);
    }
}

LL query(int v, int tl, int tr, int l, int r){
    // modify following line and operation function according to the type of query
    if(l > tr || r < tl)
        return 0;       // 0 for Sum/XOR,  INF for Min,   -INF for Max 
    if(tl >= l && tr <= r)return seg_tree[v];
    else{
        int tm = (tl + tr)/2;
        return operation(query(2*v+1, tl, tm, l, r), query(2*v+2, tm+1, tr, l, r));
    }
}

void solve(){
    cin >> n >> q;
    arr.assign(n, 0);
    seg_tree.assign(4*n, 0);
    RANGE(j,n)cin >> arr[j];
    build(0, 0, n-1);
    RANGE(j,q){
        int t;
        cin >> t;
        if(t == 1){
            // perform the update
            
        }
        else{
            // answer the query
            int l, r;
            cin >> l >> r;
            cout << query(0, 0, n-1, l-1, r-1) << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t = 1;
    for(int i = 0; i < t; ++i){
        solve();
    }

    return 0;
}



/* complie flags
-Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
*/