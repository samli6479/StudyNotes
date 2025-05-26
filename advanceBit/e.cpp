/*
https://atcoder.jp/contests/abc356/tasks/abc356_d

Given integers N and M, compute the k=0 to N sum of popcount(k&M), modulo 998244353.
  
find the bits set with M

using a frequency array to store

traverse from 0 to n to check the common bits between k and m 

update the sum with common counts divide with 998244353

let us do a smaple count

assume jth bit of m is set

j = 0 

for n = 0, popcount = 0 & 1 = 0

for n = 1, popcount = 1 & 1 = 1

for n = 2, popcount = 10 & 01 = 0

for n = 3, popcount = 11 & 01 = 1

for n =4 , popcount = 100 & 01 = 0

so for j = 0 you have 0 ,1 ,0 ,1, 0  pattern

j = 1 

n = 0, popcount = 00 & 10 = 0

n = 1, popcount = 01 & 10 = 0

n = 2, popcount = 10 & 10 = 1

n = 3, popcount = 11 & 10 = 1

n = 4, popcount = 100 & 10 = 0 

so for j = 1 you have 0, 0, 1, 1, 0 pattern

so in summary it follow 2 ** (j + 1) pattern fot the period of popcount

so total = (n + 1) / （2 ** (j + 1) ) * （2 ** j）+ max(0, (n + 1) % (2 ** (j + 1)) - 2 ** j)

first term is the full period count 

second term is the remaining count in the last period

first half of cycle is 0 and second half is 1

*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    long long n, m;

    cin >> n >> m;

    long long mod = 998244353;

    long long ans = 0;

    long long t = n + 1;

    for(int j = 0; j < 60; j++){

        if((m >> j) & 1){

            /*
            ll temp = n;
            temp >>= (j + 1);
            temp *= (1LL << j);

            did we passed the jth bit one 
            if (n & (1LL << j)) {
                temp += ((n % (1LL << j)) + 1);
            }
            ans += temp;
            
            
            */

            long long half   = 1LL << j;
            long long period = half << 1;

            long long full   = t / period;
            long long rem    = t % period;

            long long cnt_full = (full % mod) * (half % mod) % mod;
            long long cnt_rem  = max(0LL, rem - half) % mod;
            long long cnt      = (cnt_full + cnt_rem) % mod;

            ans = (ans + cnt) % mod;

        }

    }

    cout << ans % mod << endl;

    return 0;
}