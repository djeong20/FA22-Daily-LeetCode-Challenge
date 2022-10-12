class Solution {
public:
    bool isSubsequence(string s, string t) {
        for (int i = 0; i < t.length(); i++) {
            
            if (s[0] == t[i]) {
                s.erase(0, 1);
            }
            
            if (s == "") return true;
        }
        if (s == "") return true;
        return false;
    }
};