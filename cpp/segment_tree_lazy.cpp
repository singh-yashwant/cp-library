#include <bits/stdc++.h>
using namespace std;

#define RANGE(i, n) for (int i = 0; i < n; ++i)
using LL = long long;

int n, q;
vector<LL> arr, seg_tree, lazy;

// modify this function according the type of segment tree used eg, sum/min/max/xor
LL operation(LL x, LL y){
    return x+y;
    // return x^y;
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

void push(int v, LL val, int tl, int tr){
    if(tl != tr){
        lazy[2*v+1] += val;
        lazy[2*v+2] += val;
    }
    lazy[v] = 0;
}

void range_update(int v, int tl, int tr, int l, int r, LL val){
    if(lazy[v]){
        seg_tree[v] += (tr - tl + 1)*lazy[v];
        push(v, lazy[v], tl, tr);
    }
    // current segment is completely outside the query range
    if(l > tr || r < tl)
        return;
    
    // current segment is completely inside the query range    
    if(tl >= l && tr <= r){
        seg_tree[v] += val * (tr - tl + 1);
        push(v, val, tl, tr);
    }
    // current segment is partially inside the query range
    else{
        int tm = (tl + tr)/2;
        range_update(2*v+1, tl, tm, l, r, val);
        range_update(2*v+2, tm+1, tr, l, r, val);
        seg_tree[v] = operation(seg_tree[2*v+1], seg_tree[2*v+2]);
    }
}

LL get(int v, int tl, int tr, int ind){
    if(lazy[v]){
        seg_tree[v] += (tr - tl + 1)*lazy[v];
        push(v, lazy[v], tl, tr);
    }
    if(tl == tr)
        return seg_tree[v];
    int tm = (tl + tr)/2;
    if(ind <= tm)
        return get(2*v+1, tl, tm, ind);
    else 
        return get(2*v+2, tm+1, tr, ind);
}

LL range_query(int v, int tl, int tr, int l, int r){
    // current segment is completely outside the query range
    if(l > tr || r < tl)
        return 0;
    if(lazy[v]){
        seg_tree[v] += (tr - tl + 1)*lazy[v];
        push(v, lazy[v], tl, tr);
    }
    // current segment is completely inside the query range    
    if(tl >= l && tr <= r)
        return seg_tree[v];
    else{
        int tm = (tl + tr)/2;
        return operation(range_query(2*v+1, tl, tm, l, r), range_query(2*v+2, tm+1, tr, l, r));
    }
}

void solve(){
    cin >> n >> q;
    seg_tree.assign(4*n, 0);
    lazy.assign(4*n, 0);
    arr.assign(n, 0);
    build(0, 0, n-1);

    // check the input output format and answer queries accordingly
    RANGE(j,q){
        string s;
        cin >> s;
        int l, r;
        cin >> l >> r;
        if(s == "answer")
            cout << range_query(0, 0, n-1, l-1, r-1) << endl;
        else{
            cout << "OK\n";
            range_update(0, 0, n-1, l-1, r-1, 1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t = 1;
    for(int i = 1; i <= t; ++i){
        cout << "Scenario #" << i << ":" << endl;
        solve();
    }

    return 0;
}



/* complie flags
-Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
*/