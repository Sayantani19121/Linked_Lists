#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int number;
	struct node *next;
}node;

struct node *dup(node *copy)
{
    if (copy==NULL)
    return NULL;

    else
    {
    node *new=malloc(sizeof(node));
    new->number=copy->number;
    new->next=dup(copy->next);

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

	node *numbers = NULL;
    int i=0, num;
	while(i<7)
	{
		printf("\nEnter your number ");
		scanf("%d", &num);
		
		node *n = malloc(sizeof(node));

		if(!n)
		{
			return 1;		
		}

		n-> number =num;
		n-> next = NULL;

		if(numbers)
		{
			for (node *ptr =numbers; ptr!=NULL; ptr=ptr->next)
            {
			if(ptr->next == NULL)
			{
				ptr->next=n;
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
    node *newlist= dup(numbers);
    reversep(newlist);
}
