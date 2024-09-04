struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
  public:
    void removeLoop(Node* head) {
        if(head==NULL || head->next == NULL) return;
        
        Node* fast=head;
        Node* slow=head;
        
        while(fast != NULL && fast->next != NULL){
            fast=fast->next->next;
            slow=slow->next;
            
            if(slow==fast){
                break;
            } 
        }
        
        if (slow != fast) {
            return;
        }
        
        slow=head;
        if(slow==fast){
            while(fast->next!=slow){
                fast=fast->next;
            }
        }
        else{
            while(slow->next!= fast->next){
                slow=slow->next;
                fast=fast->next;
            }
        }
        fast->next=NULL;
    }
};
