class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = sandwiches.size();
        vector<int> count(2, 0);
        
        for (auto s : students) {
            count[s]++;
        }
       
        for (int i = 0; i < n; i++) {
            count[sandwiches[i]]--;
            
            if (count[sandwiches[i]] < 0) return n - i;
        }
        
        return 0;
    }
};