class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> arr;
        for(auto i : nums) arr.push_back(i);
        int i, t=0;
        for(i=k;i>=1;i--) {
            t--;
            if(t<0) t=arr.size()-1;
        }
        for(i=0;i<nums.size();i++) {
            nums[i]=arr[t];
            t++;
            if(t>=nums.size()) t=0;
        }
    }
};