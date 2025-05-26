/*
https://codeforces.com/problemset/problem/1095/C

power of two

given n, k

return if you can represent n as a sum of k powers of two

if yes, print any combination of k powers of two

else print no

1. convert n to binary format

2. check the popcount of n <= k <= n

3. greedy split the larget power of two until performed k - popcount(n) splits

*/ 

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, k;

    cin >> n >> k;

    if( k > n || k < __builtin_popcount(n)){

        cout << "NO" << endl;

        return 0;
    }

    priority_queue<int> pq;

    for(int i = 0; i < 30; i++){

        if(n & (1 << i)){

            pq.push(1 << i);
        }
    }


    while(pq.size() < k){

        int x = pq.top();

        pq.pop();

        pq.push(x / 2);

        pq.push(x / 2);

    }

    cout << "YES" << endl;

    while(!pq.empty()){

        cout << pq.top() << " ";

        pq.pop();

    }

    cout << endl;

    return 0;
}