#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m;

    cin >> n >> m;
    
    vector<vector<int>> a(n+1, vector<int>(m+1));

    for(int i = 1; i <= n; i ++){

        for(int j = 1; j <= m; j++){

            cin >> a[i][j];

        }

    }

    vector<vector<int>> prefix(n+1, vector<int>(m+1));

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++){

            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + a[i][j];

        }

    }

    int q;

    cin >> q;

    while(q--){

        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        int size = (x2- x1 + 1) * (y2 - y1 + 1);

        int sum = prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1];

        if(sum == size){

            cout << 1 << endl;

        }
        else{


            cout << 0 << endl;

        }

    }

    return 0;

}