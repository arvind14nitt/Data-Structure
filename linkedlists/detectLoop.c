#include "stdio.h"
#include "stdlib.h"
struct ListNode{
	int val;
	struct ListNode* next;
};

//enum bool{false, true};
#define bool int
#define true 1
#define false 0

bool detectLoop(struct ListNode* head){
	//use fast and slow pointer, if they matches, there is cycle else not
	struct ListNode* fast_ptr = head, *slow_ptr = head;
	while(fast_ptr && fast_ptr->next){
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
		if(slow_ptr == fast_ptr){
			return true;
		}
	}
	return false;
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
	head->next->next->next->next = head->next;	
	//printList(head);
        //pass the node address and get a new list without node
	bool isLoop = detectLoop(head);
	//print the Linked List
	printf("loop %x\n", isLoop);
}
