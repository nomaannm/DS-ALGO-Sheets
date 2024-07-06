#include<iostream>
#include <vector>
#define LENGTH int


struct Node {
    int data;
    Node* next;

    //Constructor 1
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    //Constructor 2
    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};

Node*
insertionAtHead(int val, Node* head) {
    Node* temp = new Node(val, head);
    return temp;

}

Node*
insertionAtTail(int val, Node* head) {
    if(head == nullptr) {
        return new Node(val);
    }

    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node*
insertAtK(Node* head, int element, int K ) {
    if(head == nullptr) {
        if(K==1) return new Node(element);
        else return nullptr;
    }
    if(K == 1) {
        Node* temp = new Node(element, head);
        return temp;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp!=nullptr) {
        cnt++;
        if(cnt == K-1 ) {
            Node* x = new Node(element);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node*
insertBeforeValue(Node* head, int element, int val) {
    if(head == nullptr) return nullptr;
    if(head->data == val) {
        return new Node(element, head);
    }
    Node* temp = head;
    while(temp->next != nullptr) {
        if(temp->next->data == val) {
            Node* x = new Node(element, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}



Node*
convertArrToLL(std::vector<int>& arr) {
    if(arr.empty()) return nullptr;
    Node* head = nullptr;
    Node* mover = nullptr;
    for(size_t i = 0; i < arr.size() ; i++) {
        if(i == 0) {
            head = new Node(arr[i]);
            mover = head;
        }
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}



void
deleteAtHead(Node*& head) {
    if(head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

Node*
deleteAtTail(Node* head) {
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node* temp = head;
    while(temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

void
deleteAtK(Node*& head, const int KthElement) {
    if(head == nullptr) return;
    if(KthElement == 1) deleteAtHead(head);
    int cnt = 0;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr) {
        cnt += 1;
        if(cnt == KthElement) {
            prev->next = temp->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

Node*
deleteAtValue(Node* head, int value) {
    if(head == nullptr) return head;
    if(head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = nullptr;

    while(temp->next != nullptr) {
        if(temp->data == value) {
            prev->next == temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

LENGTH
lengthOfSinglyLL(Node* head) {
    LENGTH length = 0;
    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
        length += 1;
    }
    return length;
}

void
traversal(Node* head) {
    Node* temp = head;
    while(temp->next != nullptr) {
        printf("%d ", temp->data);
        temp = temp->next ;
    }
}

int
searchInSinglyLL(Node* head, int val) {
    Node* temp = head;
    while(temp->next != nullptr) {
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}



int main() {
    //Node* node1 = new Node(2,nullptr);
    //std::cout << node1 ;
    //Node* node2 = new Node("String",nullptr);
    //node1->next = node2;

    std::vector<int>  vec = {1,2,3,4,5,6,7,8,9};
    auto head = convertArrToLL(vec);
    traversal(head);
    std::cout << "\n";
    //std::cout << "\n Length : " << lengthOfSinglyLL(head) << "\n";
    //std::cout << (bool)searchInSinglyLL(head,5) << std::endl;

    //deleteAtHead(head);
    //head = deleteAtTail(head);
    //deleteAtK(head,10);
    //head = deleteAtValue(head,9);
    head = insertionAtHead(2, head);
    head = insertionAtTail(10, head);
    head = insertAtK(head, 23, 5);
    head = insertBeforeValue(head, 22, 23);
    traversal(head);

}
