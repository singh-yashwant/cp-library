#include <bits/stdc++.h>
using namespace std;


// time constraints
// upto 1e6 very fast
// upto 2e7 in 1.5 seconds

int primes_upto = 20000000;
vector<bool>is_prime(primes_upto+1, true);
is_prime[1] = is_prime[0] = false;
for(int i = 2; i < sqrt(primes_upto)+1; ++i){
    if(is_prime[i]){
        int j = i * i;
        while(j <= primes_upto){
            is_prime[j] = false;
            j += i;
        }
    }
}

// list of all primes upto the upper limit set {2, 3, 5, 7, 11, 13, ...}
vector<int>primes;
for(int i = 2; i <= primes_upto; ++i)
    if(is_prime[i])primes.push_back(i);
