/*

https://codeforces.com/problemset/problem/1547/D


growing sequence

ai, ai+1, ai+2, ...

for jth bits in ai, and ai+1, if ai[j] = 1 then ai+1[j] = 1, applyting to all i


cogrow sequence

xi, yi and zi = xi xor yi  and zi is growing sequence then we call x and y cogrow sequence

given x find the lexicographically smallest sequence y such that x and y are cogrow sequence

we can just find the bits in xi and since it is xor, we know for sure that yi

xor 

0, 0 is 0 

0, 1 is 1 and 1, 0 is 1 

1, 1 is 0

we want the lexicographically smallest sequence y, so we want to make sure the 0 bits are at the start

*/

#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;

    cin >> t;

    while(t--){

        int n;

        cin >> n;

        int x[n], y[n];

        for(int i = 0; i < n; i++){
            cin >> x[i];
        }

        int mask = 0;

        for(int i = 0; i < n; i++){

            y[i] = mask & (~x[i]);

            int z = x[i] ^ y[i];

            mask |= z;

        }

        for(int i = 0; i < n; i++){
            cout << y[i] << " ";
        }

        cout << endl;
        
    }
    return 0;

}
