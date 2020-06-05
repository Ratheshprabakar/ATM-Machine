#include<stdio.h>
int main()
{
	while(1)
	{
		int choice;
		printf("\n---ATM MACHINE---\n");
		printf("1. DEPOSIT\n2. WITHDRAWAL\n3. BALANCE ENQUIRY\n4. EXIT\nEnter Your Choice\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				deposit();
				break;	
			}
			case 2:
			{
				withdrawal();
				break;	
			}	
			case 3:
			{
				balance();
				break;		
			}
			case 4:
			{
				exit(1);	
			}
			default:
				printf("Enter a Valid choice\n");
		}	
	}		
}

