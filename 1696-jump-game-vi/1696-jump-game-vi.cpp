class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int,int>> que;
        int v;
        for(int i=0;i<nums.size();i++){
            while(!que.empty() && que.front().second<i-k) que.pop_front();
            if(i==0) v=nums[0];
            else v=que.front().first+nums[i];
            while(!que.empty() && que.back().first<v) que.pop_back();
            que.push_back({v,i});
      //      printf("%d %d\n",v,i);
        }
        return v;
    }
};