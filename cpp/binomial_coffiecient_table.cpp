#include <bits/stdc++.h>
using namespace std;

long long nCr[1005][1005];
const long long MOD = 1e9+7;

// nCr = (n-1)C(r) + (n-1)C(r-1)
// nC0 = 1, nCn = 1
void fill_ncr_table(){
    memset(nCr, 0, sizeof(nCr));
    for(int i = 0; i < 1005; ++i){
        for(int j = 0; j <= i; ++j){
            if(i == j || j == 0)nCr[i][j] = 1;
            else nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1])%MOD;
        }
    }
}

int main(){
    fill_ncr_table();
    return 0;
}
