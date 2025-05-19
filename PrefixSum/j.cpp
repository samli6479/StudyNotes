#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n;

    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++){

        cin >> a[i];
    }

    vector<int> sorted = a;

    sort(sorted.begin(), sorted.end());

    vector<long long> prefix(n+1);

    vector<long long> orderPrefix(n+1);

    for(int i = 1; i <= n; i++){

        prefix[i] = prefix[i-1] + a[i-1];

        orderPrefix[i] = orderPrefix[i-1] + sorted[i-1];

    }


    int m;

    cin >> m;    

    while(m--){

        int type, l , r;

        cin >> type >> l >> r;

        if(type == 1){

            cout << prefix[r] - prefix[l-1] << endl;

        }

        else{

            cout << orderPrefix[r] - orderPrefix[l-1] << endl;

        }


    }

    return 0;
}