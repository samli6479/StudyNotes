/*
Given an array of Nelements, answer the following Q queries
●
Query: L, R
●
Result= A[L] ^ A[L + 1] ^ A[L + 2] ^ …. ^ A[R]

xor of all elements in range L to R 

p[l] = a[1] ^ a[2] ^ a[3] ^ a[4] ^ ... a[l]

p[r] = a[1] ^ a[2] ^ a[3] ^ a[4] ^ ... a[r]

and we know that a ^ a = 0 and a ^ 0 = a

p[r] ^ p[l-1] = a[l] ^ a[l+1] ^ a[l+2] ^ ... a[r]


*/

#include <bits/stdc++.h>

using namespace std;

int main(){


    int n, q;

    cin >> n >> q;

    vector<int> a(n+1), p(n+1);

    for(int i = 1; i <= n; i++){

        cin >> a[i];

        p[i] = p[i-1] ^ a[i];

    }

    while(q--){

        int l, r;

        cin >> l >> r;

        cout << (p[r] ^ p[l-1]) << endl;

    }
    

    return 0;

}