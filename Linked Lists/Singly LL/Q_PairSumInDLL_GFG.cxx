class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>> ans;
        Node* temp1 = head;
        Node* temp2 = head;
        reachTheTail(temp2);
        //while(left->data < right->data)
        while(temp1 != NULL && temp2 != NULL && temp1 != temp2){
            if(temp1->data + temp2->data <= target){
                if(temp1->data + temp2->data == target) ans.push_back({temp1->data, temp2->data});
                temp1 = temp1->next;
            }
            else{
                temp2 = temp2->prev;
            }
        }
        return ans;
        
    }
    
    inline void reachTheTail(Node*& node){
        while(node->next != NULL){
            node = node->next;
        }
    }
};
