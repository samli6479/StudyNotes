/*

https://www.hackerrank.com/contests/dcc-lab-30-jan/challenges/multiple-powers-of-two/problem

an array of size n given q queries 

for each query qi

add 2 ** qi - 1 to all number Aj 

st Aj is divisible by 2 ** qi 


5 3
1 2 3 4 4
2 
3 
4

1 2 3 7 7 

traverse the array and record if the number is divisible by 2 ** qi 

if it is then add 2 ** qi - 1 to the result

then go to check the next qi with the updated array 
*/

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, q;

    cin >> n >> q;

    vector<int> arr(n);

    for(auto &i: arr) cin >> i;


    int curmaxpower = 32;

    while(q--) {

        int qi;

        cin >> qi;

        if(qi >= curmaxpower) continue;

        curmaxpower = min(curmaxpower, qi);

        for(auto &i: arr) {



            if((i & ((1 << qi) - 1)) == 0) {

                i += (1 << (qi)) - 1 ;

            }

        }


    }

    for(auto &i: arr) cout << i << " ";

    return 0;   
}