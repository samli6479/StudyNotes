/*
https://www.codechef.com/problems/XORMUL

given three numbers n, a, b

0 <= a, b < 2 ** n 

find a third number x st 0 <= x < 2 ** n 

and (a xor x) * (b xor x) is maximum

to maximize the result 

it is to have 1 in the most significant bit

xor

1 xor 1 = 0

1 xor 0 = 1

0 xor 0 = 0

let y, z track the result of a xor x and b xor x respectively

if both ai and bi are 0, then we need to set xi to 1

if both ai and bi are 1, then we need to set xi to 0 

regardless of this we need to set yi and zi to 1 so that the result is maximum

then we need to check about if we have 1 and 0 in the same position for a and b

we are trying to maximize y * z

so we can do a two case compare the result of y * z, best can add is the remainder 

*/

#include <bits/stdc++.h>


using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){

        int n, a, b;

        cin >> n >> a >> b;

        int ans = 0;
        
        int y = 0, z = 0;

        for(int i = n-1; i >=  0; i--){

            int remain = (1 << i) - 1;

            int ai = (a>>i)&1;
            int bi = (b>>i)&1;

            if(ai == bi){

                if(ai == 0){

                    ans |= (1 << i);

                }

                y |= (1 << i);

                z |= (1 << i);


            }

            else{


                int y0 = y + (ai << i);
                int z0 = z + (bi << i);

                long long f0 = (long long)(y0 + remain) * (long long)(z0 + remain);


                int y1 = y + (bi << i);
                int z1 = z + (ai << i);

                long long f1 = (long long)(y1 + remain) * (long long)(z1 + remain);

                if(f0 > f1){

                    y = y0;
                    z = z0;
                    
                }

                else{

                    ans |= (1 << i);

                    y = y1;
                    z = z1;

                }

            }


        }

        cout << ans << endl;
    }

    return 0;
}