/*

https://codeforces.com/problemset/problem/1669/H

given array of size n

we can do the following operation any number of times

get the maximum and of all the elements after at most k operations 

we can replace one element with ai or 2 ^ j where j is between 0 and 30

we start from the bit 30 and go down to 0 to check how many operations we need to

make the current bit 1 in the answer then we decrease the number of operations

then we calculate the final answer

*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){

        int n, k;

        cin >> n >> k;

        vector<int> a(n);

        int cnt[31] = {0};


        for(auto &x : a) cin >> x;

        int operations = k;

        for(auto x : a){

            for(int i = 0; i < 31; i++){

                if(x & (1 << i)) cnt[i]++;

            }

        }

        int ans = 0;

        int remain = k;

        for(int j = 30; j >= 0; j--){

            if(n - cnt[j] <= remain){

                remain -= (n - cnt[j]);

                ans |= (1 << j);

            }
        }

        cout << ans << endl;

    }

    return 0;

}