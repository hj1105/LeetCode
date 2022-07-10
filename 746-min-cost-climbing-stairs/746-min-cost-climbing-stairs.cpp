class Solution {
public:
    int dy[1005];
    int minCostClimbingStairs(vector<int>& cost) {
        dy[0]=cost[0];
        dy[1]=cost[1];
        int i,n=cost.size();
        for(i=2;i<n;i++)dy[i]=min(dy[i-1],dy[i-2])+cost[i];
        return min(dy[n-1],dy[n-2]);
    }
};