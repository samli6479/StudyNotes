/*
Given an array with all 0s initially perform the following Q queries on it.
In the ith query you will be given 3 integers: Li, Ri, Xi. 
You need to add Xi, to all the values in the array from index Li to Ri.
After performing all the queries print the final state of the array.

8, 2

1， 4， 3

2，5， 6


 */



# include <bits/stdc++.h>
using namespace std;

int main(){

    int n, m;

    cin >> n >> m;

    vector<long long> diff(n + 2);

    while(m--){

        int l, r, d;

        cin >> l >> r >> d;

        diff[l] += d;

        diff[r + 1] -= d;
        
    }



    for(int i = 1; i <= n; i++){

        diff[i] += diff[i - 1];

        cout << diff[i] << '\n';


    }

    return 0;
}