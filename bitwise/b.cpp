/*
https://codeforces.com/problemset/problem/1421/A

In order to celebrate Twice's 5th anniversary, Tzuyu and Sana decided to play a game.

Tzuyu gave Sana two integers a
 and b
 and a really important quest.

In order to complete the quest, Sana has to output the smallest possible value of (a⊕x) + (b⊕x) for any given x
where ⊕denotes the bitwise XOR operation.

minmize a ^ x + b ^ x

doing it bit by bit

3 cases 

1. a = 0, b = 0

a ^ x + b ^ x = 0

choose x = 0

2. a = 1, b = 1

choose x = 1


3. a = 1, b = 0 or a = 0, b = 1

you can choose x = 0 or x = 1 regardless you will get 1

so minimize sum is equal to sum of k bits where a != b and that is a ^ b

one number able to help is set x = a & b 

a ^ x + b ^ x = a ^ (a & b) + b ^ (a & b)

then we can use the property of xor that is a ^ a = 0 and a ^ 0 = a

so a ^ (a & b) + b ^ (a & b) = (a ^ a & b) + (b ^ a & b) = 0 ^ b = b

*/


#include <bits/stdc++.h>


using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){

        long long a, b;


        cin >> a >> b;

        cout << (a ^ b) << endl;



    }

    return 0;



}