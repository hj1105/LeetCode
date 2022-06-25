class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int sz=nums.size(),cnt1=0,cnt2=0;
        for(int i=1;i<sz;i++){
            if(nums[i-1]>nums[i]){
                cnt1++;
                if(i-2>=0 && nums[i-2]>nums[i]){
                    cnt1=2;
                    break;
                }
            }
        }
        for(int i=1;i<sz;i++){
            if(nums[i-1]>nums[i]){
                cnt2++;
                nums[i]=nums[i-1];
            }
        }
        return cnt1<=1 || cnt2<=1;
    }
};