/*
https://codeforces.com/problemset/problem/1202/A

x, y has trailing zeros

We want the smallest non-negative k such that reversing the binary of
    s_k = x + (y << k)
is lexicographically minimal.

Equivalently, in the unreversed sum s_k we need the earliest possible 0-bit
in its binary (so that when reversed it becomes the first character).

Let:
  p = position of y’s least-significant ‘1’ (0-based from the right)
    = v2(y), the number of trailing zeros in y
Shifting y by k moves that ‘1’ to position p + k.

We then scan x from its least significant bit upwards, to find the first
‘1’ in x at some position q ≥ (p + k).  To force a 0 at bit q in the sum,
we need to align y’s one there: p + k = q ⇒ k = q − p.

Thus the minimal k is:
  1) compute p = trailing-zero count of y
  2) compute shift_y = p
  3) find in x the first ‘1’ at or above that LSB-distance:
       let q index = (x.size()-1) − shift_y
       while q >= 0 and x[q]=='0', q--
     if q < 0, no such ‘1’ ⇒ answer k = 0
     else k = ((x.size()-1) − q) − shift_y

*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    cin >> t;

    while(t--){
        
        string x, y;
        cin >> x >> y;

        // 1) find p = index of rightmost '1' in y
        int p = y.size() - 1;
        while (p >= 0 && y[p] == '0') --p;

        // distance of that '1' from the LSB
        int shift_in_y = y.size() - 1 - p;

        // 2) find q = index in x of the first '1' at or to the left of that position
        int q = x.size() - 1 - shift_in_y;
        while (q >= 0 && x[q] == '0') --q;

        // 3) k is how much we shifted y’s 1-bit past x’s 1-bit
        int k = (x.size() - 1 - q) - shift_in_y;
        // (should never be negative if inputs are valid, but just in case:)
        k = max(0, k);

        cout << k << endl;

    }

    return 0;
}