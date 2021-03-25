# include <stack>
class CQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    CQueue() {

    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        if(stack1.empty())
            return -1;
        while(!stack1.empty()){
            int temp = stack1.top();
            stack1.pop();
            stack2.push(temp);
        }
        int temp = stack2.top();
        stack2.pop();
        while(!stack2.empty()){
            int tmp = stack2.top();
            stack2.pop();
            stack1.push(tmp); 
        }
        return temp;
    }
};
