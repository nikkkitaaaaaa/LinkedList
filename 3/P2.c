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
int ansr(int n){
    int c=0;
    int sans=-1;
    int ans=-1;
    struct node* temp=head;
    while(temp!=NULL){
        
        c++;
    if(temp->data==n){
        sans=ans;
        ans=c;
    }
        
        temp=temp->next;
    }
    return sans;
}



void main(){
    printf("enter the no of Nodes in Linked List :");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        addLast();
    int q;
    printf("Enter the number whose occurences :");
    scanf("%d",&q);

    int ans=ansr(q);
    printf("the 2nd last occurence of %d is found at %d\n",q,ans);
}
