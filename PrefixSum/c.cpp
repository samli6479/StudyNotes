/*
  Problem:
    For each query (L, R) on A[1..N], compute
      1*A[L] + 2*A[L+1] + … + (R−L+1)*A[R]
    in O(1) per query after O(N) preprocessing.

  1) Write down the target sum:
     S = ∑_{k=L..R} (k - L + 1) * A[k]

  2) Notice the multiplier (k - L + 1) can be rewritten:
     k - L + 1 = k - (L - 1)

  3) Substitute back into S:
     S = ∑_{k=L..R} [k * A[k]  −  (L−1) * A[k]]

     = ∑_{k=L..R} k*A[k]   −   (L−1) * ∑_{k=L..R} A[k]

     // This is the algebraic shift!

  4) Define two prefix arrays (1-indexed):
     P1[i] = ∑_{k=1..i} A[k]
     P2[i] = ∑_{k=1..i} k * A[k]

  5) Then for any (L,R):
     weightedSum = P2[R] − P2[L-1]    // ∑ k*A[k] over k=L..R
     simpleSum   = P1[R] − P1[L-1]    // ∑ A[k] over k=L..R
     answer      = weightedSum  −  (L−1) * simpleSum

  Build P1,P2 in O(N); answer each query in O(1).
*/


#include <bits/stdc++.h>

using namespace std;




int main(){

    int n, q;

    cin >> n >> q;

    vector<int> a(n);

    for(auto &i: a){

        cin >> i;

    }

    vector<long long> prefixOne(n+1);

    vector<long long> prefixTwo(n+1);


    for(int i = 1; i <= n; i++){

        prefixOne[i] = prefixOne[i-1] + (long long)i * a[i-1];

        prefixTwo[i] = prefixTwo[i-1] + a[i-1];

    }


    while(q--){

        int l, r;

        cin >> l >> r;

        cout << (prefixOne[r] - prefixOne[l-1]) - (l -1)*(prefixTwo[r] - prefixTwo[l-1]) << '\n';


    }

    return 0;
}
