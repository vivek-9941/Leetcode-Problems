class MyCircularDeque {
    vector<int> a;
    int head;   // index of current front element
    int tail;   // index one past the current rear element
    int n;      // capacity
    int cnt;    // number of elements

public:
    MyCircularDeque(int k) : a(k), head(0), tail(0), n(k), cnt(0) {}

    bool insertFront(int value) {
        if (cnt == n) return false;
        head = (head - 1 + n) % n;
        a[head] = value;
        ++cnt;
        return true;
    }
    
    bool insertLast(int value) {
        if (cnt == n) return false;
        a[tail] = value;
        tail = (tail + 1) % n;
        ++cnt;
        return true;
    }

    bool deleteFront() {
        if (cnt == 0) return false;
        head = (head + 1) % n;
        --cnt;
        return true;
    }
    
    bool deleteLast() {
        if (cnt == 0) return false;
        tail = (tail - 1 + n) % n;
        --cnt;
        return true;
    }
    
    int getFront() {
        if (cnt == 0) return -1;
        return a[head];
    }
    
    int getRear() {
        if (cnt == 0) return -1;
        int idx = (tail - 1 + n) % n;
        return a[idx];
    }
    
    bool isEmpty() { return cnt == 0; }
    bool isFull()  { return cnt == n; }
};
