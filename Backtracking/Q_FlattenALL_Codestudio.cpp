/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
#include<bits/stdc++.h>

Node* merge2list(Node* head1, Node* head2){
	Node* t1 = head1;
	Node* t2 = head2;
	Node* dummy = new Node(-1);
	Node* res = dummy;
	while(t1 != NULL && t2 != NULL){
		if(t1->data < t2->data){
			res->child = t1;
			res = t1;
			t1 = t1->child;
		}else{
			res->child = t2;
			res = t2;
			t2 = t2->child;
		}
		res->next = NULL;
	}
	if(t1) res->child = t1;
	else res->child = t2;
	if(dummy->child) dummy->child->next = nullptr;
	return dummy->child;
}


Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head->next == NULL){
		return head;
	}
	Node* mergedHead = flattenLinkedList(head->next);
	head = merge2list(head, mergedHead);
	return head;
}
