#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, 
	         Dlist **head2, Dlist **tail2,
			 Dlist **headR,Dlist **tailR)
{
	Dlist *temp1=*tail1;
	Dlist *temp2=*tail2;
	int carry=0;
	int res=0;
	while(temp1!=NULL || temp2!=NULL)
	{
		if(temp1!=NULL && temp2!=NULL)
		{
			res=temp1->data + temp2->data + carry;
			temp1=temp1->prev;
			temp2=temp2->prev;
		}
		else if(temp1==NULL && temp2!=NULL)
		{
			res=temp2->data + carry;
			temp2=temp2->prev;
		}
		else if(temp2==NULL && temp1!=NULL)
		{
			res=temp1->data + carry;
			temp1=temp1->prev;
		}
		carry = res / 10; 
		res = res % 10; 
		insert_at_first(headR,tailR,res);
	}
	if(carry>0)
	{
		insert_at_first(headR,tailR,carry);
	}
	return SUCCESS;
}