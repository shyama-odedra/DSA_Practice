class MyCircularDeque {
private:
    vector<int> v;
    int front;
    int rear;
    int capacity;
    int size;

public:
    MyCircularDeque(int k) {
        v.resize(k);
        capacity = k;
        front = 0;
        rear = capacity - 1;
        size = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        v[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        v[rear] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return v[front];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return v[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};