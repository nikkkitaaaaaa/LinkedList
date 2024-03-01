#include<stdio.h>
#include<stdlib.h>



struct Quest{
	int data;
	struct Quest* next;
};
struct Quest* head=NULL;




void add(){
	printf("How many Nodes you want to make?\n");
	int NoOfNodes;
	scanf("%d",&NoOfNodes);
	for(int i=1;i<=NoOfNodes;i++){
		struct Quest* newnode=(struct Quest*)malloc(sizeof(struct Quest));
		printf("enter data: ");
		scanf("%d",&((*newnode).data));
		newnode->next=NULL;
		if(head==NULL)
			head=newnode;
		else{
			struct Quest* temp=head;
			while(temp->next!=NULL)
				temp=temp->next;
			temp->next=newnode;
		}

	}
}


void sLast(int num){
	int c=0;
	int Lpos=0;
	int Spos=0;
	struct Quest* temp=head;
	while(temp!=NULL){
		c++;
		if(temp->data==num){
			Spos=Lpos;
			Lpos=c;
		}
		temp=temp->next;
	}
	if(Lpos==0 && Spos==0)
		printf("No occurences\n");
	else{
		if(Spos==0)
			printf("One Ocuuurence at %d\n",Lpos);
		else
			printf("Second Last Occurence at %d\n",Spos);
	}
}




void main(){
	add();
	int num;
	printf("enter the no whiose second Last Occcurence should Be found :");
	scanf("%d",&num);
	sLast(num);
}
