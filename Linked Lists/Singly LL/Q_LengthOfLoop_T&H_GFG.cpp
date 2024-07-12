int findLength(Node*& slow, Node*& fast){
    int length = 1;
    fast = fast->next;
    while(slow != fast){
        length++;
        fast = fast->next;
    }
    return length;
}

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{
    
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return findLength(slow, fast);
        }
            
    }
    
    return 0;
}
