class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(nums.size()==1){
            if(k%2==0) return nums[0];
            return -1;
        }
        int ret=-1;
        if(k>nums.size()){
            for(auto i : nums) ret=max(ret,i);
            return ret;
        }
        else if(k==nums.size()){
            for(int i=0;i<nums.size()-1;i++) ret=max(ret,nums[i]);
            return ret;
        }
        else{
            for(int i=0;i<=k;i++){
                if(i==k-1) continue;
                ret=max(ret,nums[i]);
            }
            return ret;
        }
    }
};