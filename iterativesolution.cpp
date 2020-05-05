class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return head;
        }
        Node* h1 = head;
        Node* temp = h1->next;
        // điều khiển con trỏ next của bản chính và bản sao nối với nhau
        while(h1)
        {
            h1->next = new Node(h1->val, temp, NULL);
            h1 = temp;
            if(temp)
                temp = temp->next;
        }
        // nối con trỏ random bản sao sao cho giống với bản chính
        h1 = head;
        while(h1)
        {
            h1->next->random = NULL;
            if(h1->random)
                h1->next->random = h1->random->next;
            h1 = h1->next->next;
        }
        h1 = head;
        Node* h2 = head->next;
        Node* res = head->next;
        // trả lại con trỏ next sao cho giống với bản chính lúc đầu
        while(h1 && h2){
            h1->next = h2->next;
            h1 = h1->next;
            if(h1)
                h2->next = h1->next;
            h2 = h2->next;
        }
        return res;
    }
};
