class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> counter;
        int res = 0;

        for (auto n : nums) {
            ++counter[n];
        }

        for (auto itr : counter) {
            if (itr.second > 1) {
                res += itr.second * (itr.second-1) / 2; // n Choose 2
            }
        }

        return res;
    }
};