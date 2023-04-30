#include "stdio.h"
#include "stdlib.h"
struct ListNode{
	int val;
	struct ListNode* next;
};

int freqOfInt(struct ListNode* head, int n){
	int count = 0;
	//dummy->1->2->3->4->NULL
	while(head){
		if(head->val == n){
			count++;
		}
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
	head->next->next->next = create_node(2);
	
	printList(head);
        //pass the node address and get a new list without node
	int c = freqOfInt(NULL,2);
	//print the Linked List
	printf("freq is %x\n",c);
}
