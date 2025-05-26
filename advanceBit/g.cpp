/*
https://www.codechef.com/problems/ORTUPLES

given three numbers p, q, r 

find the number of tuples (a, b, c) such that 

a | b = p

b | c = q

a | c = r

bitwise or 

1. 0 and 1 or 1 and 0 or 1 and 1 both are 1 

2. 0 and 0 is 0 

find the bitmask of p, q, r

if a has 1 in jth bit then p has 1 in jth bit and p has 1 in jth bit

so the same for b and c

find all common bits in both p and q, r and q, p and r

use this to determine the set of 1s in a, b, c

the rest of the bits have to be 0s

return the number of such tuples

*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){

        int p, q, r;

        cin >> p >> q >> r;

        long long ans = 1;

        for(int i = 0; i < 30; i++){

            int cnt = 0;

            if (p &(1 << i)) cnt++;

            if (q &(1 << i)) cnt++;

            if (r &(1 << i)) cnt++;

            if (cnt == 1){

                ans = 0;

                break;

            }

            if(cnt == 3) ans *= 4;

        }

        cout << ans << endl;
        
    }

    return 0;
}

