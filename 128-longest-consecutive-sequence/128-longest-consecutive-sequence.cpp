class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for(auto i : nums){
            cnt[i]=1;
        }
        int ans=0;
        for(auto i : cnt){
            int a=i.first,b=i.second,len=0;
            //printf("%d %d\n",a,b);
            while(b>0 && cnt.count(a-1)==0){
            //    printf("%d\n",a+len);
                if(cnt.count(a+len)>0) len++;
                else break;
            }
            if(len>ans) ans=len;
        }
        return ans;
    }
};