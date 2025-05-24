/*

https://codeforces.com/problemset/problem/1630/A

given a set of n elements containing 0 to n-1 exactly once

another number k is given 

each element in the set is in exactly one pair

sum of all the pairs ai & aj = k

if we can form this we return the all the pairs

if we cannot form this we return -1 

bitwise and 4 cases

1. 0 & 0 = 0

2. 0 & 1 = 0

3. 1 & 0 = 0

4. 1 & 1 = 1

since n is a power of 2

so n -1 would be all 1s in binary

and n-1 - i for all i would be the bitwise not of i so i & (n-1-i) = 0 for all i 

1. if k == 0 use the above property 

2. if k == n - 1 there are 2 cases

    we need to break the result into 2 parts

    1 part is to form with n - 1

    we can form the pairs with n-1 and n-2 get n - 2 from the bitwise and calculation

    we can form the pairs with 1 and 3 get 1 from the bitwise and calculation

    then with 0 and n-4 get 0 and 2 with n -3 to get 0 

    sum all the pairs we get n - 1

    2 part is to form with 0 using i and n-1-i

    this only works if n is greater than 4

3. if k is in between 0 and n-1

    k & (n-1) = k 

    and 0 with n - 1 - k to get 0

    rest all pairs are formed using i and n-1-i 


*/

#include <bits/stdc++.h>

using namespace std;

void printPair(int a, int b, vector<bool> &used){

    cout << a << " " << b << endl;

    used[a] = true;

    used[b] = true;

}


int main(){

    int t;

    cin >> t;

    while(t--){

        long long n, k;

        cin >> n >> k;

        if(k == n-1){

            if(n == 4){

                cout << -1 << endl;

                continue;

            }

            vector<bool> vis(n, false);

            printPair(n-1, n-2, vis);

            printPair(1, 3, vis);

            printPair(0, n-4, vis);

            printPair(2, n-3, vis);

            for(int i = 0; i < n; i++){

                int j = n - 1 - i;

                if(i < j && !vis[i] && !vis[j]){

                    printPair(i, j, vis);

                }
            }
        }

        else if (k == 0){

            for(int i = 0; i < n/2; i++){

                cout << i << " " << n-1-i << endl;

            }

        }

        else{

            vector<bool> vis(n, false);

            printPair(k, n-1, vis);

            printPair(0, n-1-k, vis);

            for(int i = 0; i < n; i++){

                int j = n-1-i;

                if(i < j && !vis[i] && !vis[j]){

                    printPair(i, j, vis);

                }
                
            }

        }

    }

    return 0;
    
}

