class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = 0;
        int i2 = 0;
        
        if (n == 0) {
            return;
        }
        if (m == 0) {
            for (auto i : nums2) {
                nums1.push_back(i);
                nums1.erase(nums1.begin());
            }
        }
        
        for (int i = 0; i < nums2.size(); i++) {
            nums1.pop_back();
        }
        
        while (true) {
            if (i1 == nums1.size()) {
                while (i2 < n) {
                    nums1.push_back(nums2[i2]);
                    i2++;
                }
                break;
            }
            
            if (nums1[i1] >= nums2[i2]) {
                nums1.insert(nums1.begin()+i1, nums2[i2]);
                i2++;
            }
            else {
                i1++;
            }
            
            if (i2 == nums2.size()) {
                break;
            }
            
        }
    }
};