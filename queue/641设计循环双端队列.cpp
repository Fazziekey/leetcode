// 设计实现双端队列。

// 实现 MyCircularDeque 类:

// MyCircularDeque(int k) ：构造函数,双端队列最大为 k 。
// boolean insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true ，否则返回 false 。
// boolean insertLast() ：将一个元素添加到双端队列尾部。如果操作成功返回 true ，否则返回 false 。
// boolean deleteFront() ：从双端队列头部删除一个元素。 如果操作成功返回 true ，否则返回 false 。
// boolean deleteLast() ：从双端队列尾部删除一个元素。如果操作成功返回 true ，否则返回 false 。
// int getFront() )：从双端队列头部获得一个元素。如果双端队列为空，返回 -1 。
// int getRear() ：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1 。
// boolean isEmpty() ：若双端队列为空，则返回 true ，否则返回 false  。
// boolean isFull() ：若双端队列满了，则返回 true ，否则返回 false 。

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/design-circular-deque
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        maxSize = k;    
    }
    
    bool insertFront(int value) {
        if((queue.size()) == maxSize){
            return false;
        }
        queue.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if((queue.size()) == maxSize){
            return false;
        }
        queue.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        queue.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        queue.pop_back();
        return true;
    }
    
    int getFront() {
        return queue.empty() ? -1 : queue.front();
    }
    
    int getRear() {
        return queue.empty() ? -1 : queue.back();
    }
    
    bool isEmpty() {
        return queue.empty();
    }
    
    bool isFull() {
        return queue.size() == maxSize;
    }
private:
    deque<int> queue;
    int maxSize;
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