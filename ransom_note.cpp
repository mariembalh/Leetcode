class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int npos = -1;
        for(char& c: magazine)
        {
            cout << "the new strring is " << ransomNote<<endl;
            npos=ransomNote.find(c);
            if (npos!= -1)
            {
                ransomNote.erase(ransomNote.begin()+npos);
            }
        }
        return true && ransomNote.empty();
    }
};
