/*****************************************************************/
/* simple list with three nodes                                  */
/*****************************************************************/
#include "stdio.h"
#include "stdlib.h"

struct node{
    int data;
    struct node * next;
};

                                                                      
/* 1-> 2-> 3 -> NULL */

struct node * create_node(int data){

	struct node * new_node = (struct node *)malloc(sizeof(int));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void print_list(struct node * head){
      if(head == NULL)
   	printf("list is empty");
      else{
	      while(head !=NULL){
	          printf("%d->", head->data);
		  head = head->next;
	      
	      }
              printf("NULL\n");
      }

}

/*driver function to create the linked list*/ 
int main(){
    struct node * head = NULL, *prev = NULL, *next = NULL;
    int i;
    for(i=1; i<=3;i++){
        next= create_node(i);
	if(prev != NULL){
	    prev->next = next;
	}else{
	    head = next;
	}
	prev = next;
    }

    print_list(head);
    return 0;
}
