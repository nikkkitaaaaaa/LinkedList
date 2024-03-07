#include<stdio.h>
void* malloc(size_t);


struct node{
	struct node* prev;
    char data[10];
	struct node* next;

};


struct node* head=NULL;

struct node* create(){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
     
	printf("enter the data: ");
    
    char ch;
    int i=0;
	while((ch=getchar())!='\n'){
        (newnode->data[i++])=ch;
         
    }
    (newnode->data[i])='\0';
    
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
int p(char* str){
    int size=0;
    while(*(str++)!='\0')
        size++;
    return size;



}
void ansr(){
    int c=0;
   int size;
   printf("Enter the Size of string:");
   scanf("%d",&size);
    struct node* temp=head;
    int n=0;
    while(temp!=NULL){
        n++;
        if(p(temp->data)==size)
            printf("%s\n",temp->data);
        temp=temp->next;
    }
    
}
void printLL(){
    if(head!=NULL){
        struct node* temp=head;
        while(temp->next!=NULL){
            printf("|%s|->",temp->data);
            temp=temp->next;
        }
        printf("|%s|\n",temp->data);
    }else 
        return;
}


void main(){
    printf("enter the no of Nodes in Linked List :");
    int n;
    scanf("%d",&n);
     getchar();
    for(int i=0;i<n;i++)
        addLast();
    printf("Given Linked List\n");
    printLL();
    ansr();
   
}
