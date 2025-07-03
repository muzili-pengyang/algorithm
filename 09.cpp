#include <iostream>

// 定义链表节点结构
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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
    // 创建两个链表表示的数字
    ListNode* h1 = new ListNode(2, new ListNode(4, new ListNode(3))); // 表示数字 342
    ListNode* h2 = new ListNode(5, new ListNode(6, new ListNode(4))); // 表示数字 465

    std::cout << "List 1: ";
    printList(h1);
    std::cout << "List 2: ";
    printList(h2);

    // 计算两个链表数字的和
    ListNode* result = addTwoNumbers(h1, h2);

    std::cout << "Sum List: ";
    printList(result);

    // 释放链表内存（可选）
    while (h1 != nullptr) {
        ListNode* temp = h1;
        h1 = h1->next;
        delete temp;
    }
    while (h2 != nullptr) {
        ListNode* temp = h2;
        h2 = h2->next;
        delete temp;
    }
    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
