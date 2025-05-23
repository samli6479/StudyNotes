/*

 https://www.codechef.com/submit/ANDSUBAR

 1 <= T <= 10^5

 1 <= N <= 10^9

start with basic approach

let us see 

4 - [2,3]

7 - [4,5,6,7]

common is around 2^k 

length can be n- 2^k + 1 or 2^(k-1)


*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){

        int n;

        cin >> n;

        int answer = 0;

        int i;

        for(i = 30; i >= 0; i--){

            if(1LL << i <=n ) break;
        }

        int temp = n - (1 << i) + 1;

        int length = (i > 0 ? 1 << (i-1) : 0);

        answer = max(length, temp);

        cout << answer << endl;
    }


    return 0;
}