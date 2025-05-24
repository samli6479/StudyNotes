/*
https://www.codechef.com/COOK143A/problems/SEGFAULT

Problem: Finding the Thief

There are N people numbered from 1 to N with the following rules:
1. Exactly one person is a thief
2. The thief always lies
3. All other people always tell the truth

Each person i makes a claim about who the thief could be:
- Person i says the thief is one of the people in the range [Li, Ri]
- This means the thief could be Li, Li+1, Li+2, ..., Ri

Your task:
- Determine how many different people could possibly be the thief
- It is guaranteed that at least one person can be the thief

Input:
- First line: N (number of people)
- Next N lines: Each line contains Li and Ri (the range claimed by person i)

Output:
- Print a single integer: the number of people who could be the thief

Input:
1           // number of test cases
3           // n = 3 people
1 2         // person 1 claims [1,2]
3 3         // person 2 claims [3,3] (if thief, would lie and say thief is at 3)
1 3         // person 3 claims [1,3]

Output:
1           // number of possible thieves
2           // position 2 is the only possible thief

Solution Logic:

1. For each interval [left[i], right[i]]:
   - Add 1 at position left[i] in diff array
   - Subtract 1 at position right[i]+1 in diff array

2. Compute prefix sum of diff array to get coverage count:
   - For each position i: diff[i] += diff[i-1]
   - This gives us how many intervals cover each position

3. For each position i from 1 to n:
   - Check if diff[i] == n-1 (exactly n-1 intervals cover this position)
   - AND check if !(left[i] <= i && i <= right[i]) (position i is not covered by its own interval)
   - If both conditions are true, add i to answer

4. Output:
   - First line: size of answer array
   - Second line: all positions that satisfy the conditions

*/


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

            cout << ans[i] << endl;

        }
    }


    return 0;

}