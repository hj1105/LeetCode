class Solution {
public:
    struct Stack{
        char ch;
        int w;
    }st[30004];
    int longestValidParentheses(string s) {
        int n=s.length(),i,cnt=0;
        for(i=0;i<n;i++){
            if(s[i]=='('){
                st[++cnt].ch='(';
                st[cnt].w=i;
            }
            else{
                if(st[cnt].ch=='(') cnt--;
                else{
                    st[++cnt].ch=')';
                    st[cnt].w=i;
                }
            }
        }
        if(cnt==0) return n;
        int ans=st[1].w;
        st[++cnt].w=n;
        for(i=2;i<=cnt;i++)if(st[i].w-st[i-1].w-1>ans)ans=st[i].w-st[i-1].w-1;
        return ans;
    }
};