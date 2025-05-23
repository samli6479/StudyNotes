/*
https://codeforces.com/problemset/problem/1362/B


In the first line there is a single integer n (1≤n≤1024) denoting the number of elements in set S. 
Second line consists of n distinct integers si (0≤si<1024), elements of S.


we use the fact a[i] ^ k also belongs to S to derive that k must also be less than 1024

then using freq array we can find the answer


*/


#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){

        int n;

        cin >> n;

        int a[n];
        
        int freq[1024] = {};


        for(int i = 0; i < n; i++){

            cin >> a[i];

            freq[a[i]]++;

        } 

        int answer = -1;

        for(int k = 1; k < 1024; k++){

            bool flag = true;

            for(int i = 0; i < n; i++){

                if(!freq[a[i] ^ k]){

                    flag = false;

                    break;

                }

            }

            if(flag){

                answer = k;

                break;

            }

        }

        cout << answer << endl;
        
    }


    return 0;
}
