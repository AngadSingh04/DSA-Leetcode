class MinStack {
public:
    int *arr;
    int size = 1000;
    int to;
    MinStack() {
        arr = new int[size];
        to = -1;
    }
    
    void push(int val) {
        if(to == size-1){
            return;
        }
        to++;
        arr[to] = val;
    }
    
    void pop() {
        if(to == -1){
            return;
        }
        int ans = arr[to];
        to--;
    }
    
    int top() {
        if(to == -1){
            return -1;
        }
        return arr[to];
    }
    
    int getMin() {
        int minE = INT_MAX;
        for(int i = 0; i <= to; i++){
            if(minE > arr[i]){
                minE = arr[i];
            }
        }
        return minE;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */