/*

https://www.codechef.com/problems/ANDORUNI

given array of size n integers

from the array create a new array of size n(n-1) / 2 elements 

where each elements is make by bitwise and of two elements of the array

for each opertion

1. take away the maximum and minimum elements of the new array

2. get bitwise or the new element and add it to the array

stop until you only have one element in the array

return the last remaining element

0 <= ai <= 10^9

2 <= n <= 10^5

cannot do the brutal force way it will tle

ai & aj only exist if we know that ai and aj are both 1

bitwise or of the maximum and minimum element will get us bits on both of them

0011 or 1100 = 1111

so need to think about the relation between the maximum and minimum element so we can do something

let us go with some example

0, 1, 2, 3, 4

0000, 0001, 0010, 0011, 0100

freq array

1 - 1, 2 - 2, 3 - 1

there for we only get 2 bit have 1 all other bits are 0

so the result will be 0010

so we what we can do is traverse the array of all elements in the array get freq array

if the freq of the bit is greater than 1 then we can say that the bit will be 1 in the result

4 6 7 2

0100 0110 0111 0010

freq array 

1 - 1, 2 - 3, 3 - 3

so the result will be 0110  - 6
 

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

        for(auto &i : a) cin >> i;

        int freq[32] = {0};

        int ans = 0;

        for(int i = 0; i < 30; i++){

            for(auto j : a){
                if((j >> i) & 1) freq[i]++;

                if(freq[i] > 1) {
                    
                    ans += (1 << i);

                    break;
                }

            }

        }

        cout << ans << endl;
    
    }

    return 0;
}