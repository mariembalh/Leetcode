class Solution {
public:
    int romanToInt(string s) {
        string sub = "IXC";
        map<char, int> values { { 'I', 1}, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
        vector<char> v;
        map<char, char> m = { { 'V', 'I'}, { 'X', 'I'}, { 'L', 'X'}, { 'C', 'X'}, { 'M', 'C'}, { 'D', 'C'} };
        int  score =0 , prescore = 0, postcore = 0;
        for(char& c : s)
        {
            if((sub.find(c) != -1 ) || (!v.empty()))
            {
                if( (!v.empty()) && (v.back() == m[c]))
                {
                    char pre = v.back();
                    postcore += values[c]- values[pre];
                    prescore -= values[pre];
                    v.pop_back();
                }
                else 
                {
                    v.push_back(c);
                    prescore += values[c];
                }
            }
            else
            {

                score += values[c];
            }    
        }

        score += postcore;
        score += prescore;
        return score;
    }
};
