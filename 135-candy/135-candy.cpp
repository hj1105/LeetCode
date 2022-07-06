class Solution {
public:
    int give[20004];
    vector<int> arr[20004];
    int calc(int cur,int s,int e,int n,vector<int>& ratings)
    {
        int l,r;
        l=s-1<0?99999:ratings[s-1];
        r=e+1>=n?99999:ratings[e+1];
        if(l>cur && r>cur){
            give[s]=give[e]=1;
            return (e-s+1);
        }
        else{
            int a,b,ret=e-s-1;
            a=s-1<0?0:give[s-1];
            b=e+1>=n?0:give[e+1];
            if(s==e){
                give[s]=max(a,b)+1;
                return give[s];
            }
        //    printf("%d %d %d %d %d %d\n",s,e,l,r,a,b);
            if(l<cur){
                ret+=a+1;
                give[s]=a+1;
            }
            else{
                ret+=1;
                give[s]=1;
            }
            if(r<cur){
                ret+=b+1;
                give[e]=b+1;
            }
            else{
                ret+=1;
                give[e]=1;
            }
            return ret;
        }
        return 0;
    }
    
    int candy(vector<int>& ratings) {
        int i,j,n=ratings.size(),ans=0,mx=-1;
        for(i=0;i<n;i++){
            arr[ratings[i]].push_back(i);
            if(ratings[i]>mx) mx=ratings[i];
        }
        for(i=0;i<=mx;i++){
            int s=-1,e=-1,l=arr[i].size();
            if(l==0) continue;
            for(j=0;j<l;j++){
                if(s==-1 || arr[i][j]!=e+1){
                    if(s!=-1) ans+=calc(i,s,e,n,ratings);
                    e=s=arr[i][j];
                }
                else if(arr[i][j]==e+1) e++;
            }
            ans+=calc(i,s,e,n,ratings);
       //     printf("%d\n",ans);
        }
        return ans;
    }
};