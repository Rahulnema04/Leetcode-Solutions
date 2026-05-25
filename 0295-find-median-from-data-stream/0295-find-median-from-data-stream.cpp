class MedianFinder {
public:
    priority_queue<int> leftMaxHeap; // smaller half
    priority_queue<int, vector<int>, greater<int>> rightMinHeap; // larger half

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        leftMaxHeap.push(num);

        rightMinHeap.push(leftMaxHeap.top());
        leftMaxHeap.pop();

        if (rightMinHeap.size() > leftMaxHeap.size()) {
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }
    
    double findMedian() {

        if (leftMaxHeap.size() > rightMinHeap.size()) {
            return leftMaxHeap.top();
        }

        return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */