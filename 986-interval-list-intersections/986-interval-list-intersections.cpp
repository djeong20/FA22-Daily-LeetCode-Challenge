class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        if (firstList.size() == 0 || secondList.size() == 0) {
            return res;
        }
        
        int a_idx = 0;
        int a_end = firstList.size();
        int b_idx = 0;
        int b_end = secondList.size();
        
        while (a_idx != a_end && b_idx != b_end) {
            int a_start = firstList[a_idx][0];
            int a_end = firstList[a_idx][1];
            int b_start = secondList[b_idx][0];
            int b_end = secondList[b_idx][1];
            
            if (a_end < b_start) {
                a_idx++;
            } 
            else if (b_end < a_start) {
                b_idx++;
            }
            else if (a_start <= b_start && b_end <= a_end) {
                vector<int> a = {b_start, b_end};
                res.push_back(a);
                b_idx++;
            }
            else if (b_start <= a_start && a_end <= b_end) {
                vector<int> a = {a_start, a_end};
                res.push_back(a);
                a_idx++;
            }
            else if (a_start <= b_start && b_start <= a_end ) { 
                vector<int> a = {b_start, a_end};
                res.push_back(a);
                a_idx++;
            }
            else if (b_start <= a_start && a_start <= b_end){
                vector<int> a = {a_start, b_end};
                res.push_back(a);
                b_idx++;
            }
            
        }
        
        // cases
        // 1. A.end < B.start || B.end < A.start (no intersection)
        // 2. B.start <= A.end && A.start <= B.start (share some)
        // 3. B.start <= A.start < A.end <= B.end  (include)        
        
        return res;
        
    }
};