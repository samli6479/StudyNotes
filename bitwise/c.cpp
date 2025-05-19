/*
question https://codeforces.com/problemset/problem/1909/B

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤500). The description of the test cases follows.

The first line of each test case contains a single integer n
 (2≤n≤100) — the length of the array a.

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤10 ** 17) — the initial state of the array. It is guaranteed that all the ai are distinct.

Note that there are no constraints on the sum of n over all test cases.

*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    cin >> t;

    while(t--){

        int n;

        cin >> n;

        long long a[n];

        for(auto &i: a){

            cin >> i;
        }

        long long ans = 2;

        set<long long> remainders;

        int k = 0;

        while(k < 60){

            remainders.clear();

            for(int i = 0; i < n; i++){

                remainders.insert(a[i] % (ans << k));
            }

            if(remainders.size() == 2){

                break;
            }

            k++;
        }

        ans = ans << k;

        cout << ans << endl;


    }

    return 0;
}
