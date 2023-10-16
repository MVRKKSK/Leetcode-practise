class MyStack {
public:
    queue<int> kyu1;
    queue<int> kyu2;
    int n;
    MyStack() {
        n = 0;
    }
    void push(int x) {
       kyu2.push(x);
       n++;
       while(!kyu1.empty()){
           kyu2.push(kyu1.front());
           kyu1.pop();
       }
       queue<int> temp = kyu1;
       kyu1 = kyu2;
       kyu2 = temp;
    } 
    int pop() {
        if(n>0){
            int ele = kyu1.front();
            kyu1.pop();
            n--;
            return ele;
        }
        return -1;
    } 
    int top() {
        if(n>0){
            int ele = kyu1.front();
            return ele;
        }
        return -1;
    }
    bool empty() {
        return n==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */