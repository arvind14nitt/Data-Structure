#include "stdio.h"
#include "stdlib.h"
struct ListNode{
	int val;
	struct ListNode* next;
};

struct ListNode* deleteNodeByPointer(struct ListNode* head, struct ListNode* node){
	struct ListNode dummy;
	dummy.next = head;
	struct ListNode* prev = &dummy;
	//dummy->1->2->3->4->NULL
	while(head){
		if(head == node){
			//delete the head
			prev->next = head->next;
			free(node);
			head = prev->next;
		}else{
			prev = head;
			head = head->next;
		}
	}
        return dummy.next;
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
	head = deleteNodeByPointer(NULL,NULL);
	//print the Linked List
	printList(head);
}
