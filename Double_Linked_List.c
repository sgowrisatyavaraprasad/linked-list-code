//double_Linked_List;
#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *pre;
	int  data;
	struct node *next;
};
typedef struct node Node;
// gobal variables , one for maintaing head and another for maintaing tail
Node *head = NULL;
Node *tail = NULL;
Node *creat_a_new_node(int val){
	Node *newnode = (Node*)malloc(sizeof(Node*));
	newnode->data = val;
	newnode->next = NULL;
	newnode->pre = NULL;
	return newnode;
}
void insert_at_head(int val){
	Node *newnode = creat_a_new_node(val);
	if(head == NULL && tail == NULL){
		head = newnode;
		tail = newnode;
	}
	else{
			head->pre = newnode;
			newnode->next = head;
			head = newnode;
	}
}
void insert_at_tail(int val){
	Node *newnode = creat_a_new_node(val);
	if(tail == NULL && head == NULL){
		tail = newnode;
		head = newnode;
	}
	else{
		tail->next = newnode;
		newnode->pre = tail;
		tail = newnode;
	}
}
void delete_at_head(){
	if(head == NULL) printf("there is no nodes to delete \n");
	else if(head->next == NULL){
		free(head);
		head = NULL;
		tail = NULL;
	}
	else{
		Node *temp = head;
		head = head->next;
		head->pre = NULL;
		free(temp);
		
	}
}
void delete_at_tail(){
	if(tail == NULL) printf("there is no nodes to delete at tail \n ");
	else if(tail->next == NULL && tail->pre == NULL){
		tail = NULL;
		head = NULL;
	}
	else{
		Node *temp = tail;
		tail = tail->pre;
		free(temp);
		tail->next = NULL;
	
	}
}
void display_from_head(){
	Node *temp = head;
	if(head == NULL) printf("there is no nodes to print! \n");
	else{
		while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
	}
}
void display_from_tail(){
	Node *temp = tail;
	if(tail == NULL) printf("there is no nodes to print! \n");
	else{
		while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->pre; 
	}
	printf("\n");
	}
}
int main(){
	int ch;
	while(1){
		printf("enter \n 1.insert at head \n 2. insert at tail \n 3.display from head \n 4. display from tail\n 5. delete at head\n 6.delete at tail");
		scanf("%d",&ch);
		if(ch == 1){
			//printf("insert at head \n");
			int val;
			printf("enter a value to insert at head: \n");
			scanf("%d",&val);
			insert_at_head(val);
		}
		else if(ch == 2){
			//printf("insert at tail \n");
			int val1;
			printf("enter a value to insert at tail: \n");
			scanf("%d",&val1);
			insert_at_tail(val1);
		}
		else if(ch == 3){
			//printf("display from head\n");
			display_from_head();
		}
		else if(ch == 4){
			//printf("display from tail \n");
			display_from_tail();
		}
		else if(ch == 5){
			delete_at_head();
		}
		else if(ch == 6){
			delete_at_tail();
		}
		else{
			printf("thank you! ");
			break;
		}
	}
}