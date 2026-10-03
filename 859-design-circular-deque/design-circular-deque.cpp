class MyCircularDeque {
public:

    int* dqueue;
    int r, f;
    int currSize;
    int cap;

    MyCircularDeque(int k) {
        cap = k;
        currSize = 0;
        r = 0;
        f = 0;
         
        dqueue = new int[cap];
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }

        f = (f - 1 + cap)%cap;
        dqueue[f] = value;

        currSize++;
        return true;

    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }

        dqueue[r] = value;
        r = (r+1)% cap;
        currSize++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        currSize--;
        f = (f + 1)% cap;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        currSize--;
        r = (r - 1 + cap)% cap;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return dqueue[f];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return dqueue[(r-1 + cap)% cap];
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */