class Solution {
public:
    int max(int a,int b){
        return a>b?a:b;
    }
    
    struct data{
        int a,b,c;
    };
    
    int proc(vector<int>& arr, vector<int>& brr){
        vector<data> dp;
        int n=arr.size(), i;
        dp.push_back({arr[0],brr[0],0});
        for(i=1;i<n;i++){
            data x;
            x.a=dp[i-1].a+arr[i];
            x.b=max(dp[i-1].a+brr[i],dp[i-1].b+brr[i]);
            x.c=max(dp[i-1].b+arr[i],dp[i-1].c+arr[i]);
            dp.push_back(x);
        }
        return max(max(dp[n-1].a,dp[n-1].b),dp[n-1].c);
    }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int a,b;
        a=proc(nums1, nums2);
        b=proc(nums2, nums1);
        return max(a,b);
    }
};