#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    cin >> t;


    while(t--){

        int n;

        cin >> n;

        vector<long long> diff(n+2);

        vector<int> left(n+1), right(n+1);



        for(int i = 1; i <= n; i++){

            int l, r;

            cin >> left[i] >> right[i];
            
            diff[left[i]]++;

            diff[right[i]+1]--;   

        }

        for(int i = 1; i <= n; i++){

            diff[i] += diff[i-1];

        }

        vector<int> ans;

        for(int i = 1; i <= n; i++){

            if(diff[i] == n -1 && !(left[i] <= i && i <=right[i] )){

                ans.push_back(i);

            }

        }

        cout << ans.size() << endl;

        for(int i = 0; i < ans.size(); i++){

            cout << ans[i] << " ";

        }
    }


    return 0;

}