#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;

    cin >> n;

    vector<int> a(n);

    for(auto &i: a) cin >> i;

    long long sum = 0;

    long long count = 0;

    vector<long long> mp(n);

    mp[0] = 1;

    for(int i = 0; i <n ; i++){

        sum += a[i];

        long long rem = (sum % n + n) % n;

        count += mp[rem];

        mp[rem]++;
        

    }

    cout << count << endl;

    return 0;
}