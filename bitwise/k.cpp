/*
https://www.codechef.com/submit/XXOORR

1 <= T <= 10^5

1 <= N， K <= 10^5

1 <= A[i] <= 10^9

number of opertions

choose a number p >=0

select at most k numbers from the array

for each number ai, replace it with ai xor 2 ** p

find minimum number of operations to make all the numbers to zero

for each bits level we check how many count, 

since we do operations with k numbers at top 

so we need some all this and use x + k - 1 / k as the ceiling to solve 

*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){

        int n, k;

        cin >> n >> k;

        int a[n];

        for(auto &i : a) cin >> i;

        int answer = 0;

        array<long long, 31> cnt{};

        for(int x: a){

            for(int i = 0; i < 31; i++){

                if(x & (1ll << i)) cnt[i]++;       
                
            }
        }


        long long ans = 0;

        for(int i = 0; i < 31; i++){

            ans += (cnt[i] + k - 1) / k;

        }

        cout << ans << endl;

    }

    return 0;
}