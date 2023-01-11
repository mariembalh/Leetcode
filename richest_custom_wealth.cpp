class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int wealth =0, maximum = -1;
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=0;j<accounts[i].size();j++)
            {
                wealth +=accounts[i][j];
            }
            maximum = max(maximum,wealth);
            wealth = 0;
        }
        return maximum;
    }
};
