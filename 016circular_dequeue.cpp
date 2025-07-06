#include <iostream>
#include <deque>

using namespace std;

class MyCircularDeque1{
public:
    deque<int> deque;
    int size;
    int limit;

    MyCircularDeque1(int k):size(0),limit(k) {}

    bool insertFont(int val){
        if(isFull()){
            return false;
        }else{
            deque.push_front(val);
            size++;
            return true;
        }
    }

    bool insertLast(int val){
        if(isFull()){
            return false;
        }else{
            deque.push_back(val);
            size++;
            return true;
        }
    }

    bool deleteFront(){
        if(isEmpty()){
            return false;
        }else{
            deque.pop_front();
            size--;
            return true;
        }
    }

    bool deleteLast(){
        if(isEmpty()){
            return false;
        }else{
            deque.pop_back();
            size--;
            return true;
        }
    }

    int getFront(){
        if(isEmpty()){
            return -1;
        }else{
            return deque.front();

        }
    }

     int getRear(){
        if(isEmpty()){
            return -1;
        }else{
            return deque.back();
            
        }
    }

    bool isEmpty(){
        return size==0;
    }

    bool isFull(){
        return size==limit;
    }

};


class MyCircularDeque2 {
public:
    int* deque;
    int l,r,size,limit;
    MyCircularDeque2(int k) {
        deque=new int[k];
        l=r=0;
        size=0;
        limit=k;
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        if(isEmpty()){
            l=r=0;
        }else{
            l = l==0 ? (limit-1):(l-1);
        }
        deque[l]=value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        if(isEmpty()){
            l=r=0;
        }else{
            r= (r==limit-1) ? 0:(r+1);
        }
        deque[r]=value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }else{
            l= l==limit-1 ? 0: (l+1);
            size--;
            return true;
        }
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }else{
           r= r==0? (limit-1):(r-1);
            size--;
            return true;
        }
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }else{
            return deque[l];
        }
    }
    
    int getRear() {
         if(isEmpty()){
            return -1;
        }else{
            return deque[r];
        }
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==limit;
    }
};
