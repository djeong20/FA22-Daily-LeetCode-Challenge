class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> mp;
        int n = groupSizes.size();

        for (int i = 0; i < n; ++i) {
            int gs = groupSizes[i];

            if (gs == 1) {
                res.push_back({i});
                continue;
            }

            if (mp.find(gs) == mp.end()) {
                mp[gs] = {i};
            }
            else {
                mp[gs].push_back(i);

                if (mp[gs].size() == gs) {
                    res.push_back(mp[gs]);
                    mp[gs].clear();
                }
            }
        }

        return res;
    }
};