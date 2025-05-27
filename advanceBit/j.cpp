/*

https://codeforces.com/problemset/problem/1567/B

two integers a and b

new array 

mex of the array equal to a

xor of the array equal to b

find the minimum length of the array

0 <= a, b <= 3 * 10^5 

mex is the smallest non-negative integer that is not in the array 

base array is 0 to a-1 

let xor of all elements of base array be xori

let xori xor b = c

if c == 0, then xor == b, so the length of the array is a

if (c) != a two cases are possible

1. c < a, mex would still be a then we can add c to the array, so the length of the array is a+1

2. c > a, mex would be a, so we can add c to the array, so the length of the array is a+1

if c == a, then it means xori xor b == a, so xori xor a == b

so we need to xor a into with all elements of the array

but we can't add a to the array as it will change the mex to a+1

so we need to add two elements to the array where the xor of the two elements is a

we can add 1 and (1 xor a) to the array 

this will make the length of the array a+2

*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    cin >> t;

    int pref[300005] {0};

    for(int i = 1; i < 300005; i++){

        pref[i] = pref[i-1] ^ i;

    }


    while(t--){

        int a, b;

        cin >> a >> b;
        
        int xori = pref[a-1];

        if(xori == b){

            cout << a << endl;

        }

        else if((xori ^ b) == a){

            cout << a + 2 << endl;
        }

        else{

            cout << a + 1 << endl;

        }

    }

    return 0;
}

