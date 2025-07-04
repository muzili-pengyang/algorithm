#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Queue1{
private:
    queue<int> queue;

public:
    bool isEmpty(){
        return queue.empty();
    }

    void offer(int num){
        queue.push(num);

    }

    int poll(){
        if (queue.empty()){
            throw out_of_range("Queue is empty!");
        }
        int front=queue.front();
        queue.pop();
        return front;
    }

    int peek(){
        if (queue.empty()){
            throw out_of_range("Queue is empty!");
        }
        return queue.front();
    }

    int size(){
        return queue.size();
    }

};

class Queue2{
public:
    int* que;
    int l;
    int r;

    Queue2(int n){
        que=new int[n];
        l=0;
        r=0;
    }

    bool isEmpty(){
        return l==r;
    }

    void offer(int num){
        que[r++]=num;
    }

    int poll(){
        return que[l++];
    }

    int head(){
        return que[l];
    }

    int tail(){
        return que[r-1];
    }

    int size(){
        return r-l;
    }

};

class Stack2{
public:
    int* stack2;
    int size;
    Stack2(int n){
        stack2=new int[n];
        size=0;
    }

    void push(int num){
        stack2[size++]=num;
    }

    bool isEmpty(){
        return size==0;
    }    

    int top(){
        return stack2[size-1];
    }

    void pop(){
        size--;
    }

    int getsize(){
        return size;
    }
};

int main(){
    //队列
    // //Queue1 q;
    // Queue2 q(2);

    // q.offer(1);
    // q.offer(2);
    // q.offer(3);

    // // cout<<"Queue size:"<< q.size() <<endl;
    // // cout<<"Front element:"<<q.peek() <<endl;
    // // cout<<"Poll element:"<<q.poll() <<endl;
    // // cout<<"Queue size after poll:"<<q.size() <<endl;

    // cout<<"Queue size:"<< q.size() <<endl;
    // cout<<"Head element:"<<q.head() <<endl;
    // cout<< "Tail element:"<<q.tail() <<endl;
    // cout<<"Poll element:"<<q.poll() <<endl;
    // cout<<"Queue size after poll:"<<q.size() <<endl;

    //栈
    // stack<int> stack1;
    // stack1.push(1);
    // stack1.push(2);
    // stack1.push(3);

    // cout<<"stack1 size:"<< stack1.size()<<endl;
    // while(!stack1.empty()){
    //     cout<<"stack1 top:"<<stack1.top()<<endl;
    //     stack1.pop();
    // }
    // // stack1.swap(stack2)  //交换两个栈的内容

    Stack2 s(5);
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.getsize() <<" ";
    cout<<s.top()<<endl;
    
    while(!s.isEmpty()){
        cout<<" top:"<<s.top()<<endl;
        s.pop();
    }
    
    return 0;

}