/*
https://codeforces.com/problemset/problem/1312/C

given array of size n and number k

another integer array start from 1

bi = 0 from start 

two operations 

1. add k ^ j to ai

2. skip this opertion

can we make bi == ai for all i

*/


#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){

        int n, k;

        cin >> n >> k;

        vector<long long> a(n);

        for(int i = 0; i < n; i++){

            cin >> a[i];
        }

        vector<int> used(64, 0);

        bool possible = true;

        for(int i = 0; i < n && possible; i++){

            long long x = a[i];

            int pos = 0;

            while(x > 0){

                int digit = x % k;

                if(digit > 1){
                
                    possible = false;
                    break;
                }

                used[pos] += digit;

                if(used[pos] > 1){

                    possible = false;
                    break;
                }

                x /= k;
                pos++;

            }


        }

        if(possible){

            cout << "YES" << endl;

        }

        else{

            cout << "NO" << endl;

        }


    }


    return 0;
}