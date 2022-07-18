class Solution {
public:
    const int M=1000000007;
    int dy[1005][1005];
    
    int kInversePairs(int n, int k) {
        dy[1][0]=1;
        int t=1;
        for(int i=2;i<=n;i++) {
            int sum=0;
            for(int j=0;j<=t;j++) {
                for(int l=0;l<i;l++) {
                    if(j+l<=k) dy[i][j+l]=(dy[i][j+l]+dy[i-1][j])%M;
                }
            }
            t=t+i;
            if(t>k) t=k;
        }
        return dy[n][k];
    }
};
/*
1 2 3
1 3 2
2 1 3 : 
2 3 1 : 2
3 1 2 : 2
3 2 1 : 3
*/