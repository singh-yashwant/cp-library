#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL power(LL b, LL p, LL mod){
    if(p == 0)return 1;
    LL temp = power(b, p/2, mod);
    if(p % 2 == 0)
        return (temp * temp) % mod;
    else
        return (((b * temp) % mod) * temp) % mod;
}
