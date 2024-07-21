class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        int carry = backtracked(head);
        if(carry == 1){
            Node* newNode = new Node(1);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
    int backtracked(Node*& temp){
        if(temp == NULL) return 1;
        int carry = backtracked(temp->next);
        temp->data += carry;
        if(temp->data < 10) return 0;
        else{
            temp->data = 0;
            return 1;
        }
    }
    
    
};
