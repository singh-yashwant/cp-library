#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using VL = vector <long long>;

const int N = 300005;
VL factorial_num(N);
void calc_factorial(LL mod){
    factorial_num[0] = 1;
    for(int i = 1; i < N; ++i)
        factorial_num[i] = (factorial_num[i-1] * i) % mod;
}

VL num_inv(N);
void calc_inv(LL mod){
    num_inv[0] = num_inv[1] = 1;
    for(int i = 2; i < N; ++i)
        num_inv[i] = num_inv[mod % i] * (mod - mod / i) % mod;
}

VL  factorial_num_inv(N);
void calc_inv_of_factorial(LL mod){
    factorial_num_inv[0] = factorial_num_inv[1] = 1;
    for(int i = 2; i < N; ++i)
        factorial_num_inv[i] = factorial_num_inv[i-1] * num_inv[i] % mod;
}

LL ncr(LL n, LL r, LL mod){
    return ((factorial_num[n] * factorial_num_inv[r]) % mod) * factorial_num_inv[n-r] % mod;
}
int main(){

    const LL MOD = 1e9 + 7;
    calc_factorial(MOD);
    calc_inv(MOD);
    calc_inv_of_factorial(MOD);

    // cout << ncr(n, r, MOD);

    return 0;
}



/* complie flags
-Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
*/