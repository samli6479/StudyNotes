/*
https://codeforces.com/problemset/problem/1601/A

given a array of size n

choose k distinct elements from the array

let x be the and of all the elements chosen

subtract x from all the elements chosen

find all possible values of k such that we can reduce the all elements of the array to 0

Print them in increasing order.

1≤n≤200000

0≤ai≤ 2 ** 30 

think about the bits of the numbers

inorder to clear a bit we need to clear the bit in all the numbers 

so we need to find the number of elements in the array which have the bit set

for bits from 0 to 29 get the freq of the bit in all the numbers

if freq[b] == 0 then the bit is already clear 

else we need to group them into batches of size k

so k should be a factor of all freq[b] then k should be gcd of all freq[b]

if gcd is 0 then all elements from 1 to n works

else we need to find all divisors of gcd and order them from smallest to largest


The divisor i

The complementary divisor g/i.

so we can get it under sqrt(g) complexity 

total complexity is o(30 * n + 30 * log(n) + sqrt(n)) which is o(n)

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

        for(auto &i: a) cin >> i;

        vector<int> freq(30, 0);

        // o(30 * n)

        for(int i = 0; i < 30; i++){

            for(auto &j: a){

                if(j & (1 << i)) freq[i]++;
            }

        }

        int g = 0;

        // o(30 * log(n))

        for(int i = 0; i < 30; i++){
            
            if(freq[i] > 0){

                g = __gcd(g, freq[i]);

            }
        }

        if(g == 0){

            // o(n)

            for(int i = 1; i <= n; i++){

                cout << i << " ";

            }
        }

        else{

            vector<int> ans;

            // o(sqrt(g)) worst case is o(sqrt(n))

            for(int i = 1; i * i <= g; i++){

                if(g % i == 0){

                    ans.push_back(i);

                    if(i != g / i){

                        ans.push_back(g /i);

                    }

                }

            }



            sort(ans.begin(), ans.end());

            // o(ans.size())

            for(auto &i: ans) cout << i << " ";

        }

        cout << endl;

    }

    return 0;
}
