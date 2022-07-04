/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ret=nullptr, *cur=nullptr, *bef=nullptr;
        if(lists.size()==0) return ret;
        for(ListNode *i=lists[0];i;i=i->next){
            ListNode *nxt=new ListNode(i->val);
            if(ret==nullptr){
                ret=nxt;
                cur=ret;
            }
            else{
                cur->next=nxt;
                cur=nxt;
            }
        }
        for(int i=1;i<lists.size();i++){
            cur=ret;
            bef=nullptr;
            ListNode *lcur=lists[i];
            while(cur){
                if(lcur==nullptr) break;
                
             //   printf("%d %d\n",cur->val, lcur->val);
                if(lcur->val<cur->val){
                    ListNode *tmp=new ListNode();
                    tmp->val=lcur->val;
                    tmp->next=cur;
                    if(bef!=nullptr) bef->next=tmp;
                    else ret=tmp;
                    cur=tmp;
                    lcur=lcur->next;
                }
                
                bef=cur;
                cur=cur->next;
            }
            cur=bef;
            while(lcur!=nullptr){
                ListNode *nxt=new ListNode(lcur->val);
                if(ret==nullptr){
                    ret=nxt;
                    cur=ret;
                }
                else{
                    cur->next=nxt;
                    cur=nxt;
                }
                lcur=lcur->next;
            }
        }
        return ret;
    }
};