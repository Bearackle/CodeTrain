#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void push (ListNode** head, int data)
 {
    ListNode *newnode = new ListNode(data);
    newnode->next = *head;  //dereference pointer head
    *head = newnode;
 }

