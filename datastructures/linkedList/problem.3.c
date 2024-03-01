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
	
	int pos=0;
	struct Quest* temp=head;
	while(temp!=NULL){
		
		if(temp->data==num){
			pos++;
		}
		temp=temp->next;
	}
	if(pos==0)
		printf("No occurences\n");
	else{
		printf("%d Ocuuurence \n",pos);
	}
}




void main(){
	add();
	int num;
	printf("enter the no whose second Last Occcurence should Be found :");
	scanf("%d",&num);
	sLast(num);
}
