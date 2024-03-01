#include<stdio.h>
void* malloc(size_t);





struct node{
	int data;
	struct node* next;
}
;
struct node* head=NULL;
void add(){
	printf("How many Nodes you want to make?\n");
	int NoOfNodes;
	scanf("%d",&NoOfNodes);
	for(int i=1;i<=NoOfNodes;i++){
		struct node* newnode=(struct node*)malloc(sizeof(struct node));
		printf("enter data: ");
		scanf("%d",&((*newnode).data));
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


void aDigits(){
	struct node* temp=head;
	while(temp!=NULL){
		int num=0;
		while(temp->data!=0){
			num+=(temp->data)%10;
			temp->data=(temp->data)/10;	

		}
		(*temp).data=num;
		temp=temp->next;
	}
}
void printLL(){

	struct node* temp=head;
	while(temp->next!=NULL){
		printf("|%d|->",(temp->data));
		temp=temp->next;
	
	}
	printf("|%d|\n",(temp->data));
}


void main(){
	add();
	aDigits();
	printLL();

}
