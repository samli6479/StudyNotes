/*
Greg has an array a = a1, a2, ..., an and m operations. Each operation looks as: li, ri, di, (1 ≤ li ≤ ri ≤ n). To apply operation i to the array means to increase all array elements with numbers li, li + 1, ..., ri by value di.

Greg wrote down k queries on a piece of paper. Each query has the following form: xi, yi, (1 ≤ xi ≤ yi ≤ m). That means that one should apply operations with numbers xi, xi + 1, ..., yi to the array.

Now Greg is wondering, what the array a will be after all the queries are executed. Help Greg.

Input
The first line contains integers n, m, k (1 ≤ n, m, k ≤ 105). The second line contains n integers: a1, a2, ..., an (0 ≤ ai ≤ 105) — the initial array.

Next m lines contain operations, the operation number i is written as three integers: li, ri, di, (1 ≤ li ≤ ri ≤ n), (0 ≤ di ≤ 105).

Next k lines contain the queries, the query number i is written as two integers: xi, yi, (1 ≤ xi ≤ yi ≤ m).

The numbers in the lines are separated by single spaces.

Output
On a single line print n integers a1, a2, ..., an — the array after executing all the queries. 
Separate the printed numbers by spaces.

1 1 1
1
1 1 1
1 1


 */


#include <bits/stdc++.h>

using namespace std;


int main(){

    int n, m, k;

    cin >> n >> m >> k;

    vector<long long> diff(n + 2);

    vector<long long> prefix(m + 2);

    vector<long long> a(n);

    vector<int> L(m+1), R(m+1), D(m+1);

    for(auto &i :a) cin >> i;

    for(int i = 1; i <= m; i ++){

        cin >> L[i] >> R[i] >> D[i];

    }


    while(k--){

        int x, y;

        cin >> x >> y;

        prefix[x] += 1;

        prefix[y + 1] -= 1;
        
    }


    for(int i = 1; i <= m; i++){

        prefix[i] += prefix[i - 1];

    }

    for(int i = 1; i <= m; i++){

        diff[L[i]] += prefix[i] * D[i];

        diff[R[i] + 1] -= prefix[i] * D[i]; 

    }

    for(int i = 1; i <= n; i++){

        diff[i] += diff[i - 1];

        cout << diff[i] + a[i - 1] << '\n';

    }


    return 0;
}