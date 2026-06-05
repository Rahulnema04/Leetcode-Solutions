class Solution {
public:
    int findMin(vector<int>& nums) {
        
        auto min_iter = min_element(nums.begin(), nums.end());
        return *min_iter;


    }
};