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
int mystr(char str[]){
	int c=0;
	while(*(str++)!='\0')
		c++;
	return c;
}

void quest(){
	printf("enter the length\n");
	int num;
	scanf("%d",&num);
	struct node* temp=head;
	while(temp!=NULL){
		if(mystr(temp->str)==num)
			printf("%s\n",temp->str);
		temp=temp->next;
	}

}

void main(){
	addnode();
	printLL();
	quest();
}

