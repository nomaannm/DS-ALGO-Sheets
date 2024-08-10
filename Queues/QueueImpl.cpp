#include<iostream>

class Queue {
private:
    int q[1000]{};
    int start, end, size, capacity;
public:
    explicit Queue(const int cap = 1000) : start{-1}, end{-1}, size{0}, capacity{cap} {}
    ~Queue() = default;

    void push(int elem);
    int pop();
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] bool isFull() const;
};

void Queue::push(int elem) {
    if(isFull()) {
        std::cout << "Queue is full!\n" ;
        return ;
    }
    if(isEmpty()) {
        start = 0;
        end = 0;
    } else {
        end = (end+1) % capacity;
    }

    Queue::q[end] = elem;
    size += 1;
}

int Queue::pop() {
    if (isEmpty()) {
        std::cout << "Queue is empty!\n";
        return -1; // or any other error value
    }
    int elem = q[start];
    start = (start+1) % capacity;
    size--;

    if(isEmpty()) {
        start = -1;
        end = -1;
    }

    return elem;
}

bool Queue::isEmpty() const {
    return size == 0;
}

bool Queue::isFull() const {
    return size == capacity;
}

int main() {
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    std::cout << q.pop() << " " << q.pop();
}
