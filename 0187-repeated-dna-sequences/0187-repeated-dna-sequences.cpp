class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        unordered_set<string> dna;
        unordered_set<string> res;
        string seq;
        
        for (int i = 0; i < n-9; i++) {
            seq = s.substr(i, 10);
            
            if (dna.find(seq) == dna.end()) {
                dna.insert(seq);
            } 
            else {
                res.insert(seq);
            }
        }
        
        vector<string> v;
        
        for (string st : res) {
            v.push_back(st);
        }
        
        return v;
    }
};