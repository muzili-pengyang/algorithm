#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Myqueue{
public:
    stack<int> in;
    stack<int> out;

    void inToOut(){
        if(out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
    }

    void push(int val){
        in.push(val);
        inToOut();
    }

    int pop(){
        inToOut();
        int ret=out.top();
        out.pop();
        return ret;
    }

    int peek(){
        inToOut();
        return out.top();
    }

    bool empty(){
        return in.empty() && out.empty();

    }

};


class MyStack {
public:
    queue<int> s;
    MyStack() {
        
    }
    
    void push(int x) {
        int n=s.size();
        s.push(x);
        for (int i=0;i<n;i++){
            s.push(s.front());
            s.pop();
        }
    }
    
    int pop() {
        int ret=s.front();
        s.pop();
        return ret;
    }
    
    int top() {
        return s.front();
    }
    
    bool empty() {
        return s.empty();
    }
};

class MinStack1 {
public:
    stack<int> data;
    stack<int> min;

    MinStack1() {
        
    }
    
    void push(int val) {
        data.push(val);
        if(min.empty() || val<=min.top()){
            min.push(val);
        }else{
            min.push(min.top());
        }

    }
    
    void pop() {
        data.pop();
        min.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min.top();
    }
};

class MinStack2 {
public:
    static const int max=3*1e4;
    int data[max];
    int min[max];
    int size=0;
    MinStack2() {
        
    }
    
    void push(int val) {
        data[size]=val;
        if(size==0 || val<=min[size-1]){
            min[size]=val;
        }else{
            min[size]=min[size-1];
        }
        size++;
    }
    
    void pop() {
        size--;
    }
    
    int top() {
        return data[size-1];
    }
    
    int getMin() {
        return min[size-1];
    }
};