/*
https://codeforces.com/problemset/problem/1514/B

*/


#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    cin >> t;

    const int MOD = 1e9 + 7;

    while(t--){

        long long n, k;

        cin >> n >> k;

        /*
        we got n numbers and k is the max 2 ** k - 1 

        in order to find the max number and also make sure the and operations result is 0 

        we need to have one 0 and the rest 1 for all bits

        length is at n

        total choice of bits is k and you have n numbers so total number is n ** k
    
        */

        long long result = 1;
        n %= MOD;
        while (k > 0) {
            if (k & 1) 
                result = (result * n) % MOD;
            n = (n * n) % MOD;
            k >>= 1;
        }
    
        cout << result << endl;

    }

    return 0;
}