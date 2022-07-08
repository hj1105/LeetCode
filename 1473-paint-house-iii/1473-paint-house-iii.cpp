class Solution {
public:
    int dy[105][105][25];
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int i,j,k;
        for(i=0;i<=m;i++)for(j=0;j<=target;j++)for(k=0;k<=n;k++)dy[i][j][k]=1e9;
        for(i=1;i<=n;i++) dy[0][0][i]=0;
        for(i=1;i<=m;i++){
            if(houses[i-1]!=0){
                for(j=1;j<=target;j++){
                    for(k=1;k<=n;k++){
                        if(k==houses[i-1]) dy[i][j][k]=min(dy[i][j][k],dy[i-1][j][k]);
                        else dy[i][j][houses[i-1]]=min(dy[i][j][houses[i-1]],dy[i-1][j-1][k]);
                    }
                }
            }
            else{
                for(j=1;j<=target;j++){
                    for(k=1;k<=n;k++){
                        for(int t=1;t<=n;t++){
                            if(k==t) dy[i][j][k]=min(dy[i][j][k],dy[i-1][j][t]+cost[i-1][k-1]);
                            else dy[i][j][k]=min(dy[i][j][k],dy[i-1][j-1][t]+cost[i-1][k-1]);
                        }
                    }
                }
            }
        }
        /*for(i=1;i<=m;i++){
            printf("--------\n%d\n",i);
            for(j=1;j<=target;j++){
                for(k=1;k<=n;k++) printf("%d ",dy[i][j][k]);
                printf("\n");
            }
        }*/
        int ret=1e9;
        for(j=1;j<=n;j++)if(dy[m][target][j]<ret)ret=dy[m][target][j];
        if(ret==1e9) return -1;
        return ret;
    }
};