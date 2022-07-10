class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> arr;
        vector<int> ret;
        for(int i=0;i<nums.size();i++){
            while(!arr.empty() && arr.front().second<=i-k) arr.pop_front();
            while(!arr.empty() && arr.back().first<nums[i]) arr.pop_back();
            arr.push_back({nums[i],i});
            if(i>=k-1) ret.push_back(arr.front().first);
        }
        return ret;
    }
};