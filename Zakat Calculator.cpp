#include<stdio.h>

int menuscreen();
float income();
void method1(float salary);
void method2(float salary);
void print(float amount_zakat_per_annum, float amount_zakat_per_month);

int main()
{
	menuscreen();
}

int menuscreen()
{
	int user_option;
	float salary;
	
	printf ("\n\t\tCalculator Zakat of Income\n");
	printf ("\t\t**************************\n");
	
	printf ("\n\t1. Zakat of Income using Method 1");
	printf ("\n\t2. Zakat of Income using Method 2");
	printf ("\n\t3. Quit\n");

	printf ("\nUser Option >> ");
	scanf ("%d",&user_option);

	if (user_option==1)
	{
		printf ("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf ("Description method 1 : \n");
		printf ("\t\tFor this method it will be calculated by using formula:\n");
		printf ("\n\t\t\tAnnual Gross Salary*2.5 percent");
		salary=income();
		method1(salary);
	}
	if (user_option==2)
	{
		printf ("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf ("Description method 2 : \n");
		printf ("\tFor this method it will be calculated by using formula : \n");
		printf ("\n\t\tAnnual Gross Salary - Total Expenses * 2.5 percent");
		salary=income();
		method2(salary);
	}
	if(!(user_option==1||user_option==2||user_option==3))
	{
		printf ("\n\tINVALID INPUT!!! PLEASE RE-ENTER....\n\n");
		menuscreen();
	}
}

float income()
{
	float salary;
	
	printf ("\nAnnual gross salary for 2019 including bonus/dividen/royalty/etc :>> RM");
	scanf ("%f",&salary);
		
	while (salary<=0)
	{
	printf("\n\t\t\tNegative Value!!");
	printf ("\n\nAnnual gross salary for 2019 including bonus/dividen/royalty/etc :>> RM");
	scanf ("%f",&salary);
	}		
	return salary;
}

void method1(float salary)
{
	float amount_zakat_per_annum, amount_zakat_per_month;
	int statement, user_option;
	
	amount_zakat_per_annum=salary*2.5/100;
	printf ("\nAmount Zakat of Income per annum = RM %.2f ", amount_zakat_per_annum);	
	amount_zakat_per_month=amount_zakat_per_annum/12;
	printf("\nAmount zakat of Income monthly deduction is RM %.2f", amount_zakat_per_month);
		
	printf ("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		
	printf("\nDo you want to print the statement? If YES (Press 1) >> ");
	scanf ("%d",&statement);
	if (statement==1)
	{
	print(amount_zakat_per_annum, amount_zakat_per_month);
	}
		if (!(statement==1))
	{
	menuscreen();
	}		
}

void method2(float salary)
{
	int married, kid, num_wife, statement;
	float parent_money,expenses_wife, expenses_kid, deposit_TH, expenses_parent, expenses_epf, total_expenses, amount_zakat_per_annum, amount_zakat_per_month;
	
	printf ("\nAre you married? Press 1 (YES) / 0 (NO)>> ");
	scanf ("%d",&married);
	if(married==1)
	{
		printf("How many your wife? >> ");
		scanf("%d",&num_wife);
		while (!(num_wife==4||num_wife==3||num_wife==2||num_wife==1))
		{
			printf("Invalid Value\n");
			printf("How many your wife?>>");
			scanf("%d",&num_wife);
		}
	}
	if(married==0)
	{
		num_wife=0;
	}
	while (!(married==0||married==1))
	{
		printf ("\tInvalid Input!!");
		method2(salary);
	}
	
	printf ("How many kid(s)? >> ");
	scanf ("%d",&kid);
	
	printf ("How much money you give to your parent monthly? >> RM ");
	scanf ("%f",&parent_money);		
	
	printf ("How much you deposit to Lembaga Tabung Haji per year? >> RM ");
	scanf ("%f",&deposit_TH);
	
	expenses_wife = num_wife * 3000;
	expenses_kid = kid * 1000;
	expenses_parent = parent_money * 12;
	expenses_epf = 11 * salary / 100;
	total_expenses = 8000 + expenses_wife + expenses_kid + expenses_parent + expenses_epf + deposit_TH;
		
	printf ("\n\nDESCRIPTION ON TOTAL EXPENSES");
	printf ("\nOWN                      : RM 8000.00");
	printf ("\nWIFE                     : RM %.2f",expenses_wife);
	printf ("\nKID (S)                  : RM %.2f",expenses_kid);
	printf ("\nPARENT (PER ANNUM)       : RM %.2f",expenses_parent);
	printf ("\nEPF-11 percent           : RM %.2f",expenses_epf);
	printf ("\nDEPOSIT (TABUNG HAJI)    : RM %.2f",deposit_TH);
	printf ("\nTOTAL EXPENSES (ALLOWED) : RM %.2f",total_expenses);
		
	printf ("\nYour nett income after deduction is RM %.2f",salary-total_expenses);
		
	amount_zakat_per_annum = (salary - total_expenses) * 2.5 / 100 ;
	printf("\n\nAmount Zakat of Income per annum is RM %.2f",amount_zakat_per_annum);
	amount_zakat_per_month = amount_zakat_per_annum / 12;
	printf ("\nAmount Zakat of Income monthly deduction is RM %.2f",amount_zakat_per_month);
		
	printf ("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	
	printf("\nDo you want to print the statement? If YES (Press 1) >> ");
	scanf ("%d",&statement);
	if (statement==1)
	{
	print(amount_zakat_per_annum, amount_zakat_per_month);
	}
		if (!(statement==1))
	{
	menuscreen();
	}		
}

void print(float amount_zakat_per_annum, float amount_zakat_per_month)
{
	printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\t\tWelcome...");
	printf("\n\t\t\tPusat Zakat Negeri Selangor\n");
	printf("\t\t\t____________________________\n");
	printf("\nZakat of Income Statement\n");
	printf("\nMonthly zakat deduction is %0.2f",amount_zakat_per_month);
	printf("\nAmount Zakat per annum is %0.2f",amount_zakat_per_annum);
	printf("\n\n\t\t\tTHANK YOU!!!");
	printf("\n\n\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	menuscreen();
}
