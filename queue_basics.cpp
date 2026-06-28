#include<bits/stdc++.h>
using namespace std;

// queue using array
class Queue{
    int *arr;
    int front, rear, capacity;
    public:
    Queue(int size){
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
    }
    void enqueue(int x){
        if(rear == capacity - 1){
            cout << "Queue overflow" << endl;
            return;
        }
        arr[++rear] = x;
    }
    int dequeue(){
        if(front > rear){
            cout << "Queue underflow" << endl;
            return -1;
        }
        return arr[front++];
    }
    int peek(){
        if(front > rear){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    int size(){
        return rear - front + 1;
    }
    bool isEmpty(){
        return front > rear;
    }
    int getRear(){
        if(front > rear){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }
};


// circular queue using array
class CircularQueue{
    int *arr;
    int front, rear, capacity;
    public:
    CircularQueue(int size){
        arr = new int[size];
        capacity = size;
        front = -1;
        rear = -1;
    }
    void enqueue(int x){
        if((rear + 1) % capacity == front){
            cout << "Queue overflow" << endl;
            return;
        }
        if(front == -1)
            front = 0;
        rear = (rear + 1) % capacity;
        arr[rear] = x;
    }
    int dequeue(){
        if(front == -1){
            cout << "Queue underflow" << endl;
            return -1;
        }
        int x = arr[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }else{
            front = (front + 1) % capacity;
        }
        return x;
    }
    int peek(){
        if(front == -1){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    int size(){
        if(front == -1)
            return 0;
        if(rear >= front)
            return rear - front + 1;
        return capacity - front + rear + 1;
    }
    bool isEmpty(){
        return front == -1;
    }
    int getRear(){
        if(front == -1){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }
};

class myQueue {
    stack<int>ip,op;
  public:
    myQueue() {
        // Initialize your data members
    }

    void enqueue(int x) {
        // Implement enqueue operation
         ip.push(x);
    }

    void dequeue() {
        // Implement dequeue operation
        if(front()==-1) return;
        op.pop();
    }

    int front() {
        if(op.empty()){
            while(!ip.empty()){
                op.push(ip.top());ip.pop();
            }
        }
        return op.empty()?-1:op.top();
    }

    int size() {
        // Implement size operation
        return op.size()+ip.size();
    }

    bool isEmpty() {
        // Implement isEmpty operation
        return op.empty() && ip.empty();
    }

    void display() {
        // Implement display operation
        stack<int>temp1 = ip,temp2 = op;
        while(!temp2.empty()){
            cout<<temp2.top()<<" ";
            temp2.pop();
        }
        vector<int>v;
        while(!temp1.empty()){
            v.push_back(temp1.top());
            temp1.pop();
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
};

// stack using queue
class myStack{
    queue<int>q;

    public:
    myStack() {
        // Initialize your data members
    }

    void push(int x) {
        // Implement push operation
        q.push(x);
        int n = q.size();
        for(int i=0;i<n-1;i++){
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        // Implement pop operation
        if(q.empty()) return;
        q.pop();
    }
    int top() {
        // Implement top operation
        if(q.empty()) return -1;
        return q.front();
    }

    bool isEmpty() {
        // Implement isEmpty operation
        return q.empty();
    }

    int size() {
        // Implement size operation
        return q.size();
    }

    void display() {
        // Implement display operation
        queue<int>temp = q;
        while(!temp.empty()){
            cout<<temp.front()<<" ";
            temp.pop();
        }
        cout<<endl;
    }
};

// reverse a queue using recursion
// tc: O(n), sc: O(n)(recursion stack)
 void reverseQueue(queue<int> &q) {
        if(q.empty()) return;
        // code here
        int ele= q.front();q.pop();
        reverseQueue(q);
        q.push(ele);
    }

// reverse first k elements of a queue
// tc: O(n), sc: O(k)
void reverseKElements(queue<int> &q, int k) {
    // steps:
    // 1. pop first k elements from queue and push them into stack
    // 2. pop all elements from stack and push them back into queue
    int n = q.size();
    if(n<k || q.empty() || k<=0) return;
    stack<int> st;
    for(int i=0;i<k;i++){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    // 3. pop n-k elements from queue and push them back into queue
    int n = q.size();
    for(int i=0;i<n-k;i++){
        q.push(q.front());
        q.pop();
    }
}
int main(){
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Front element is: " << q.peek() << endl;
    cout << "Queue size is: " << q.size() << endl;
    cout << "Rear element is: " << q.getRear() << endl;
    q.dequeue();
    cout << "Front element is: " << q.peek() << endl;
    cout << "Queue size is: " << q.size() << endl;
    cout << "Rear element is: " << q.getRear() << endl;
    q.enqueue(4);
    q.enqueue(5);
    cout << "Front element is: " << q.peek() << endl;
    cout << "Queue size is: " << q.size() << endl;
    cout << "Rear element is: " << q.getRear() << endl;
    cout<< "Dequeued element: " << q.dequeue() << endl;
    q.enqueue(6);
    cout << "Front element is: " << q.peek() << endl;
    cout << "Queue size is: " << q.size() << endl;
    cout << "Rear element is: " << q.getRear() << endl;

    cout << "------------------------" << endl;
    // circular queue
    CircularQueue cq(5);
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cout << "Front element is: " << cq.peek() << endl;
    cout << "Queue size is: " << cq.size() << endl;
    cout << "Rear element is: " << cq.getRear() << endl;
    cq.dequeue();
    cout << "Front element is: " << cq.peek() << endl;
    cout << "Queue size is: " << cq.size() << endl;
    cout << "Rear element is: " << cq.getRear() << endl;
    cq.enqueue(4);
    cq.enqueue(5);
    cout << "Front element is: " << cq.peek() << endl;
    cout << "Queue size is: " << cq.size() << endl;
    cout << "Rear element is: " << cq.getRear() << endl;
    cq.enqueue(6);
    cout << "Front element is: " << cq.peek() << endl;
    cout << "Queue size is: " << cq.size() << endl;
    cout << "Rear element is: " << cq.getRear() << endl;
    cq.dequeue();
    cout << "Front element is: " << cq.peek() << endl;
    cq.enqueue(7);
    cout << "Front element is: " << cq.peek() << endl;
    cout << "Queue size is: " << cq.size() << endl;
    cout << "Rear element is: " << cq.getRear() << endl;

    // for(int i=0; i<5; i++){
    //     cout << "Dequeued element: " << cq.dequeue() << endl;
    // }
    cout<<endl;


    // queue using stack
    myQueue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    cout << "Front element is: " << q1.front() << endl;
    cout << "Queue size is: " << q1.size() << endl;
    cout << "Is queue empty? " << (q1.isEmpty() ? "Yes" : "No") << endl;
    q1.dequeue();
    cout << "Front element is: " << q1.front() << endl;
    cout << "Queue size is: " << q1.size() << endl;
    cout << "Is queue empty? " << (q1.isEmpty() ? "Yes" : "No") << endl;
    

    cout << "------------------------" << endl;

    //stack using queue

    myStack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << "Top element is: " << s1.top() << endl;
    cout << "Stack size is: " << s1.size() << endl;
    s1.pop();
    cout << "Top element is: " << s1.top() << endl;
    s1.display();
    cout << "Stack size is: " << s1.size() << endl;

    // reverse a queue using recursion
    queue<int> q2;
    q2.push(1);
    q2.push(2);
    q2.push(3);
    cout << "Original queue: ";
    while(!q2.empty()){
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl;
    reverseQueue(q2);
    cout << "Reversed queue: ";
    while(!q2.empty()){
        cout << q2.front() << " ";
        q2.pop();
    }
    cout << endl;

    // reverse first k elements of a queue
    queue<int> q3;
    q3.push(1);
    q3.push(2);
    q3.push(3);
    q3.push(4);
    q3.push(5);
    int k = 3;
    cout << "Original queue: ";
    while(!q3.empty()){
        cout << q3.front() << " ";
        q3.pop();
    }
    cout << endl;
    reverseKElements(q3, k);
    cout << "Queue after reversing first " << k << " elements: ";
    while(!q3.empty()){
        cout << q3.front() << " ";
        q3.pop();
    }
    cout << endl;


    return 0;
}