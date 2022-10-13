class Solution {
public:
    int longestValidParentheses(string s) {
        std::stack<int> st;
        st.push(-1);
        int res = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                
                if (st.empty()) {
                    st.push(i);
                }
                else {
                    res = res > i - st.top() ? res : i - st.top();
                }
            }
        }
        return res;
    }
    
    
    // basic idea: '(' = push, ')' = pop : if (!st.empty())
    // if st.empty() after pop, valid parentheses 
};