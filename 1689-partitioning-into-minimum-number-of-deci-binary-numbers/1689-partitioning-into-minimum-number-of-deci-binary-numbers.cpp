class Solution {
public:
    int minPartitions(string n) {
        int ret=0;
        while(1){
            int mini=10,len=n.size();
            for(int i=0;i<len;i++){
                if(n[i]-'0'!=0 && n[i]-'0'<mini) mini=n[i]-'0';
            }
            if(mini==10) break;
            ret+=mini;
            for(int i=0;i<len;i++)if(n[i]!='0')n[i]-=mini;
        }
        return ret;
    }
};