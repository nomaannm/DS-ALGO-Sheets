class LRUCache {
public:
    class Node {
    public:
        int key, value;
        Node* prev;
        Node* next;
        Node(int key, int value) {
            this->key = key;
            this->value = value;
            next = NULL;
            prev = NULL;
        }
    };

    int capacity;
    unordered_map<int, Node*> mpp;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtHead(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) {
            return -1;
        } else {
            Node* currNode = mpp[key];
            deleteNode(currNode);
            insertAtHead(currNode);
            return currNode->value;
        }
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* currNode = mpp[key];
            currNode->value = value;
            deleteNode(currNode);
            insertAtHead(currNode);
        } else {
            Node* newNode = new Node(key, value);
            if (mpp.size() == capacity) {
                Node* toDlt = tail->prev;
                mpp.erase(toDlt->key);
                deleteNode(tail->prev);
                insertAtHead(newNode);
                mpp[key] = newNode;
                delete toDlt;
            } else {
                insertAtHead(newNode);
                mpp[key] = newNode;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
