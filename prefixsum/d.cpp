
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int n = nums.size();
        
        vector<int> prefixSums(n + 1, 0);
        for (int i = 1; i <= n; ++i) {

            if(nums[i-1] == 1){

                 prefixSums[i] = prefixSums[i - 1] + 1;

            }
            else{

                prefixSums[i] = prefixSums[i - 1] - 1;


            }
        }

        unordered_map<int, int> firstIndex;
        firstIndex[0] = 0;  // sum 0 first occurs at “index” 0
        int maxLen = 0;

        for (int i = 1; i <= n; ++i) {
            int sum = prefixSums[i];
            auto it = firstIndex.find(sum);
            if (it != firstIndex.end()) {
                // found before: subarray (it->second .. i-1) has zero net sum
                maxLen = max(maxLen, i - it->second);
            } else {
                // first time seeing this prefix‐sum
                firstIndex[sum] = i;
            }
        }

        return maxLen;
    }
};