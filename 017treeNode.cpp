#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v):val(v),left(nullptr),right(nullptr){}
};

//递归实现三种遍历
void preOrder1(TreeNode* head){
    if(head==nullptr){
        return;
    }

    cout<<head->val <<" ";
    preOrder1(head->left);
    preOrder1(head->right);
}

//非递归实现先序
void preOrder2(TreeNode* head){
    if(head!=nullptr){
        stack<TreeNode*> stack;
        stack.push(head);

        while(!stack.empty()){
            head=stack.top();
            stack.pop();
            cout<< head->val <<" ";

            if(head->right !=nullptr){
                stack.push(head->right);
            }

             if(head->left !=nullptr){
                stack.push(head->left);
            }

        }
        cout<<endl;
    }
}

//非递归实现中序
void inOrder(TreeNode* head){
    if(head!=nullptr){
       stack<TreeNode*> stack;
       while(!stack.empty() || head!=nullptr){
            while(head!=nullptr){
                stack.push(head);
                head=head->left;
            }

            head=stack.top();
            stack.pop();
            cout<< head->val<<" ";

            head=head->right;

        }
        cout<<endl;
    }
}

//非递归实现后序
void posOrder1(TreeNode* head){
    if(head!=nullptr){
        stack<TreeNode*> stacks;
        stack<TreeNode*> collect;
        stacks.push(head);

        while(!stacks.empty()){
            head=stacks.top();
            stacks.pop();
            collect.push(head);

            if(head->left!=nullptr){
                stacks.push(head->left);
            }

            if(head->right!=nullptr){
                stacks.push(head->right);
            }

        }

        while(!collect.empty()){
            cout<< collect.top()->val<<" ";
            collect.pop();
        }

        cout<<endl;
    }
}

void posOrder2(TreeNode* head){
    if(head!=nullptr){
        stack<TreeNode*> stack;
        stack.push(head);
        TreeNode* pre=nullptr;
        
        while(!stack.empty()){
            TreeNode* cur;
            if(cur->left!=nullptr && cur->left!=pre && cur->right!=pre){
                stack.push(cur->left);
            }else if(cur->right!=nullptr && cur->right!=pre){
                stack.push(cur->right);
            }else{
                cout<<cur->val<<" ";
                pre=stack.top();
                stack.pop();
            }
        }
        cout<<endl;
    }
}