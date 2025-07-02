#include <iostream>

// 定义链表节点结构
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 合并两个有序链表
ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
    if (head1 == nullptr || head2 == nullptr) {
        return head1 == nullptr ? head2 : head1;
    }

    ListNode* head = head1->val <= head2->val ? head1 : head2;
    ListNode* cur1 = head->next;
    ListNode* cur2 = head == head1 ? head2 : head1;
    ListNode* pre = head;

    while (cur1 != nullptr && cur2 != nullptr) {
        if (cur1->val <= cur2->val) {
            // std::cout << cur1->val <<std::endl;
            pre->next = cur1;
            cur1 = cur1->next;
        } else {

            // std::cout << cur2->val <<std::endl;
            pre->next = cur2;
            cur2 = cur2->next;
        }
        pre = pre->next;
    }

    pre->next = cur1 != nullptr ? cur1 : cur2;
    return head;
}

// 辅助函数：打印链表
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // 创建两个链表
    ListNode* head1 = new ListNode(1, new ListNode(3, new ListNode(5)));
    ListNode* head2 = new ListNode(2, new ListNode(4, new ListNode(6)));

    std::cout << "List 1: ";
    printList(head1);
    std::cout << "List 2: ";
    printList(head2);

    // 合并链表
    ListNode* mergedHead = mergeTwoLists(head1, head2);

    std::cout << "Merged List: ";
    printList(mergedHead);

    // 释放链表内存（可选）
    while (mergedHead != nullptr) {
        ListNode* temp = mergedHead;
        mergedHead = mergedHead->next;
        delete temp;
    }

    return 0;
}
