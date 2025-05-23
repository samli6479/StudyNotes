/*

https://codeforces.com/problemset/problem/1722/G

given array of distinct integers of size n

xor of all even index elements is the same as xor of all odd index elements

return array of size n

total xor is 0 

so we can put n -3 numbers in the array with regular from 1 to n - 3 

let assume number s = xor of all numbers from 1 to n - 3

then we just need to put two large numbers greater than n-3 who is power of 2

then put the last number as s ^ x1 ^ x2 you will get the whole xor to 0


*/


#include <bits/stdc++.h>

using namespace std;


int main(){

    int t;

    cin >> t;

    while(t--){

        int n; 

        cin >> n;

        vector<long long> a;

        a.reserve(n);

        long long s = 0;

        for(int i = 1; i <= n - 3; i++){

            a.push_back(i);

            s ^= i;

        }

        int x1 = 1LL << 28;

        int x2 = 1LL << 29;

        long long c = s ^ x1 ^ x2;

        a.push_back(x1);

        a.push_back(x2);

        a.push_back(c);

        for(auto x : a){

            cout << x << " ";

        }

        cout << endl;


    }

    return 0;
}