class Solution {
public:
    
    // 8
    // 3
    // 2, 2
    // 1 
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        const int maxVal = *std::max_element(nums.begin(), nums.end());
        int count[maxVal+1];
        memset(count, 0, sizeof(count));
        
		int N = nums.size();
        
        for (int i = 0; i < N; i++) {
            count[nums[i]]++;
        }
        
        for (int i = 1; i <= maxVal; i++) {
            count[i] += count[i-1];
        }
        
        for (int i = 0; i < N; i++) {
            if (nums[i] == 0) {
                res.push_back(0);
            } else {
                res.push_back(count[nums[i]-1]);    
            }
        }
        
        return res;
    }
};