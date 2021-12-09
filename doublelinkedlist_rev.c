#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int number; 
	struct node *next;
    struct node *prev;
}node;

struct node *dup(node *copy)
{
    if (copy==NULL)
    return NULL;

    else
    {
        node *start=NULL;
        node *new=malloc(sizeof(node));
        if(start==NULL)
        start=new;
      
      new->number=copy->number;
      new->next=dup(copy->next);
      new->prev=copy->prev;

    return new;
    }

}
void reversep(node *ref)
{
 node *current=ref, *prev=NULL,*next=NULL;

    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        current->prev=next;
        prev = current;
        current = next;
    }
 ref=prev;

 while(ref!=NULL)
{
    printf("%d\n", ref->number);
    ref=ref->next;
}
}

int main(void)
{

    struct node *head = NULL;
    struct node *last = NULL;
    struct node *numbers = NULL;
    int i=0,num;

	while(i<7)
	{
		printf("\nEnter you number: ");
		scanf("%d", &num);
		
		node *n = malloc(sizeof(node));

		if(!n)
		{
			return 1;		
		}

		n-> number =num;
		n-> next = NULL;
        n-> prev = NULL;

        if(head==NULL) 
         head = n;

		if(numbers)
        	{
			for (node *ptr =numbers; ptr!=NULL; ptr=ptr->next)
            {
			if(ptr->next == NULL)
			{
				n->prev= head;
                last=n;
                ptr->next=last;
				break;
			}
		}
            }
		else
		{
			numbers=n;		
		}

        i++;

	}	

    node *random= dup(numbers);
    reversep(random);
}

/* Major changes required
1. Creating a link to the previous node in overall structure as compared to SLL
2. Allocating a start or head node for the next node to be linked to the previous one.
3.The same is taken care of while copying.

Advantages and Disadvantages of a Doubly Linked list
Advantages:
1. CLL can allocate or reallocate memory easily during its execution.
2. Just like a singly linked list, it is one of the easiest data structure to implement.
3. The traversal in a doubly linked list is bidirectional. Hence we can move to the next or the previous node from any particular node.
4. Deletion of nodes is easy as compared to a Singly Linked List as only the pointer needs to be deleted. 
5. It is very easy to reverse the doubly linked list.

Disadvantages:
1. It uses extra memory when compared to the array and singly linked list.
2. Since elements in memory are stored randomly, therefore the elements are accessed sequentially and no direct access is allowed.

*/