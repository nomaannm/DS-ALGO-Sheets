struct Node{
    string data;
    Node* next;
    Node* prev;
    Node() : data(""), next(nullptr), prev(nullptr) {}
    Node(string x) : data(std::move(x)), next(nullptr), prev(nullptr){}
    Node(string x, Node* next, Node* random) : data(std::move(x)), next(next), prev(random) {}
};
class BrowserHistory {
    Node* currentpage;
public:
    BrowserHistory(string homepage) {
        currentpage = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newpage = new Node(url);
        currentpage->next = newpage;
        newpage->prev = currentpage;
        currentpage = newpage;
    }
    
    string back(int steps) {
        while(steps){
            if(currentpage->prev) currentpage = currentpage->prev;
            else break;
            steps -= 1;
        }
        return currentpage->data;
    }
    
    string forward(int steps) {
        while(steps){
            if(currentpage->next) currentpage = currentpage->next;
            else break;
            steps -= 1;
        }
        return currentpage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
