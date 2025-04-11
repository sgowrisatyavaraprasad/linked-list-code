#include<stdio.h>
#include<stdlib.h>
//node is structure 
struct node
{
	int data;
	struct node *next;
};
//Menu-driven programm
struct node *head = NULL;
struct node *creat_new_node(int val){
	struct node *nodes = (struct node *)malloc(sizeof(struct node));
	nodes->data = val;
	nodes->next = NULL;
	return nodes;//returing the created node:
}
void insert_at_head(int val)
{
	struct node*newnode = creat_new_node(val);
	newnode->data = val;//setting data part to value
	newnode->next = NULL;//setting next part to NULL momentarily
	//check if linked list is empty
	if(head == NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->next = head;//store address of current_head is newnode's                  
		head = newnode;//make neew node as your head
	}
}
void insert_at_tail(int val1){
	struct node *newnode = creat_new_node(val1);
	newnode->data = val1;
	newnode->next = NULL;
	if(head == NULL){
		head = newnode;
	}
	else{
	struct node *temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}

	temp->next = newnode;
	}
}
void delete_at_head(){
	if(head == NULL) printf("no nodes to delete\n");
	else{
	struct node *del_node = head;
	printf("%d is delected from head\n",head->data);
	head = head->next;
	free(del_node);
	}
}
void delete_at_tail(){
	if(head == NULL) printf("there is no nodes in the list\n");
	else if(head->next == NULL){
		free(head);
		head = NULL;
	}
	else{
		// stop at last but one node adn set it's next part to null
		struct node *temp = head;
		while(temp->next->next != NULL){
			temp = temp->next;
		}
		temp->next = NULL;
	}
}
void search_element(int key){
	int found = 0;
	struct node *temp = head;
	while(temp != NULL){
	if(key == temp->data){
		found = 1;
		break;
	}
	temp = temp->next;
	}
	printf("%s\n",found ? "FOUND" : "NOT FOUND");
	}
int get_node_count(){
	int count = 0;
	struct node *temp = head;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}
void insert_at_posion(int val2,int x){
	struct node *newnode = creat_new_node(val2);
    if(head == NULL || x == 0){
    	newnode->next = head;
    	head = newnode;
	}
	else{
	struct node *temp = head;
	while(x>1&&temp->next != NULL){
		temp = temp->next;
		x--;
	}
	   newnode->next = temp->next;
		temp->next = newnode;
}
}
void display()
{
	struct node *temp = head;
	if(temp == NULL)
	{
		printf("No nodes to display\n");
	}
	else 
	{
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp= temp->next;
		}
		printf("\n");
	}
}
int main()
{
	int ch;
	while (1)
	{
		printf("Enter\n 1.Insert at head\n2.Insert at tail\n3.Display\n4.delete at head\n5.delete at tail\n6.search element\n7.nodecount\n8.insert at position\nAny other to exit : \n");
		scanf("%d",&ch);
		if (ch == 1)
		{
			int val;
			printf("Enter a value to insert at Head: \n");
			scanf("%d",&val);
			insert_at_head(val);
		}
		else if (ch == 2)
		{
			int val1;
			printf("enter a value to insert at tail: \n");
			scanf("%d",&val1);
			insert_at_tail(val1);
		}
		else if(ch == 3)
		{
			display();
		}
		else if(ch==4){
			//perform a delete at head
			delete_at_head();
		}
		else if(ch==5){
			delete_at_tail();
		}
		else if (ch == 6){
			int key;
			printf("enter the element that can search on linked list: ");
			scanf("%d",&key);
			search_element(key);
		}
		else if (ch == 7){
			int node_count = get_node_count();
			printf("the nodes count is : %d",node_count);
		}
		else if(ch==8){
			int val2,position;
			printf("enter the value to insert at position \n");
			scanf("%d",&val2);
			printf("enter the position to insert the value it : \n");
			scanf("%d",&position);
			insert_at_posion(val2,position);
		}
		else{
			printf("THANK YOU");
			break;
		}}}