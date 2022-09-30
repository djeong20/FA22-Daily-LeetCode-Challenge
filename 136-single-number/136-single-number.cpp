class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            
            auto it = s.find(val);
            
            if (it == s.end()) {
                s.insert(val);
            }
            else {
                s.erase(val);
            }            
        }
        
        auto it = s.begin();
        
        return *it;
    }
};