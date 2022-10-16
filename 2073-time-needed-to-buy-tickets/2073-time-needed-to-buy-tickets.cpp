class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
            
            if (i < k) count += tickets[i] > tickets[k] ? tickets[k] : tickets[i];
            else if (i > k) count += tickets[i] >= tickets[k] ? tickets[k]-1 : 
            tickets[i];
            else count += tickets[k];
            
            
        }
        return count;
    }
};