#include "stdio.h"
#include "stdlib.h"
struct ListNode{
	int val;
	struct ListNode* next;
};

struct ListNode* reverseLL(struct ListNode* head){
	struct ListNode* temp, *result = NULL;
	struct ListNode* curr  = head;
	//To reverse, add nodes at the head

	while(curr){
		//Hold the node attached to the head
		temp = curr->next;
		//add the curr node to the head result
		curr->next = result;
		result = curr;
		curr = temp;

	}
	return result;
}

struct ListNode* create_node(int val){
	struct ListNode* node =  (struct ListNode*)malloc(sizeof(struct ListNode));
	node->val = val;
	node->next = NULL;
	return node;
}

void printList(struct ListNode* head){
	while(head){
                if(head->next == NULL){
                        printf("%x\n",head->val);
                }else{
                	printf("%x->", head->val);
		}
                head = head->next;
        }
}

int main(){
//create the LL
	struct ListNode* head;
	head = create_node(1);
	head->next = create_node(2);
	head->next->next = create_node(3);
	head->next->next->next = create_node(4);
	
	printList(head);
        //pass the node address and get a new list without node
	head = reverseLL(head);
	//print the Linked List
	printList(head);
}
