#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, x;

    cin >> n >> x;

    vector<int> a(n);

    for(auto &i: a) cin >> i;

    long long ans = 0;

    long long sum = 0;

    map<long long , int> mp;
 
    mp[0] = 1;

    for(int i = 1; i <= n; i++){

        sum += a[i-1];

        ans += mp[sum - x];

        mp[sum]++;

    }

    cout << ans << endl;
    return 0;
}