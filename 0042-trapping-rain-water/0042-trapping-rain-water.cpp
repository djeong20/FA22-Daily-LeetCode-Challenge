class Solution {
public:
    // decreasing monotonic queue
    
    // insert element
    // 1. h < dq.back(), insert
    // 2. h < dq.front() && h > dq.back(), pop dq elements (add water)
    // 2. when new element is larger than front, pop all (add water)

    int trap(vector<int>& height) {
        int res = 0;
        stack <int> s;
        
        for (int i = 0; i < height.size(); i++) {
            
            while(!s.empty() && height[s.top()] < height[i]) {
                int t = s.top();
                s.pop();
                
                if (!s.empty()) {
                    int len = i - s.top() - 1;
                    int m = min(height[s.top()], height[i]);
                    res += (m - height[t]) * len;
                }
            }
            
            s.push(i);
        }
        return res;
    }
};


// 1. {0}
// 2. pop: 0
// 2. {1} push 1
// 3. {1, 0} push 0
// 4. {} / pop: 0, 1 -> 1 (1-0) + 0 (1-1) = 1
// 4. {2} push 2
// {2, 1} 
// {2, 1, 0}
// {2, 1} / pop: 0, 1 -> 2 (1-0) + 1 (1-1) = 0
// {3} / pop: 1, 2 -> 1 (2-1) + 0 (2-2) = 1
// {3, 2}
// {3, 2, 1}
// {3, 2} / pop: 1, 2 -> (2-1) + (2-2) = 1 
