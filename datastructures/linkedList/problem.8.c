#include<stdio.h>
#include<stdlib.h>



struct node{
	char str[20];
	struct node* next;
};

struct node* head=NULL;


void addnode(){
	printf("enter how many nodes\n");
	int count;
	scanf("%d",&count);
	getchar();	
	struct node* newnode=NULL;
	for(int i=1;i<=count;i++){
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("enetr the string\n");
		
		char c;
		int i=0;
		
		while((c=getchar())!='\n')
			newnode->str[i++]=c;	
		newnode->str[i]='\0';
		
		newnode->next=NULL;
		if(head==NULL)
			head=newnode;
		else{
			struct node* temp=head;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=newnode;
		}
	}
}

void printLL(){
	struct node* temp=head;
	while(temp->next!=NULL){
		printf("|%s|->",temp->str);
		
		temp=temp->next;

	}
	printf("|%s|\n",temp->str);
}
int strleng(char str[]){
	int c=0;
	while(*(str++)!='\0')
		c++;
	return c;
}
int count(){
	struct node* temp=head;
	int c=0;
	while(temp!=NULL){
		temp=temp->next;
		c++;
	}
	return c;
}
void delFirst(){
	if(head==NULL)
		return ;
	else{
		struct node* temp=head;
		head=head->next;
		free(temp);
	}
}


void delLast(){
	if(head!=NULL ){
		if(head->next==NULL)
			delFirst();
		else{
			struct node* temp=head;
			while(temp->next->next!=NULL){
				temp=temp->next;
			}
			struct node* tem=temp->next;
			temp->next=NULL;
			free(tem);

		}

	}

}


void del(int c){
	if(c==1)
		delFirst();
	else if(c==count() && count()>1)
		delLast();
	else{
		struct node* temp=head;
		while(c-2){
			temp=temp->next;
			c--;
		}
		struct node* tem=temp->next;
		
		temp->next=temp->next->next;
		tem->next=NULL;
		free(tem);

	}
}

void quest(){
	printf("enter the length:");
	int len;
	scanf("%d",&len);
	struct node* temp2=head;

	struct node* temp=head;
	int c=0;
	while(temp2!=NULL){
		c++;
		temp=temp2;
		temp2=temp2->next;
		if(len!=strleng(temp->str))
			del(c--);
	
	}
}



void main(){
	addnode();
	printLL();
	quest();
	printLL();
}
