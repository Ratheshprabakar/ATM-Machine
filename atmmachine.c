#include<stdio.h>
void deposit();
void withdrawal();
void balance();
int validate(int account_numb_temp,int passwd_temp);
int i,x;
int account_numb_temp;
int amount_temp;
int passwd_temp;
struct account_details
{
	int account_no;
	int password;
	int amount;
};
struct account_details s[3]={{12343432,1234,0},{12343433,5678,0},{89877182,1098,0}};	
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
int validate(int account_numb_temp,int passwd_temp)
{
	for(i=0;i<3;i++)
	{
		if(s[i].account_no==account_numb_temp)
		{
			if(s[i].password==passwd_temp)
			{
				return i;
				break;	
			}
			else
			{
				printf("\nPassword Mismatch");
				exit(1);		
			}	
		}	
		if(i==2)
		{
			printf("\nAccount doesn't exist");
			exit(1);	
		}
	}
}
void deposit()
{
	printf("\nEnter the account number\t");
	scanf("%d",&account_numb_temp);
	printf("\nEnter the amount to deposit\t");
	scanf("%d",&amount_temp);
	printf("\nEnter the password\t");
	scanf("%d",&passwd_temp);
	x=validate(account_numb_temp,passwd_temp);
	s[x].amount+=amount_temp;
	printf("\nRs:%d is successfully deposited into your account\nNow your balance is %d",amount_temp,s[x].amount);
}
void withdrawal()
{
	printf("\nEnter the account number\t");
	scanf("%d",&account_numb_temp);
	printf("\nEnter the amount to withdraw\t");
	scanf("%d",&amount_temp);
	printf("\nEnter the password\t");
	scanf("%d",&passwd_temp);
	x=validate(account_numb_temp,passwd_temp);
	if(s[x].amount<amount_temp)
	{
		printf("\nUnable to withdraw from your account. Your balance is lower than your request");	
	}
	else
	{
		s[x].amount-=amount_temp;
		printf("\nRs:%d is successfully withdrawn from your account\nNow your balance is %d",amount_temp,s[x].amount);		
	}	
}
void balance()
{
	printf("\nEnter the account number\t");
	scanf("%d",&account_numb_temp);
	printf("\nEnter the password\t");
	scanf("%d",&passwd_temp);
	x=validate(account_numb_temp,passwd_temp);
	printf("\nYour account No: %d contains Rs:%d",account_numb_temp,s[x].amount);	
}

