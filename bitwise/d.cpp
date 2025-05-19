/*
https://codeforces.com/problemset/problem/579/A

target is to find the minimum number of operations to grow from 0 to n

two operations are allowed:
1. grow the number by 2 (double)
2. add 1 to the number

to minimize the number of operations:

- we want to grow the number by 2 as much as possible
- but doubling alone can't create new '1's in binary, only move them
- so every '1' in the binary of n must come from an "add 1" operation

- in other words, the answer is just the count of 1s in the binary representation of n

*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;

    cin >> n;

    int count = 0;

    while(n > 0){

        if(n & 1){

            count++;

        }

        n >>= 1;

    }

    cout << count << endl;

    return 0;
}