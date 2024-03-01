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
int check(int num){
	int arr[10];
	int temp=num;
	int i=0;
	while(num!=0){
		arr[i++]=num%10;
		num=num/10;
	}
	int flag=1;
	while(temp!=0){
		if(arr[--i]!=temp%10){
			flag=0;
			break;
		}else
			flag=1;
		temp=temp/10;
	}	
	if(flag==1)
		return 1;
	
	return 0;

}


void Palindrome(){
	struct node* temp=head;
	int pos=0;
	while(temp!=NULL){
		pos++;
		if(check(temp->data)==1)
			printf("Palindrome found at position %d is %d\n",pos,temp->data);

		temp=temp->next;
	}
}


void main(){
	add();
	Palindrome();
	
}
