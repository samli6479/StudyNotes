#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, k , q;

    cin >> n >> k >> q;

    vector<int> temp(200010);

    vector<int> ans(200010);


    for(int i = 0; i < n; i++){

        int l, r;

        cin >> l >> r;

        temp[l]++;

        temp[r+1]--;

    }


    for(int i = 1; i <= 200000; i++){

        temp[i] += temp[i-1];

    }

    for(int i = 1; i <= 200000; i++){

        if(temp[i] >= k){

            ans[i] = 1;

        }

        ans[i] += ans[i-1];

    }
    
    for(int i = 0; i < q; i++){

        int a, b;

        cin >> a >> b;

        cout << ans[b] - ans[a-1] << endl;

    }
    return 0;
}
