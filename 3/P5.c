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
int p(int x){
    int* arr;
    int c=0;
    while(x!=0){
        
        int k=x%10;
        x=x/10;
        arr[c]=k;
        c++;
    }
    int d;
    if(c%2==0)
        d=c/2;
    else
        d=(c-1)/2;
    int flag=0;
    for(int i=0;i<d;i++){
        if(arr[i]==arr[d+i+1])
            flag=1;
        else
            flag=0;

    }
    if(flag==1)
        return 1;
    else 
        return 0;



}
void ansr(){
    int c=0;
   
    struct node* temp=head;
    int n=0;
    while(temp!=NULL){
        n++;
        if(p(temp->data)==1)
            printf("Palindrome found at %d and is %d\n",n,temp->data);
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
   
}
