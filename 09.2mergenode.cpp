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

// 实现两个链表数字相加
ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {
    ListNode* ans = nullptr; // 用于存储结果链表的头节点
    ListNode* cur = nullptr; // 用于构建结果链表的当前节点
    int carry = 0; // 进位

    for (int sum, val; // 声明变量
         h1 != nullptr || h2 != nullptr; // 终止条件
         h1 = (h1 == nullptr ? nullptr : h1->next), // 每一步 h1 的跳转
         h2 = (h2 == nullptr ? nullptr : h2->next) // 每一步 h2 的跳转
        ) {
        // 计算当前位的和，包括进位
        sum = (h1 == nullptr ? 0 : h1->val) + (h2 == nullptr ? 0 : h2->val) + carry;
        val = sum % 10; // 当前位的值
        carry = sum / 10; // 更新进位

        // 构建结果链表
        if (ans == nullptr) {
            ans = new ListNode(val);
            cur = ans;
        } else {
            cur->next = new ListNode(val);
            cur = cur->next;
        }
    }

    // 如果最后还有进位，追加一个新节点
    if (carry == 1) {
        cur->next = new ListNode(1);
    }

    return ans;
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
