class Solution {
public:

        int maximumPopulation(vector<vector<int>>& logs) {
        
        int n = logs.size();

        vector<int> prefix(2060);

        for(int i = 0; i < n; i++ ){

            prefix[logs[i][0]] += 1;

            prefix[logs[i][1]] -= 1;
        }

        int maxCount = 0;

        int year = 0;

        for(int i = 1950; i <= 2050; i++){

            prefix[i] += prefix[i-1];

            if(prefix[i] > maxCount){

                maxCount = prefix[i];

                year = i;
            }

        }

        return year;

    };

    int maximumPopulation(vector<vector<int>>& logs) {

        // initialize set and insert value to set
        
        int n = logs.size();

        set<int> log;

        for(int i = 0; i < n; i++){

            log.insert(logs[i][0]);

            log.insert(logs[i][1]);

        }

        // get list of values from set

        vector<int> newLog(log.begin(), log.end());

        int m = newLog.size();      

        // build map for corrdinate compression

        map<int, int> mp;

        int idx = 0;

        for(auto i: log){

            mp[i] = idx++;

        }

        // build prefix list and add diff to it

        vector<int> prefix(m+1);

        for(int i = 0; i < n; i++){

            prefix[mp[logs[i][0]]] += 1;

            prefix[mp[logs[i][1]]] -= 1;

        }

        // generate the prefix array 

        for(int i = 1; i < m;i++){

            prefix[i] += prefix[i-1];


        }

        // calculate the final answer

        int maxCount = 0;

        int year = newLog[0];

        for(int i = 0; i < m;i++){

            if(prefix[i] > maxCount){

                maxCount = prefix[i];

                year = newLog[i];

            }


        }

        return year;

    };
};