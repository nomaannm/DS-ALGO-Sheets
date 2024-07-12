int countNodesinLoop(struct Node *head)
{
    map<Node*,int> mpp;
    int timer = 1;
    
    Node* temp = head;
    while(temp != nullptr){
        if(mpp.find(temp) != mpp.end()){
            break;
        }
        mpp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    
    return timer - mpp[temp];
}
