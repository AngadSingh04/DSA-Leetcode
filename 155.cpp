class MinStack {
public:
    int *arr;
    int to;
    int size = 100000;
    MinStack() {
        arr = new int[size];
        to = -1;

    }
    
    void push(int val) {
        if(to == size-1){
            return;
        }else{
            to++;
            arr[to] = val;
        }
        
    }
    
    void pop() {
        if(to == -1){
            return;
        }else{
            int ans = arr[to];
            to--;
        }
        
    }
    
    int top() {
        if(to == -1){
            return -1;
        }else{
            return arr[to];
        }
        
    }
    
    int getMin() {
        int min_v = INT_MAX;
        for(int i = 0; i <= to; i++){
            if(min_v > arr[i]){
                min_v = arr[i];
            }
        }
        return min_v;
        
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