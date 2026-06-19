class MyCircularQueue {
public:
    vector<int> container;
    int front;
    int back;
    int size;
    int k;

    MyCircularQueue(int k) {
        container.assign(k, 0);
        front = 0;
        back = -1;
        size = 0;
        this->k = k;
    }
    
    bool enQueue(int value) {
        if(size == k) return false;
        back = (back+1) % k;
        container[back] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size == 0) return false;
        front = (front+1) % k;
        size--;
        return true;
    }
    
    int Front() {
        if(size == 0) return -1;
        return container[front];
    }
    
    int Rear() {
        if(size == 0) return -1;
        return container[back];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */