/*
https://leetcode.com/problems/maximum-good-people-based-on-statements/

There are two types of persons:

The good person: The person who always tells the truth.
The bad person: The person who might tell the truth and might lie.
You are given a 0-indexed 2D integer array statements of size n x n that represents the statements made by n people about each other. 
More specifically, statements[i][j] could be one of the following:

0 which represents a statement made by person i that person j is a bad person.
1 which represents a statement made by person i that person j is a good person.
2 represents that no statement is made by person i about person j.
Additionally, no person ever makes a statement about themselves. Formally, we have that statements[i][i] = 2 for all 0 <= i < n.

Return the maximum number of people who can be good based on the statements made by the n people.

we can use bit mask to represent the combination of good and bad people.

1 << n is the total number of combinations.

for each one of the mask, we check if ith bit is set or not to determine if person is good or bad.

if ith bit is set, we check if the statement made by ith person is consistent with the mask.




*/

#include <bits/stdc++.h>

using namespace std;

class Solution {

    public:

    int maximumGood(vector<vector<int>>& statements) {

        int n = statements.size();

        int ans = 0;

        for(int mask = 0; mask < (1 << n); mask ++){

            bool ok = true;

            for(int i = 0; i < n; i++){

                // if ith bit is not set, we skip

                if((mask & (1 << i)) == 0) continue;

                // if ith bit is set, we check if the statement made by ith person is consistent with the mask.
                for(int j = 0; j < n; j++){

                    int good = (mask & (1 << j)); 

                    if (statements[i][j] ==2) continue;

                    if(statements[i][j] == 0 && good || statements[i][j] == 1 && !good){

                        ok = false;

                        break;

                    }   
                }                    

            }

            if(ok) ans = max(ans, __builtin_popcount(mask));


        }

        return ans;
    }
        
};
