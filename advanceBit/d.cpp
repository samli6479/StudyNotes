/*

https://www.codechef.com/problems/MAXAND18

sequence of n numbers and integer k 

for given integer x st exactly k bits are set in its binary representation 

sum of ai & x is maximum possible

if there are multiple such x then choose the smallest one


bitwise and of the two numbers is the common set bits in the two numbers

traverse the array and construct a frequency array of the bitwise and of each elements

check the contribution of each bit in the frequency array and record the contribution

put the contribution and the bit location in a vector of pairs

sort the vector in descending order of contribution and ascending order of bit location

construct the answer from the sorted vector

*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    cin>>t;

    while(t--){

        int n,k;

        cin>>n>>k;

        vector<int> a(n);

        for(int i= 0; i < n; i++){

            cin >> a[i];

        }

        vector<int> freq(32,0);

        for(auto x: a){

            for(int i = 0; i < 32; i++){

                if(x & (1 << i)){   

                    freq[i]++;
                }

            }

        }

        vector<pair<long long,int>> order;

        order.reserve(32);

        for(int i = 0; i < 32; i++){

            long long contribution = freq[i] * (1ll << i);

            order.push_back({contribution, i});

            
        }

        /*
        for(int i = 0; i < 32; i++){

            long long contribution = freq[i] * (1ll << i);

            order.push_back({contribution, i*-1});

            
        }
        
        */




        sort(order.begin(), order.end(),
            
            [&](auto &a, auto &b){

                if(a.first != b.first){

                    return a.first > b.first;
                }

                return a.second < b.second;
            }
            );

        /*
        
        sort(order.rbegin(), order.rend());
        */
    

            int ans = 0;
            
            for(int i = 0; i < k; i++){

                ans |= (1 << order[i].second);

            }

        /*
            int ans = 0;
            
            for(int i = 0; i < k; i++){

                int bit = abs(order[i].second);

                ans |= (1 << bit);

            }
        
        */

            cout << ans << endl;
        }

    return 0;
}