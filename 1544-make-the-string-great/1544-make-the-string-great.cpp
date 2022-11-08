class Solution {
public:
    string makeGood(string s) {
        std::stack<char> st;
        
        for (int i = 0; i < s.size(); ++i) {
            
            if (isupper(s[i])) {
                // check if stack top is lower & same char
                if (!st.empty() && islower(st.top()) && st.top() == tolower(s[i])) {
                    st.pop();
                    continue;
                }
            }
            else {
                if (!st.empty() && isupper(st.top()) && st.top() == toupper(s[i])) {
                    st.pop();
                    continue;
                }
            }
            
            
            st.push(s[i]);
        }
        string res = "";
        
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        
        return res;
    }
};