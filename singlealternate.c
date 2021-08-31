#include<stdio.h>
#include<stdlib.h>
typedef struct sll       
{
	int data;
	struct sll *link;
}node;
node *first=NULL;
node *last=NULL; // int arr[10];
void create(int ele)
	{
		node*ptr=(node*)malloc(sizeof(node));
		ptr->data=ele;
		ptr->link=NULL;
		if(first==NULL)
		{
			first=ptr;
			last=ptr;
		}
		else
		{
			last->link=ptr;
			last=ptr;
		}	
	}	
void display()
{
	node *temp=first;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->link;
	}
	free(temp);
}
void insert_front(int ele)
{
	node*ptr=(node*)malloc(sizeof(node));
	ptr->data=ele;
	ptr->link=first;
	first=ptr;
}
void insert_last(int ele)
{
	node*ptr=(node*)malloc(sizeof(node));
	ptr->data=ele;
	ptr->link=NULL;
	last->link=ptr;
	last=ptr;
}
void insert_middle(int ele)
{
	node*ptr=(node*)malloc(sizeof(node));
	ptr->data=ele;
	ptr->link=NULL;
	int key=30;
	node *temp=first;

	while(temp->data!=key)
	{
		temp=temp->link;
	}
		ptr->link=temp->link;
		temp->link=ptr;
}
void delete_front()
{
	first=first->link;
}
void delete_last()
{
	node *flag,*temp=first;
	while(temp->link!=NULL)
	{
		flag=temp;
		temp=temp->link;
	}
	flag->link=NULL;
	last=flag;
}
void delete_alternate()
{
	node *n,*flag,*temp=first;
	while(temp->link!=NULL)
	{
		flag=temp;
		n=temp->link;
		if(n->link!=NULL)
		{
		flag->link=n->link;
		temp=n->link;
		}
		else
		{
		flag->link=n->link;
		temp=n;   //0 1000 10 2000 20 3000 30 4000 40 5000 50 null
	}	}
}
int main()
{
	create (0);
	create (10);
    create (20);
	create (30);
	create (40);
	display();
	insert_front(5);
	printf("ater insertion 5 in front\n");
	display();
	insert_last(50);
	printf("ater insertion 50 in last\n");
	display();
	insert_middle(25);
	printf("ater insertion 25 in middle\n");
	display();
	delete_front();
	printf("delete front element 5 \n");
	display();
//	delete_last();
	printf("delete last element 50\n");
	display();
	delete_alternate();
	printf("deleting alternate numbers\n");
	display();
}


