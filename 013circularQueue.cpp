#include <iostream>
 using namespace std;

 class CircularQueue{
    int* queue;
    int l,r,size,limit;

    CircularQueue(int k){
        queue=new int [k];
        l=r=size=0;
        limit=k;
    }

    bool enQueue(int val){
        if(isFull()){
            return false;
        }else{
            queue[r]=val;
            r= r==limit-1 ? 0:(r+1);
            size++;
            return true;
        }
    }

    bool dequeue(){
        if(isEmpty()){
            return false;
        }else{
            l = l==limit-1 ? 0: (l+1);
            size--;
            return true;
        }

    }

    int front(){
        if(isEmpty()){
            return -1;
        }else{
            return queue[l];
        }
    }

    int rear(){
        if(isEmpty()){
            return -1;
        }else{
            int last= r==0 ? (limit-1) :(r-1);
            return queue[last];
        }
    }

    bool isEmpty(){
        return size==0;
    }
    bool isFull(){
        return size==limit;
    }
 };

 