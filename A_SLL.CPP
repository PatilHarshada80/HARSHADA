#include<iostream.h>
#include<conio.h>

class NODE
{
	public :
		int data;
		NODE *next;
};

class STACK
{
	private :
		 NODE *TOP;

	public :
		STACK();
		void PUSH(int ele);
		int POP();
		void VIEW_ALL();
};

STACK :: STACK()
{
	TOP = NULL;
}

void STACK :: PUSH(int ele)
{
	NODE *NEW = new NODE();
	NEW -> data = ele;
	NEW -> next = NULL;
	NEW -> next = TOP;
	TOP = NEW;
}

int STACK :: POP()
{
	if(TOP == NULL)
	{
		cout<<"List is empty.";
		return NULL;
	}
	else
	{
		int ele = TOP ->data;
		NODE *TEMP=TOP;
		TOP =TOP->next;
		delete TEMP;
		return ele;
	}
}

void STACK :: VIEW_ALL()
{
	if(TOP==NULL)
	{
		cout<<"STACK IS NULL";
	}
	else
	{
		NODE *ptr;
		ptr=TOP;
		while(ptr != NULL)
		{
			cout<<ptr->data<<" ";
			ptr = ptr -> next;
		}
	}

}


void MENU()
{
	STACK obj;
	int opt,ele;
	do
	{
		cout<<"\n........"<<endl;
		cout<<"\n1.PUSH.";
		cout<<"\n2.POP.";
		cout<<"\n3.List All.";
		cout<<"\n4.Exit.";
		cout<<"\n........"<<endl;
		cout<<"\nEnter your option : ";
		cin>>opt;
		switch(opt)
		{
			case 1 :
				cout<<"Enter the element : "<<endl;
				cin>>ele;
				obj.PUSH(ele);
				break;
			case 2 :
				ele = obj.POP();
				if(ele != NULL)
				cout<<endl<<ele<<" delete.";
				break;
			case 3 :
				obj.VIEW_ALL();
				break;
			case 4 :
				return;


		}

	}while(1);
}

void main()
{
	clrscr();
	MENU();
	getch();
}