class Solution {
public:
    struct Stack{
        int h,w;
    }st[20004];
    int trap(vector<int>& height) {
        int ret=0, top=0, n=height.size(), i;
        for(i=n-1;i>=0;i--){
            while(top>0 && st[top].h<height[i]){
                if(top-1>0) ret+=(min(st[top-1].h,height[i])-st[top].h)*(st[top-1].w-i-1);
                //printf("%d %d %d %d %d\n",i,height[i],st[top-1].w,st[top-1].h,ret);
                top--;
            }
            st[++top].h=height[i];
            st[top].w=i;
        }
        return ret;
    }
};