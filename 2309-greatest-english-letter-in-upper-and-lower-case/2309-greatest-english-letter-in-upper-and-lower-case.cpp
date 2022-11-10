class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> lower;
        unordered_set<char> upper;
        
        char res = 0;
        
        for (auto c : s) {
            if (isupper(c)) upper.insert(c);    
            else lower.insert(c);
            
            if (lower.find(tolower(c)) != lower.end() && upper.find(toupper(c)) != upper.end() && toupper(c) > res) {
                res = toupper(c);
            }
        }
        
        if (res) return std::string(1, res);
        
        return "";
    }
};