class Solution {
public:
    bool scanMatch(string haystack, string needle, int index) {
        int N = needle.size();
        
        if (index + N > haystack.size()) return false;
        
        for (int i = 0; i < N; ++i) {
            if (haystack[index+i] != needle[i]) return false;
        }
        
        return true;
    }
    
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int nn = needle.size();
        
        int idx = 0;
        int startIdx = 0;
        
        for (int i = 0; i < n; i++) {
            if (haystack[i] == needle[idx] && scanMatch(haystack, needle, i)) {
                return i;
            }
        }
        
        return -1;
    }
};