class Solution {
public:
    string sortSentence(string s) {
        stringstream ss;
        string p;
        priority_queue<std::pair<int, string>, std::vector<std::pair<int, string>>, std::greater<std::pair<int, string>> > pq;
        
        ss << s;
        
        while (ss >> p) {
            pq.push( { stoi(p.substr(p.size()-1, 1)), p.substr(0, p.size()-1)});
        }
        
        p = pq.top().second;
        pq.pop();
        
        while (!pq.empty()) {
            p += " " + pq.top().second;
            pq.pop();
        }
        
        return p;
    }
};