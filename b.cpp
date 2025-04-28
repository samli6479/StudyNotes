#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, q;

    cin >> n >> q;

    vector<vector<int>>a(n + 1, vector<int>(n+1));

    for(int i = 1; i <= n; i++){
        for (int j = 1; j <=  n; j++){
            char ch;
            cin >> ch;

            if (ch == '*'){

                a[i][j] = 1;

            }

            else{

                a[i][j] = 0;

            }

        }
    }

    vector<vector<long long>>prefix(n+1, vector<long long>(n+1));

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= n; j++){

            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + a[i][j];

        }

    }


    while(q--){

        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        long long ans = prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1];

        cout << ans << endl;


    }
    return 0;
}