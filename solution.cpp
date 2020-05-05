class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return head;
        }
        unordered_map<Node*, Node*> hm;
        Node* h1 = head;
        Node* h2 = NULL;
        Node* res;
        // tạo bản sao của danh sách liên kết và chưa quan tâm đến con trỏ random
        while(h1)
        {
            Node* temp = new Node(h1->val, NULL, NULL);
            // nếu nó là node đầu tiên mình copy
            if(!h2)
            {
                h2 = temp;
                // res để giữ lại node đầu của bản sao chép danh sách liên kết
                res = h2;
            }
            else
            {
                h2->next = temp;
                h2 = temp;
            }
            hm.insert({h1,h2});
            h1 = h1->next;
        }
        h1 = head;
        h2 = res;
        Node* ans = h2;
        // dùng hashmap để kiếm node bản sao mà con trỏ random của node bản sao cần nối 
        while(h1)
        {
            h2->random = NULL;
            // nếu nốt random của bản chính không null
            if(h1->random)
                h2->random = hm.find(h1->random)->second;
            h1 = h1->next;
            h2 = h2->next;
        }
        return res;
    }
};
