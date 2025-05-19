#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    long long bundle;

    cin >> n >> bundle;

    vector<int> a(n + 1), b(n + 1), c(n+1);

    for(int i = 1; i <= n; i++){

        cin >> a[i] >> b[i] >> c[i];

    }

    set<int> v;

    for(int i = 1; i <= n; i++){

        v.insert(a[i]);

        v.insert(b[i] + 1);

    }

    int idx = 0;

    map<int, int> mp;

    for(auto i: v){

        mp[i] = idx++;

    }

    vector<int> newCord(v.begin(), v.end());
    int M = v.size();

    vector<long long> diff(M + 1);

    for(int i = 1; i <= n; i++){

        long long idx1 = mp[a[i]], idx2 = mp[b[i] + 1];

        diff[idx1] += c[i];

        diff[idx2] -= c[i];

    }

    for(int i = 1; i < M; i++){

        diff[i] += diff[i-1];

    }

    long long ans = 0;

    for(int i = 1; i < M; i++){

        long long span = newCord[i] - newCord[i-1];

        ans += min(diff[i-1], bundle) * span;

    }

    cout << ans << endl;

    return 0;
}