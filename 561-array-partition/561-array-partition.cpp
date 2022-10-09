class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int v = 0;
        
        for (auto it = nums.begin(); it != nums.end(); it+=2) {
            v += *it;
        }
        
        return v;
    }
};