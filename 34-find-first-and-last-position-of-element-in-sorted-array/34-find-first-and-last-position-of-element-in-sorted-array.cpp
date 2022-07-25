class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        if(!binary_search(nums.begin(),nums.end(),target)){
            ret.push_back(-1);
            ret.push_back(-1);
        }
        else{
            int sit=lower_bound(nums.begin(),nums.end(),target)-nums.begin(), eit=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
            ret.push_back(sit);
            ret.push_back(eit-1);
        }
        
        return ret;
    }
};