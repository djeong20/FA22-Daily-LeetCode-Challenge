class Solution {
public:    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for (auto str : strs) {
            string key = str;
            std::sort(key.begin(), key.end());
            
            if (mp.find(key) == mp.end()) {
                mp[key] = vector<string> {str};
            }
            else {
                mp[key].push_back(str);
            }
        }
        
        vector<vector<string>> res;
        
        for (auto e : mp) {
            res.push_back(e.second);
        }
        
        return res;
    }
};