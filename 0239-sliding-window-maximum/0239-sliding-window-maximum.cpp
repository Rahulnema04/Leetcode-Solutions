class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;   // stores INDICES, front = index of current max
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {

        // 1. Remove indices outside the current window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // 2. Remove indices from back whose values <= nums[i]
        //    (they can never be the max while nums[i] is in window)
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();

        dq.push_back(i);

        // 3. Start recording results once first full window is formed
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}
};