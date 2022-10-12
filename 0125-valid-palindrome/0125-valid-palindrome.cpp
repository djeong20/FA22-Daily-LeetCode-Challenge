class Solution {
public:
    bool isPalindrome(string s) {
        deque<char> dq;
        int n = s.length();
        char c1, c2;
            
        for (int i = 0; i < n; i++) {
            if (isalpha(s[i])) {
                dq.push_back(tolower(s[i]));
            }
            if (isdigit(s[i])) {
                dq.push_back(s[i]);
            }
        }
        
        while (dq.size() > 1) {
            c1 = dq.front();
            c2 = dq.back();
            
            if (c1 != c2) {
                // std::cout << c1 << " " << c2 << std::endl;
                return false;
            }
            dq.pop_front();
            dq.pop_back();
        }
        
        return true;
    }
};