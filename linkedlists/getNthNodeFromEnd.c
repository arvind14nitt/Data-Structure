#include "stdio.h"
#include "stdlib.h"
struct ListNode{
	int val;
	struct ListNode* next;
};

struct ListNode* nthNodeFromEnd(struct ListNode* head, int n){
	int count = 1;
	struct ListNode* curr = head;
        while(curr){
		//reach nth node from begining
		if(count == n){
			break;
		}
		count = count+1;
		curr = curr->next;
	}
	//now curr hold the nth node from begining
	//now move head and curr by 1 each till curr reaches the end then
	//head reaches the nth from end.
	while(curr->next){
		head = head->next;
		curr = curr->next;
	}
	return head;
}


struct ListNode* create_node(int val)
{
	struct ListNode* node =  (struct ListNode*)malloc(sizeof(struct ListNode));
	node->val = val;
	node->next = NULL;
	return node;
}

int main()
{
//create the LL
	struct ListNode* head;
	head = create_node(1);
	head->next = create_node(2);
	head->next->next = create_node(3);
	head->next->next->next = create_node(4);
	head->next->next->next->next = create_node(5);


        //find mid of the LL
	struct ListNode* nth = nthNodeFromEnd(head, 3);
	printf("%x\n",nth->val);	
}
