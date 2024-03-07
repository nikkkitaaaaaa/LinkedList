#include<stdio.h>

void* malloc(size_t);
void free(void*);


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
void addFirst(){
	struct node* newnode=create();
	if(head==NULL)
		head=newnode;
	else{
		newnode->next=head;
		head->prev=newnode;
		head=newnode;

	}

}

int count(){
	int c=0;
	struct node* temp=head;
	while(temp!=NULL){
		temp=temp->next;
		c++;
	}
	return c;
}

void addatPos(){

	printf("enter postion : ");
	int pos;
	scanf("%d",&pos);
	int size=count();
	if(pos>0 && pos<size+2){
		if(pos==1)
			addFirst();
		else if(pos==size+1)
			addLast();
		else{
			struct node* newnode=create();
			struct node* temp=head;
			while(pos-1){
				temp=temp->next;
				pos--;
			}
			newnode->prev=temp->prev;
			temp->prev->next=newnode;
			newnode->next=temp;
			temp->prev=newnode;
		}
	}

}
void delFirst(){
	if(head!=NULL ){
		if(head->next!=NULL){
		head=head->next;
		head->prev->next=NULL;
		free(head->prev);
		head->prev=NULL;
		}else
			head=NULL;
	}

}


void delLast(){
	if(head!=NULL){
		if(head->next!=NULL){
			struct node* temp=head;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->prev->next=NULL;
			temp->prev=NULL;
			free(temp);
			
		}else
			head=NULL;

	}
}
void delatPos(){
	printf("enter postion : ");
        int pos;
        scanf("%d",&pos);
        int size=count();
        if(pos>0 && pos<size+2){
                if(pos==1)
                        delFirst();
                else if(pos==size+1)
                        delLast();
                else{
                        struct node* temp=head;
                        while(pos-1){
                                temp=temp->next;
                                pos--;
                        }
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			temp->prev=NULL;
			temp->next=NULL;
			free(temp);


                        
		}
        }

}
void printLL(){
	struct node* temp=head;
	while(temp->next!=NULL){
		printf("|%d|-><-",temp->data);
		temp=temp->next;
	}
	printf("|%d|\n",temp->data);
}


void main(){
	int c;
	printf("enter the no of nodes :");
	scanf("%d",&c);
	for(int i=1;i<=c;i++)
		addLast();
	delatPos();
	printLL();
}

