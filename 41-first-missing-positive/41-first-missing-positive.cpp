class Solution {
public:
    int check[500005];
    int firstMissingPositive(vector<int>& nums) {
        for(auto i : nums)if(i>0 && i<=nums.size()) check[i]=1;
        for(int i=1;i<=nums.size();i++)if(!check[i]) return i;
        return nums.size()+1;
    }
};