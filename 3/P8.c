#include<stdio.h>
#include<string.h>
void* malloc(size_t);

void free(void*);
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

int size(){
    int c=0;
    struct node* temp=head;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }

    return c;
}
void delatPos(int pos){
    int sizes=size();
    if(pos==1){
        if(head!=NULL){
            if(head->next!=NULL){
                
                head=head->next;
                head->prev=NULL;
                free(head->prev);
                
            }else{
                struct node* temp=head;
                head=head->next;
                free(temp);
            }
        }

    }else if(pos!=1 && pos==sizes){
        struct node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->prev->next=NULL;
        temp->prev=NULL;
        free(temp);
    }else{
        struct node* temp=head;
        while(pos-1){
            temp=temp->next;
            pos--;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}


void ansr(){
    int c=0;
    printf("enter length:");
    scanf("%d",&c);
   int size;
   
    struct node* temp=head;
    int n=0;
    
    while(temp!=NULL){
        n++;

        if(strlen(temp->data)!=c){
            delatPos(n);
            n--;
        }
        
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
    printLL();
}
