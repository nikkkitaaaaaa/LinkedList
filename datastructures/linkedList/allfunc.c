#include<stdio.h>
#include<stdlib.h>


struct Demo{
	int data;
	struct Demo* next;

};




struct Demo* createNode(struct Demo* head){
	struct Demo* newNode=(struct Demo*)malloc(sizeof(struct Demo));
	printf("Enter the data: ");
	scanf("%d",&(newNode->data));
	newNode->next=NULL;
	return newNode;


}



struct Demo* addLast(struct Demo* head){
	struct Demo* newnode=createNode(head);

	if(head==NULL)
		head=newnode;
	else{
		struct Demo* temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;
	}
	return head;

}


struct Demo* addFirst(struct Demo* head){
	struct Demo* newnode=createNode(head);
	if(head==NULL)
		head=newnode;
	else{
		newnode->next=head;
		head=newnode;
	}
	return head;
}
int count(struct Demo* head){
	struct Demo* temp=head;
	int c=0;
	while(temp!=NULL){
		temp=temp->next;
		c++;
	}
		
	return c;
}


struct Demo* addAtPos(struct Demo* head){
	int pos;
	printf("Enter The Pos:\n");
	scanf(" %d",&pos);
	
	int size=count(head);
	
	if(pos==1)
		head=addFirst(head);
	else if(pos==size+1)
		head=addLast(head);
	else{
		struct Demo* newnode=createNode(head);
	
		struct Demo* temp=head;
		while(pos-2){
			temp=temp->next;
			pos--;
		
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
	return head;


}

struct Demo* delFirst(struct Demo* head){
	if(head==NULL)
		return head;
	else{
		struct Demo* temp=head;
		head=head->next;
		free(temp);
	}
	return head;

}


struct Demo* delLast(struct Demo* head){
	if(head!=NULL ){
		if(head->next==NULL)
			head=delFirst(head);
		else{
			struct Demo* temp=head;
			while(temp->next->next!=NULL){
				temp=temp->next;
			}
			struct Demo* tem=temp->next;
			temp->next=NULL;
			free(tem);

		}

	}
	return head;
}

struct Demo* delPos(struct Demo* head){
	printf("Enetr pos to be deleted\n");
	int c;
	scanf("%d",&c);
	if(c<1 || c>count(head)+2){
		printf("Inavlid position\n");
		return head;
	}
	if(c==1)
		head=delFirst(head);
	else if(c==count(head) && count(head)>1)
		head=delLast(head);
	else{
		struct Demo* temp=head;
		while(c-2){
			temp=temp->next;
			c--;
		}
		struct Demo* tem=temp->next;
		
		temp->next=temp->next->next;
		tem->next=NULL;
		free(tem);

	}
	return head;
}



void printLL(struct Demo* head){
	struct Demo* temp=head;
	while(temp->next!=NULL){
		printf("|%d|->",temp->data);
		temp=temp->next;
	}
	printf("|%d|\n",temp->data);
}




void main(){
	struct Demo* head=NULL;
	int count;
	printf("enter the count of nOde: ");
	scanf("%d",&count);
	for(int i=1;i<=count;i++)
		head=addLast(head);
	char ch;
	printf("Do you want to perform Operations Y/n?\n");
	
	scanf(" %c",&ch);
	while(ch=='Y' || ch=='y'){
		printf("1.addFirst\n2.addLast\n3.addAtpos\n4.Display\n5.delFirst\n6.delLast\n7.delPos\n");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1:
				head=addFirst(head);
				break;
			case 2:
				head=addLast(head);
				break;
			case 3:
				head=addAtPos(head);
				break;
			case 4:
				printLL(head);
				break;
			case 5:
				head=delFirst(head);
				break;
			case 6:
				head=delLast(head);
				break;
			case 7:
				head=delPos(head);
				break;
			default:
				printf("Wrong Choice\n");
				break;
			

		}
		
		printf("Do you want to perform Operations Y/n:");

		scanf(" %c",&ch);
	}

}
