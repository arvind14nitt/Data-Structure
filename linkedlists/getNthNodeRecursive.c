#include "stdio.h"
#include "stdlib.h"
struct ListNode{
	int val;
	struct ListNode* next;
};

//return the value at nth node
int getNthNode(struct ListNode* head, int n){
/*    node 1 = head 1
    node 2 = head->next 2
    node 3 = 3
    we are already 1 for  head*/

    if(n ==1){
	return head->val;
    }
    else return getNthNode(head->next, n-1);
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
	int len = getNthNode(head, 2);
	printf("%x\n",len);	
}
