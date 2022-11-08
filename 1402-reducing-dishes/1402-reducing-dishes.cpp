class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        
        sort(satisfaction.begin(), satisfaction.end());
        
        int maxVal = 0;
        int val;
        for (int i = 0; i < n; ++i) {
            val = 0;
            
            for (int j = 1; j <= n-i; ++j) {
                val += satisfaction[i+j-1] * j;
            }
            
            maxVal = (val > maxVal) ? val : maxVal;
        }
        
        return maxVal;
    }
};