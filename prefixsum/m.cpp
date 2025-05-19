#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    int n, q;
 
    cin >> n >> q;
 
    vector<int> a(n);
 
    for(auto &i: a) cin >> i;
 
    vector<int> prefix(n+2);
 
    while(q--){
 
        int l, r;
 
        cin >> l >> r;
 
        prefix[l] += 1;
 
        prefix[r+1] -= 1;
 
    }
 
    for(int i = 1; i <= n; i++){
 
        prefix[i] += prefix[i-1];
 
    }

    vector<long long> f(n);

    for(int i = 1; i <= n; i++){

        f[i-1] = prefix[i];

    }
 
    sort(f.begin(), f.end());
 
    sort(a.begin(), a.end());
 
    long long ans = 0;
 
    for(int i = 0; i < n; i++){
 
        ans += (long long)f[i] * a[i];        
 
 
    }
 
    cout << ans << endl;
 
    return 0;
}