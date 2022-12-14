#include <unordered_map>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> dict;
        
        int n = nums.size();
        
        if (n == 1) {
            return nums[0];
        }
        
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            
            std::cout << val << std::endl;
            auto itr = dict.find(val);
            
            if (itr == dict.end()) {
                dict.insert({val, 1});
            }
            else {
                itr->second += 1;
                
                if (itr->second > n/2) {
                    return itr->first;
                }
            }
            
            
        }
        return 0;
    }
};