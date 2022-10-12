class Solution {
public:
    string simplifyPath(string path) {
        std::stack<string> s;
        std::string delimiter = "/";
        std::string token;
        path += "/";
        size_t pos = 0;
        
        while ((pos = path.find(delimiter)) != std::string::npos) {
            token = path.substr(0, pos);
            
            if (token == ".." && !s.empty()) {
                s.pop();    
            }
            else if (token != ".." and token != "." and token != "") {
                s.push(token);
            }
            
            path.erase(0, pos + 1);
        }
        
        std::string res = "";
        
        while (!s.empty()) {
            res = "/" + s.top() + res;
            s.pop();
        }
        
        return res != "" ? res : "/";
    }
};