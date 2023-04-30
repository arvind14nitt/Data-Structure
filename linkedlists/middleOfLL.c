#include "stdio.h"
#include "stdlib.h"
struct ListNode{
	int val;
	struct ListNode* next;
};

//when fast pointer reaches the end, slow pointer reaches the mid
struct ListNode* getMiddleNode(struct ListNode* head)
{
	struct ListNode* mid = head;
	//when there is last node, we get head->next == NULL
	while(head && head->next){
		mid = mid->next;
		head = head->next->next;
	}	
	return mid;
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
	struct ListNode* mid = getMiddleNode(head);
	printf("%x\n",mid->val);	
}
