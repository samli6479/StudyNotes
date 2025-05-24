/*

2 companies have n and m employees respectively.

we want to find the list of employees who are common in both companies.

workes are from 0 to 39

*/

#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,m;

    cin>>n>>m;

    bitset<40> b1;
    bitset<40> b2;

    for(int i = 0; i < n; i++){
        int x;

        cin >> x;

        b1[x] = 1;

    }

    for(int i = 0; i < m; i++){
        int x;

        cin >> x;

        b2[x] = 1;
    }   

    bitset<40> b3;

    b3 = b1 & b2;

    cout << b3.count() << endl;

        // 2) print the actual IDs
    for(int id = 0; id < 40; id++){
        if(b3.test(id)){
            cout << id << " ";
        }
    }

    cout << endl;

    return 0;
}