#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VL = vector <long long>;

LL power(LL b, LL p, LL mod){
    if(p == 0)return 1;
    LL temp = power(b, p/2, mod);
    LL r = 0;
    if(p % 2 == 0)
        r = (temp * temp) % mod;
    else
        r = (((b * temp) % mod) * temp) % mod;
    return r;
}

LL ncr(LL n, LL r, LL m){
    LL num = 1, den = 1;
    for(int i = 1; i <= r; ++i){
        den = (den * i) % m;
        num = (num * (n - r + i)) % m;
    }
    den = power(den, m-2, m);
    return num*den%m;
}

int main(){
    // cout << ncr(n, r, mod) << endl;
    return 0;
}