#include <iostream>

using namespace std;

class Listnode{
public:
    int val;
    Listnode* next;
    Listnode(int val) : val(val), next(nullptr) {}

    Listnode (int val, Listnode* next):val(val),next(next){}
};

class Doublenode{
    public:
        int val;
        Doublenode* last;
        Doublenode* next;

        Doublenode(int v) :val(v), last(nullptr),next(nullptr) {}
};


static Listnode* reverselist(Listnode* head){
    Listnode* pre=nullptr;
    Listnode* next=nullptr;

    while (head!= nullptr){
        next=head->next;
        head->next=pre;
        pre=head;
        head=next;
    }
    return pre;
}

static Doublenode* reverseDoublenode(Doublenode* head){
    Doublenode* pre=nullptr;
    Doublenode* next=nullptr;

    while(head!= nullptr){
        next=head->next;
        head->next=pre;
        head->last=next;
        pre=head;
        head=next;
    }
    return pre;

}

// 辅助函数：打印链表
void printList(Listnode* head){
    Listnode* current=head;
    while(current!=nullptr){
        cout<< current ->val<<"->";
        current=current->next;
    }
    cout << "nullptr" <<endl;
}

int lengthDoublenode(Doublenode* head){
    int ans=0;
    Doublenode* cur=head;
    while(cur!=nullptr){
        ans++;
        cur=cur->next;
    }
    return ans;
}
void printDoublenode(Doublenode* head){
    Doublenode* cur=head;
    int length=lengthDoublenode(cur);
    cout <<"nullptr <- ";
    while(cur!=nullptr){
        if(length>1){
            cout<< cur->val <<"<=>";
        }else{
            cout<< cur->val ;
        }
        cur=cur->next;
        length--;
    }
    cout <<"->nullptr"<<endl;
}

Listnode* mergeTwolist(Listnode* head1, Listnode* head2){
    if(head1==nullptr || head2==nullptr){
        return head1==nullptr ? head2:head1;
    }

    Listnode* head=head1->val< head2->val? head1:head2;
    Listnode* cur1=head;
    Listnode* cur2=head==head1 ? head2:head1;
    Listnode* pre=head;

    while(cur1!=nullptr && cur2!=nullptr){
        if(cur1->val <= cur2->val){
            pre->next=cur1;
            cur1=cur1->next;
        }else{
            pre->next=cur2;
            cur2=cur2->next;
        }
        pre=pre->next;
    }
    pre->next= cur1==nullptr? cur2:cur1;
    return head;
}

// 主函数
int main() {
    // 创建链表 1 -> 2 -> 3 -> nullptr
    Listnode* head1 = new Listnode(1, new Listnode(2, new Listnode(3)));
    Listnode* head3 = new Listnode(4, new Listnode(5, new Listnode(6)));

    // Doublenode* head2=new Doublenode(7);
    // head2->next= new Doublenode(8);
    // head2->last=nullptr;
    // head2->next->next=new Doublenode(9);
    // head2->next->last=head2->next;

    cout<< "合并链表：";
    Listnode* mergehead=mergeTwolist(head1,head3);
    printList(mergehead);
    cout<<endl;

    // 打印链表
    std::cout << "链表内容: ";
    printList(head1);
    printList(head3);
    // printDoublenode(head2);

    // cout<< "反转链表：";
    // Listnode* reversehead1=reverselist(head1);
    // Doublenode* reversehead2=reverseDoublenode(head2);
    // printList(reversehead1);
    // printDoublenode(reversehead2);

    

    // 释放链表内存
    Listnode* current = mergehead;
    // Doublenode* cur=head2;

    while (current != nullptr) {
        Listnode* temp = current;
        current = current->next;
        delete temp;
    }

    // while (cur != nullptr) {
    //     Doublenode* temp = cur;
    //     cur = cur->next;
    //     delete temp;
    // }

}