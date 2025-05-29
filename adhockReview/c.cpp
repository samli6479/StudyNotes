/*


https://codeforces.com/problemset/problem/1607/B

B. Odd Grasshopper

start with a point x0 

if it is even location then move from xo to x0 - t

if it is odd location then move from x0 to x0 + t

determind the location of the grasshopper after n moves

odd and even is based on the abs value of number

3 cases 

odd + odd = even 

even + even = even  

odd + even = odd 

since we know the if the time is odd or even we can determin if the number is odd or even for this problem

if start is odd, t is odd then the result is even

if start is even, t is odd then the result is odd

we know for sure the moves are always increase by 1

so we can use the formula to find the location of the grasshopper

let us start with x0 = 0, n = 12

x0 = 0 move 1 to the left then x1 = -1 odd

x1 = -1 move 2 to the right then x2 = 1 odd

x2 = 1 move 3 to the right then x3 = 4 even

x3 = 4 move 4 to the left then x4 = 0 even

x4 = 0 move 5 to the left then x5 = -5 odd

x5 = -5 move 6 to the right then x6 = 1 odd

x6 = 1 move 7 to the right then x7 = 8 even

x7 = 8 move 8 to the left then x8 = 0 even

x8 = 0 move 9 to the left then x9 = -9 odd

x9 = -9 move 10 to the right then x10 = 1 odd

x10 = 1 move 11 to the right then x11 = 12 even

x11 = 12 move 12 to the left then x12 = 0 even

x12 = 0 move 13 to the left then x13 = -13 odd

x13 = -13 move 14 to the right then x14 = 1 even

x14 = 1 move 15 to the right then x15 = 16 even

x15 = 16 move 16 to the left then x16 = 0 even

x16 = 0 move 17 to the left then x17 = -17 odd

what is the pattern of the final results compare to the start number? 

so we come back to the start point for every 4 moves

then let us check if we start with x0 = 1, n = 12

x0 = 1 move 1 to the right then x1 = 2 even

x1 = 2 move 2 to the left then x2 = 0 even

x2 = 0 move 3 to the left then x3 = -3 odd

x3 = -3 move 4 to the right then x4 = 1 odd

x4 = 1 move 5 to the right then x5 = 6 even

x5 = 6 move 6 to the left then x6 = 0 even

x6 = 0 move 7 to the left then x7 = -7 odd

x7 = -7 move 8 to the right then x8 = 1 odd

x8 = 1 move 9 to the right then x9 = 10 even

x9 = 10 move 10 to the left then x10 = 0 even

x10 = 0 move 11 to the left then x11 = -11 odd

x11 = -11 move 12 to the right then x12 = 1 even

x12 = 1 move 13 to the right then x13 = 14 even

x13 = 14 move 14 to the left then x14 = 0 even

x14 = 0 move 15 to the left then x15 = -15 odd

x15 = -15 move 16 to the right then x16 = 1 even

x16 = 1 move 17 to the right then x17 = 18 even

what is the pattern of the final results compare to the start number?  

so we come back to the start point for every 4 moves regard less of the start number

so we can use the formula to find the location of the grasshopper 

let r be the remainder of n / 4, start with even/ odd

if r == 0, xn = x0, xn = x0

if r == 1, xn = x0 - n , xn = x0 + n 

if r == 2, xn = x0 + 1, xn = x0 - 1

if r == 3, xn = x0 + (n + 1 ), xn = x0 - (n+1)

*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    long long t;

    cin >> t;

    while(t--){

        long long x0, n;

        cin >> x0 >> n;

        long long r = n % 4;

        bool isOdd = (x0 & 1) != 0;

        if(r == 0){
            cout << x0 << endl;
        }

        else if(r == 1){

            if(isOdd){

                cout << x0 + n << endl;

            }

            else{

                cout << x0 - n << endl;

            }

        }

        else if(r == 2){

            if(isOdd){

                cout << x0 - 1 << endl;

            }

            else{

                cout << x0 + 1 << endl;

            }

        }

        else{

            if(isOdd){

                cout << x0 - (n + 1) << endl;

            }

            else{

                cout << x0 + (n + 1) << endl;

            }

        }

    }


    return 0;
}