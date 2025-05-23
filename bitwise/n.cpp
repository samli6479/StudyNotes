/*

https://codeforces.com/problemset/problem/1742/G

Let's define the prefix OR array b
 as the array bi=a1 OR a2 OR … OR ai, where OR represents the bitwise OR operation. 
 In other words, the array b is formed by computing the OR of every prefix of a.

You are asked to rearrange the elements of the array a in such a way that its prefix OR array is lexicographically maximum.

An array x is lexicographically greater than an array y if in the first position where x and y differ, xi>yi.

or - all elements in both will be there

so we need to get the max numbers of all elements and put it in the first place

then we check the other elements to see if we can get the greater of a or b then the rest

if we are able to get all bits maksed then the rest of number can be in any order 



*/

#include <bits/stdc++.h>

using namespace std;

int main(){


    int t;

    cin >> t;

    while(t--){

        int n;

        cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++){

            cin >> a[i];

        }

        vector<int> res;

        res.reserve(n);

        vector<int> used(n, 0);

        int cur = 0;

        for(int i = 0; i < 31; i++){

            int best = cur;
            
            int bestIndex = -1;

            for(int j = 0; j < n; j++){

                if(used[j]) continue;

                int curOr = cur | a[j];

                if(curOr > best){

                    best = curOr;

                    bestIndex = j;

                }

            }

            if(bestIndex == -1) break;

            used[bestIndex] = 1;

            res.push_back(a[bestIndex]);

            cur = best;

        }

        for(int i = 0; i < n; i++){
            
            if(!used[i]){

                res.push_back(a[i]);

            }

        }

        for(int i = 0; i < n; i++){

            cout << res[i] << " ";

        }

        cout << endl;
    }

    return 0;


}