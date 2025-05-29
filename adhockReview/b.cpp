/*

https://cses.fi/problemset/task/1074/

input - n sticks of length p1, p2, ... , pn

output - minimum cost of making all sticks of equal length

find the median of the sticks and calcualte the total cost of by doing the traverse? 

sort the sticks and then find the median 

*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;

    cin >> n;

    vector<long long> sticks(n);

    for(int i = 0; i < n; i++){

        cin >> sticks[i];
    }

    sort(sticks.begin(), sticks.end());

    long long median = 0;

    long long total_cost = 0;

    if(n % 2 == 0){

        long long median1 = sticks[n/2 - 1];
        long long median2 = sticks[n/2];

        median = (median1 + median2) / 2;

    }

    else{   

        median = sticks[n/2];
    }

    for(int i = 0; i < n; i++){

        total_cost += abs(sticks[i] - median);
    }

    cout << total_cost << endl;

    return 0;

}