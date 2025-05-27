/*
https://codeforces.com/problemset/problem/1362/C

given a number n

define the unfairness of two numbers as the difference in position of two numbers

the total unfairness is the sum of unfairness of all numbers from 0 to n

we need to find the minimum total unfairness

i=1 ∑ n HammingDistance(i-1, i)

when you start from 0 to n

you always flip the last bit which is 2 ** 0 

then you flip the second last bit on every second increment which is 2 ** 1

then you flip the third last bit on every fourth increment which is 2 ** 2

bit b flips when i is a multiple of 2 ** b

so we can calculate the number of flips of bit b by dividing n with 2 ** b

sum all from 0 to log2(n)



*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){

        long long n;

        cin >> n;

        long long ans = 0;

        while(n > 0){

            ans += n;

            n /= 2;

        }

        cout << ans << endl;

    }   

    return 0;
}