class MyCircularQueue {
public:

    int* queue;
    int currSize,cap;
    int f, r;
    MyCircularQueue(int k) {
        queue = new int[k];
        cap = k;
        currSize = 0;
        r = -1;
        f = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        r = (r+1) % cap;
        queue[r] = value;
        currSize++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        currSize--;
        f = (f + 1)% cap;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return queue[f];
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        return queue[r];
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == cap;
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