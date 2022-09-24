/*Inserting a node at the front, at the end and at the given position in a given linked list*/

#include "stdio.h"
#include "stdlib.h"

/* data type for the node */
struct node{
   int data;
   struct node * next;
};

void printList(struct node* head)
{
    while(head)
    {
       printf("%d->",head->data);
       head = head->next;
    }
    printf("NULL\n");
}


struct node* create_node(int data)
{
   struct node* new_node =(struct node *)malloc(sizeof(struct node));
   new_node->data = data;
   new_node->next = NULL;
   return new_node;
}

//Delete a particular node from the Linked List
void deleteNode(struct node** head, int node_data)
{
    struct node* temp, *prev_node;
    temp = *head;//temp will now hold the address of first node
    prev_node = temp;
    //Iterate towards the node, find its previous node
    while(temp)
    {
       if(temp->data == node_data)
       {
	  prev_node->next = temp->next;
          free(temp);
	  break;
       }
       prev_node = temp;
       temp = temp->next;
    }

}

void insertAtHead(int data, struct node** head)
{
   struct node * new_node = create_node(data);
   new_node->next = (*head);
   *head = new_node;
}

void insertAtEnd(struct node* head, int data)
{
   struct node* new_node = create_node(data);
   struct node * last_node;
   while(head){
      last_node = head;
      head = head->next;
   }
   last_node->next = new_node;
}

void insertAtIndex(struct node * head, int key_element, int data)
{
   struct node *key_node;
   struct node* new_node = create_node(data);
   //find the node which has the key_element
   while(head)
   {
      if(head->data == key_element)
      {
          key_node = head;
	  new_node->next = key_node->next;
	  key_node->next = new_node;
	  break;
      }
      head = head->next;
   }
}
/* 1->2->3->4->5->NULL */

int main()
{
   struct node * head, *temp, *temp_prev;
   int i,data=0;
   head = create_node(1);
   temp = head;
   temp_prev = temp;
   //create node, change the next for each node to point to next node
   for(i=2;i<=5;i++){
	temp = create_node(i);
	temp_prev->next = temp;
	temp_prev = temp;
   }
   printList(head);
   //Insert 0 at the head
   insertAtHead(data, &head);//why address of head, because we want to modify the head 
   printList(head); /* 0->1->2->3->4->5->NULL */

   //Insert 6 at the end
   data = 6;
   insertAtEnd(head, data);//just pass the head, no need to modify the head
   printList(head);/*0->1->2->3->4->5->6->NULL */
   //Insert 99 after 3
   int key = 3;
   data = 99;
   insertAtIndex(head, key, data);/*0->1->2->3->99->4->5->6->NULL */
   printList(head);

   deleteNode(&head, 99);
   printList(head);
   return 0;
}


