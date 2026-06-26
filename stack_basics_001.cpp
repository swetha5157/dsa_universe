#include<bits/stdc++.h>
using namespace std;


//implemeent stack using array
//why we use class for stack?
// we use class for stack because it allows us to encapsulate the data and functions related to the stack in a single unit.
class Stack{
    int *arr; // why * arr? because we want to create a dynamic array to store the elements of the stack. we can also use vector instead of array, but we are using array here to understand the concept of stack better.
    int top;
    int capacity;
    public:
    Stack(int size){
        arr = new int[size];
        capacity = size;
        top = -1;
    }
    void push(int x){
        if(top == capacity - 1){
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = x;
    }
    int pop(){
        if(top == -1){
            cout << "Stack underflow" << endl;
            return -1;
        }
        return arr[top--];
    }
    int peek(){
        if(top == -1){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    int size(){
        return top + 1;
    }
    bool isEmpty(){
        return top == -1;
    }
};

//implement two stacks in an array
class TwoStacks{
    int *arr;
    int top1, top2;
    int capacity;
    public:
    TwoStacks(int size){
        arr = new int[size];
        capacity = size;
        top1 = -1;
        top2 = capacity;
    }
    void push1(int x){
        if(top1 < top2 - 1){
            arr[++top1] = x;
        }else{
            cout << "Stack overflow" << endl;
            return;
        }
    }
    void push2(int x){
        if(top1 < top2 - 1){
            arr[--top2] = x;
        }else{
            cout << "Stack overflow" << endl;
            return;
        }
    }
    int pop1(){
        if(top1 >= 0){
            return arr[top1--];
        }else{
            cout << "Stack underflow" << endl;
            return -1;
        }
    }
    int pop2(){
        if(top2 < capacity){
            return arr[top2++];
        }else{
            cout << "Stack underflow" << endl;
            return -1;
        }
    }
};

int main(){

    // ---Stack using array---
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "Top element is: " << s.peek() << endl;
    cout << "Stack size is: " << s.size() << endl;
    cout << "Popped element is: " << s.pop() << endl;
    cout << "Top element is: " << s.peek() << endl;
    cout << "Stack size is: " << s.size() << endl;


    // ---Two stacks in an array--- 
    TwoStacks ts(5);
    ts.push1(1);
    ts.push1(2);
    ts.push2(3);
    ts.push2(4);
    cout << "Popped element from stack 1 is: " << ts.pop1() << endl;
    cout << "Popped element from stack 2 is: " << ts.pop2() << endl;
    cout << "Popped element from stack 1 is: " << ts.pop1() << endl;
    cout << "Popped element from stack 2 is: " << ts.pop2()
    << endl;
    return 0;

}