/*
https://codeforces.com/problemset/problem/1726/B

sequence a ai, ai+1, ai+2, ... 

sequence a is interesting if for all i, xor of a0 to ai-1 is 0 

find any sequence of a of length n such that sum of a is m and a is interesting

put no is we cannot make the sequence interesting 

put yes and any sequence satisfies the condition

let's say we have a sequence a0, a1, a2, ... an-1

such that values a0, a2, a3 ,.. ak < an 

so xor of a0, a1, a2 ,.. ak is 0

xor logic x xor y = 0 iff x = y so need to check if for all unique numbers from a0 to ak we have even number of occurences 

cases of m and n

1. m < n it is not possible to make the sequence interesting

2. m >= n 

    a. if n is odd we can have n- 1 1s and the last one is m - (n-1)

    b. if n is even

       1. let r = m - (n-2) if r is even we can have n-2 1s and the last two are r/2, r/2

       2. if r is odd then it is not possible to make the sequence interesting


*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){

        int n, m;

        cin >> n >> m;

        if(m < n){
            cout << "No" << endl;
        }

        else{

            int r = m - (n-2);

            // Case A: n odd → (n−1) ones + one big leftover


            if((n & 1) == 1){
            
                cout << "Yes" << endl;

                for(int i = 1; i < n; i++){

                    cout << 1 << " ";

                }

                cout << m - (n-1) << endl;

            }

            // Case B: n even

            else{

                // Case B1: r is even → (n−2) ones + two leftovers

                if((r & 1) == 0){

                    cout << "Yes" << endl;

                    for(int i = 1; i <= n-2; i++){
                        
                        cout << 1 << " ";

                    }

                    cout << r/2 << " " << r/2 << endl;

                }

                // Case B2: r is odd → not possible

                else{

                    cout << "No" << endl;

                }
            }
            

        }

    }

    return 0;
    
}