class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs[0].size();
        string res = "";
        
        for (int i = 0; i < n; ++i) {
            char c = strs[0][i];
            for (auto s : strs) {
                
                if (s[i] != c) {
                    return res;
                }
                
            }
            res += c;
        }
        
        return res;
    }
};