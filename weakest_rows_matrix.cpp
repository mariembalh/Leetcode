class Solution {
public:
    static bool cmp(pair<int, int>& a,
            pair<int, int>& b)
    {
        if(a.second != b.second)
            return a.second < b.second;
        else
            return a.first < b.first;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int nb_soldier = 0;
        vector<pair<int, int> > soldiers;
        vector<int> response;
        for(int i=0;i<mat.size();i++)
        {
            nb_soldier = 0;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j] == 1)
                    nb_soldier++;
                else 
                    break;
            }
            soldiers.push_back(make_pair(i,nb_soldier));
        
        }
        sort(soldiers.begin(), soldiers.end(), cmp);
        for (int i=0; i<k; i++)response.push_back(soldiers[i].first);
        return response;
    }
};
