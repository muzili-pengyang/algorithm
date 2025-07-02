#include <iostream>

// 定义链表节点结构
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 实现链表分区操作
ListNode* partition(ListNode* head, int x) {
    ListNode* leftHead = nullptr; // < x 的区域
    ListNode* leftTail = nullptr;
    ListNode* rightHead = nullptr; // >= x 的区域
    ListNode* rightTail = nullptr;
    ListNode* next = nullptr;

    while (head != nullptr) {
        next = head->next; // 保存下一个节点
        head->next = nullptr; // 断开当前节点的连接

        if (head->val < x) {
            if (leftHead == nullptr) {
                leftHead = head;
            } else {
                leftTail->next = head;
            }
            leftTail = head;
        } else {
            if (rightHead == nullptr) {
                rightHead = head;
            } else {
                rightTail->next = head;
            }
            rightTail = head;
        }

        head = next; // 移动到下一个节点
    }

    if (leftHead == nullptr) {
        return rightHead; // 如果没有小于 x 的节点，直接返回右分区的头节点
    }

    // 将左分区的尾部连接到右分区的头部
    leftTail->next = rightHead;
    return leftHead; // 返回左分区的头节点
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
    // 创建一个链表：1 -> 4 -> 3 -> 2 -> 5 -> 2
    ListNode* head = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2))))));

    std::cout << "Original List: ";
    printList(head);

    // 分区操作，x = 3
    ListNode* partitionedHead = partition(head, 3);

    std::cout << "Partitioned List: ";
    printList(partitionedHead);

    // 释放链表内存（可选）
    while (partitionedHead != nullptr) {
        ListNode* temp = partitionedHead;
        partitionedHead = partitionedHead->next;
        delete temp;
    }

    return 0;
}
