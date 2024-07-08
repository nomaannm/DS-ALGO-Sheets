#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* prev;
    string data;
    Node* next;

    explicit Node(string& val) {
        this->data = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
    Node(string& val, Node* prev, Node* next) {
        this->data = val;
        this->prev = prev;
        this->next = next;
    }

    ~Node() {
        delete next;
        delete prev;
    }

};

pair<Node*,Node*>
convertArrtoDLL(vector<string>& arr) {
    if(arr.empty()) return {nullptr, nullptr};

    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(size_t i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], prev, nullptr);
        prev->next = temp;
        prev = prev->next;
    }
    Node* tail = prev;
    return {head, tail};

}

void
traversalWithHead(Node*& head ) {
    if(head == nullptr) return;
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    printf("\n");
}

void
traversalWithTail(Node*& tail) {
    if(tail == nullptr) return;
    Node* temp = tail;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    printf("\n");
}

void
deleteAtHead(Node*& head) {
    if(head == nullptr) return;
    if(head->next == nullptr) {
        delete head;
        return;
    }
    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;
}

void
deleteAtTail(Node*& tail) {
    if(tail == nullptr) return;
    if(tail->prev == nullptr) {
        delete tail;
        return;
    }
    Node* temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    temp->prev = nullptr;
    delete temp;
}

void
deleteKthElement(pair<Node*,Node*>& pair, int K) {
    int cnt = 0;
    Node* temp = pair.first;
    while(temp != nullptr) {
        cnt += 1;
        if(cnt == K) break;
        temp = temp->next;
    }

    Node* prev = temp->prev;
    Node* next = temp->next;

    if(prev == nullptr && next == nullptr) {
        delete temp;
    }
    else if(prev == nullptr) {
        deleteAtHead(temp);
    }
    else if(next == nullptr) {
        deleteAtTail(pair.second);
    }
    else {
        prev->next = temp->next;
        next->prev = temp->prev;
        temp->next = nullptr, temp->prev = nullptr;
        delete temp;
    }
}

void
deleteWithValue(pair<Node*,Node*>& pair, const string& value) {
    Node* temp = pair.first;
    while( temp != nullptr ) {
        if (temp->data == value) break;
        temp = temp->next;
    }
    Node* prev = temp->prev;
    Node* next = temp->next;

    if(prev == nullptr && next == nullptr) {
        delete temp;
    }
    else if(prev == nullptr) {
        deleteAtHead(pair.first);
    }
    else if(next == nullptr) {
        deleteAtTail(pair.second);
    }
    else {
        prev->next = temp->next;
        next->prev = temp->prev;
        temp->next = nullptr, temp->prev = nullptr;
        delete temp;
    }
}

void
deleteCertainNode(Node* temp) {
    Node* prev = temp->prev;
    Node* next = temp->next;
    if(temp->next == nullptr) {
        prev->next = temp->prev = nullptr;
        delete temp;
        return;
    }
    prev->next = next;
    next->prev = prev;
    temp->next = temp->prev = nullptr;
    delete temp;
}

void
insertionBeforeHead(Node*& head, string val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void
insertionBeforeTail(Node*& head, string val) {
    Node* newNode = new Node(val);
    Node* temp = head;
    while(temp->next->next != nullptr) {
        temp = temp->next;
    }
    Node* tail = temp->next;
    newNode->next = tail;
    tail->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void
insertionBeforeKthElement(Node*& head, string val, int K) {
    if(K == 1) insertionBeforeHead(head,val);
    Node* newNode = new Node(val);
    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr) {
        cnt += 1;
        if(cnt == K) {
            break;
        }
        temp = temp->next;

    }
    Node* prev = temp->prev;
    newNode->next = temp;
    newNode->prev = prev;
    prev->next = newNode;
    temp->prev = newNode;


}

void
insertionBeforeCertainNode(Node*& temp, string val) {
    Node* back = temp->prev;
    Node* newNode = new Node(val);
    newNode->next = temp;
    newNode->prev = back;
    back->next = newNode;
    temp->prev = newNode;
}





int main() {
    vector<string> arr = {"C++","Java","Rust","GOlang","Python"};
    pair<Node*, Node*> pair = convertArrtoDLL(arr);
    traversalWithHead(pair.first);
    traversalWithTail(pair.second);

    /*
    printf("\nDeletion Operations:\n");
    deleteAtHead(pair.first);
    traversalWithHead(pair.first);
    printf("\n");
    deleteAtTail(pair.second);
    traversalWithTail(pair.second);
    deleteKthElement(pair,3);
    traversalWithHead(pair.first);
    */

    deleteCertainNode(pair.first->next->next);
    traversalWithHead(pair.first);

    deleteWithValue(pair,"GOlang");
    traversalWithHead(pair.first);

    insertionBeforeHead(pair.first,"Obj-C");
    traversalWithHead(pair.first);
    traversalWithTail(pair.second);

    insertionBeforeTail(pair.first,"Swift");
    traversalWithHead(pair.first);
    traversalWithTail(pair.second);

    insertionBeforeKthElement(pair.first, "Kotlin", 2);
    traversalWithHead(pair.first);
    traversalWithTail(pair.second);

    insertionBeforeCertainNode(pair.first->next->next, "Scala");
    traversalWithHead(pair.first);
    traversalWithTail(pair.second);


}
