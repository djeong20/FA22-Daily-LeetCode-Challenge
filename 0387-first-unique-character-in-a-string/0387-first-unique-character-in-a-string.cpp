class Solution {
public:
    int firstUniqChar(string s) {
        std::unordered_map<int, int> um;
        
        for (int i = 0; i < s.length(); i++) {
            if (um.find(s[i]) == um.end()) {
                um[s[i]] = 1;
            }
            else {
                um[s[i]]++;
            }
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (um[s[i]] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};