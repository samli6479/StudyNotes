/*
https://codeforces.com/problemset/problem/1634/B

n ,x , y 

get either alice or bob 

at the end


cases

parity of x - means is x even or odd

on last bit of x  

1. even x or odd x

2 operations add or xor of ai

1. even ai

a. even x add even ai is even

b. odd x xor even ai is 1 on the last bit

2. odd ai

a. even x add odd ai is odd 

b. odd x xor odd ai is even 

so we just need to track how many odds so we know how many times a flip happens


*/


#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        long long n, x, y;

        cin >> n >> x >> y;

        vector<int> a(n);

        for(auto &i : a) cin >> i;

        int odd = 0;

        for(auto &i : a){

            if(i &1) odd++;

        }

        int flip = odd & 1;

        int finalA = (x ^ flip) & 1;

        if(finalA == (y & 1)) cout << "Alice" << endl;

        else cout << "Bob" << endl;


    }

    return 0;

}