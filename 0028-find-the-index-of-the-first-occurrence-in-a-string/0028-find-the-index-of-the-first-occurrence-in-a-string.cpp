class Solution {
public:
    bool scanMatch(string haystack, string needle, int index, int n, int nn) {    
        for (int i = 0; i < nn; ++i) {
            if (haystack[index+i] != needle[i]) return false;
        }
        
        return true;
    }
    
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int nn = needle.size();
        
        for (int i = 0; i <= n-nn; ++i) {
            if (haystack[i] == needle[0] && scanMatch(haystack, needle, i, n, nn)) {
                return i;
            }
        }
        
        return -1;
    }
};