/*

Given an array of n elements

print all possible subsets of the array in any order

convert them into bits location of this is [0,1,2,3,...n-1]

using bitmask we can generate all possible subsets

*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;

    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){

        cin >> arr[i];

    }

    int total = 1 << n; 

    for(int mask = 0; mask < total; mask++){

        for(int j = 0; j < n; j++){

            if(mask & (1 << j)){

                cout << arr[j] << " ";
            }

        }

        cout << endl;
    }

    return 0;
}