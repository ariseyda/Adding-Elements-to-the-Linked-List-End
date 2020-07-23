#include<stdio.h>
#include<stdlib.h>

//Adding Elements to the Linked List End

struct node{
	int data;
	struct node *next;
};

struct node* start=NULL;
struct node* temp=NULL;
struct node* q=NULL;

void printNode();
void addEnd(int _data);

//The paramter sent to it will be added to the end in the linked list.
void addEnd(int _data){
	
	struct node* addednode=(struct node*)malloc(sizeof(struct node));//I created the node to be added.
	addednode->data=_data;
	addednode->next=NULL;//The pointer value will be NULL because the node will be appended to the end.
	
	//If there are no nodes in the link list:
	if(start==NULL){
		start=addednode;
	}
	else{
		//I assigned the start value to one temporary value(q) to find the trailing element.
		//I throw the start variable to a temporary value because I don't want to change the start variable.
		q=start;
		while(q->next!=NULL){
			q=q->next;
		}
		q->next=addednode;
	}
	
}

void printNode(){
	
	q=start;
	//This loop does not print the last node because the pointer of the last node is NULL and exits the loop without printing, 
	//so I add the printf function below to print the last node.
	while(q->next!=NULL){
		printf("%d=>",q->data);
		q=q->next;
	}
	printf("%d",q->data);
}

int main(){
	
	int addedData;
    
    while(1){
    	printf("\nEnter the value to be added at the end:");
	    scanf("%d",&addedData);
	    addEnd(addedData);
	    printNode();
	}
    
    
	return 0;
}
