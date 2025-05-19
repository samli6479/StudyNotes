/*

https://www.codechef.com/problems/BITEQU

find a,b,c,d such that ((a&b)|c)^d=n

(a & b) | c  ^ d = (a | c) & (b | c)  ^ d

neeeds to convsider case where n is 0 

so we need to make sure that we have different values for a,b,c,d

thus old thought of set a and b to 2^37 and 2^36 would not work 

lets us make a & b have one bit set namely 2 ^ 36 

then we set c to 2 ^ 35 

thus (a & b) | c = 2 ^ 36 + 2 ^ 35 

since n is less than 2 ^ 32 we can set d to 2 ^ 35 + 2 ^ 36 + n  

and all these values are guarenteed to be distinct



*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	
    int t;
    
    cin >> t;
    
    while(t--){
	
    	long long n;
        cin >> n;
        long long a = (1LL << 37) + (1LL << 36);
        long long b = 1LL << 36;
        long long c = 1LL << 35;
        long long d = (1LL << 35) + (1LL << 36) + n;
        cout << a << " " << b << " " << c << " " << d << endl;
    }
    
    return 0;

}