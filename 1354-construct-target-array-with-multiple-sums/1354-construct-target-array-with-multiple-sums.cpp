class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum=0;
        for(auto i : target){
            pq.push(i);
            sum+=i;
        }
        
        while(pq.top()!=1){
            int t=pq.top();
            pq.pop();
            sum-=t;
            if(t<=sum || sum<1) return false;
            t=t%sum;
            sum+=t;
            pq.push(t?t:sum);
        //    printf("%d %d\n",left,sum);
        //    printf("%d\n",sum);
        }
        return true;
    }
};