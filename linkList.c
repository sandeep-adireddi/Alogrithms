#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;
	struct node *prev;
};
struct node *insert(struct node* head, int value)
{	 
	

	struct node *node= (struct node*)malloc(sizeof(struct node)); // create new node
	struct node *temp= (struct node*)malloc(sizeof(struct node));// create new temp node
	temp = head; //storing head in temp
	
	if (head->next == NULL) // if the inserted elemet is first one
	{	
		node->value = value;
		node->next = NULL;
		head-> next = node;
		head->prev = head;

	}
	else
	{ 
		while(head->next != NULL) // traversing till last node in list
		{
			head = head->next; 
		}

		head->next = node;       //adding new node to last
		node-> next = NULL;
		node->prev = head;
		node->value = value;


		return temp;

	}
	
}
struct node *delete (struct node* head ,int position)
{	
	struct node *temp= (struct node*)malloc(sizeof(struct node)); // create new temp node
	
	temp = head; //storing head in temp

	if (head == NULL) //return null if there is no head for link list
	{ 
		return NULL;
	}

	if (position == 0)   // if first element to be deleted
	{    
		struct node *next= (struct node*)malloc(sizeof(struct node));
		next = head->next->next;         // store 2nd element address in next
		free(head->next);				// delete 1st node
		head->next = next;				// addind 2nd elemnt in 1st node place
		return  head;
	}

	else
	{  	head= head->next;
		for (int i=0; head!=NULL && i<position-1; i++)  // traverse to the node before the deleting elment
         {
         	head = head->next;
         }
     	struct node *next= (struct node*)malloc(sizeof(struct node));
		next = head->next->next; //storing the address of suffix node to deleting node 
	    next->prev = head;
		free(head->next);        //deleting the given node
		head->next = next;		// adding the suffix node in deleted nodes palce

 	 	return temp;
	}
	

}
void print(struct node* head)
{	 
	if (head == NULL)
	{  
		return;
	}
	head = head->next;
	while(head != NULL)
{   
	printf("%d\n",head->value );
	head = head->next;
}
}

int main()
{ 	
	struct node *head = (struct node*)malloc(sizeof(struct node));  //initalize the head node
	 head ->next = NULL;
	 head ->prev = NULL;
	int arraySize = 0;
	scanf("%d",&arraySize);
	for (int i = 0; i < arraySize; ++i)
	{	int value;
		scanf("%d",&value);         //taking input value
		
		head = insert(head,value); //inserting into linklist
		
	}
	head = delete(head,0);
	print(head);
	/* code */
	return 0;
}