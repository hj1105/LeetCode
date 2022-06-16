class Solution {
public:
int dy[1005][1005];
string longestPalindrome(string s) {
    int k,i,j,len=s.length(),max_len=0,st,en;
    for(i=0;i<len;i++) dy[i][i]=1;
    for(i=0;i<len-1;i++){
        if(s[i]==s[i+1]) dy[i][i+1]=1;
    }
    for(k=2;k<len;k++){
        for(i=0;i<len;i++){
            if(i+k>=len) break;
            j=i+k;
            if(s[i]==s[j] && dy[i+1][j-1]) dy[i][j]=1;
        }
    }
    for(i=0;i<len;i++)for(j=i;j<len;j++){
            if(dy[i][j]){
                if(j-i+1>max_len){
                    max_len=j-i+1;
                    st=i;
                    en=j;
                }
            }
        }
    string ret="";
    for(i=st;i<=en;i++) ret+=s[i];
    return ret;
}
};