#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, q; 

    cin >> n >> q;

    vector<long long> a(n);

    vector<long long> res(n+1);

    for(auto &i : a){

        cin >> i;
    }

    res[0] = 0;

    for (int i = 1; i <= n; i++){

        res[i] = res[i-1] + a[i-1];

    }


    while(q -- ){

        int l, r;

        cin >> l >> r;

        cout << (res[r] - res[l-1]) << endl;


    }


    return 0;
}