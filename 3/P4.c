#include<stdio.h>
void* malloc(size_t);


struct node{
	struct node* prev;
	int data;
	struct node* next;

};


struct node* head=NULL;

struct node* create(){
	struct node* newnode=(struct node*)malloc(24);
	printf("enter the data: ");
	scanf("%d",&(newnode->data));
	newnode->prev=NULL;
	newnode->next=NULL;
	return newnode;
}


void addLast(){
	struct node* newnode=create();
	if(head==NULL)
		head=newnode;
	else{
		struct node* temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		newnode->prev=temp;
		temp->next=newnode;

	}
}
void ansr(){
    int c=0;
   
    struct node* temp=head;
    while(temp!=NULL){
        int n=0;
        while((temp->data)!=0){
            n+=(temp->data)%10;
            temp->data=(temp->data)/10;
        }
        temp->data=n;
        
        temp=temp->next;
    }
    
}
void printLL(){
    if(head!=NULL){
        struct node* temp=head;
        while(temp->next!=NULL){
            printf("|%d|->",temp->data);
            temp=temp->next;
        }
        printf("|%d|\n",temp->data);
    }else 
        return;
}


void main(){
    printf("enter the no of Nodes in Linked List :");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        addLast();
    printf("Given Linked List\n");
    printLL();
    ansr();
    printf("Answer Linked List\n");
    printLL();

}
