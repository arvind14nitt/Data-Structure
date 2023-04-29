#include "stdio.h"
#include "stdlib.h"
struct ListNode{
	int val;
	struct ListNode* next;
};

int lengthLL(struct ListNode* head){
	int count = 0;
	if(head == NULL){
		return count;
	}
	while(head){
		count++;
		head = head->next;
	}
	return count;
}

struct ListNode* create_node(int val){
	struct ListNode* node =  (struct ListNode*)malloc(sizeof(struct ListNode));
	node->val = val;
	node->next = NULL;
	return node;
}

int main(){
//create the LL
	struct ListNode* head;
	head = create_node(1);
	head->next = create_node(2);
	head->next->next = create_node(3);
	head->next->next->next = create_node(4);


        //find length of the LL
	int len = lengthLL(head);
	printf("%x\n",len);	
}
