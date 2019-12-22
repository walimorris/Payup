/*******************************************************************
 * Filename    : Payup.c
 * Description : A daily bill notifier for PC
 * Author      : Wali Morris 
 * Created     : 20-12-2019
*******************************************************************/

#include<stdlib.h>
#include<string.h>
#include<ncurses.h>

struct Bill
{
        char company[50];
        char dueDate[50];
        int accountNumber;
        float balance;
        float paymentDue;
        float newBalance;
};
void fileUpdate(void); 
void tab(int x); 
void pause(int x); 
void startup(void); 
void setup(void);
void notify(void); 
void inputBill(struct Bill bill); 
float computeBalance(float *balance, float *payment); 

int main()
{
        struct Bill bill;
	startup(); 
	setup();  
	inputBill(bill);
	
	return 0; 
} 
void pause(int seconds)
{
	unsigned long int count = 333333333; 
	unsigned long int i, j; 
	for(i=0;i<seconds;i++)
	    for(j=0;j<count;j++); 	
} 
void fileUpdate()
{ 
	char ch; 
	printf("Do you need to update a bill? [Y/N]: ");
	ch = getchar(); 
        if(ch == 'n' || ch == 'N')
		exit(1); 
}
void startup(void)
{ 
	char ch;  	
	fileUpdate(); 
	printf("\nMaximize Screen for best results\n");	
	printf("\n<Enter to continue> or [q] to quit: ");
        ch = getchar(); 	
	if(ch == 'q' || ch == 'Q')
	    exit(1); 
	printf("\nProgram initializing...\n"); 
	pause(3); 
} 
void tab(int x)
{ 
	int i; 
	for(i=0;i<=x;i++)
	    printw("\t"); 
} 
float computeBalance(float *balance, float *payment)
{
        float newBalance;
        newBalance = *balance - *payment;
        return newBalance;
}
void setup(void)
{ 	
	int row, col; 
	char payup[] = "Payup";
        char info[] = "A Bill Notifier for your PC";
	char use[] = "A project built for your personal use";
	char author[] = "By: Wali Morris";   
	char proceed[] = "Press <enter> to continue"; 	
	
	initscr();
	if(has_colors() == FALSE)
	{ 
		printf("COLOR SUPPORT NEGATIVE\n"); 
		exit(1); 
	} 
	start_color(); 
	init_pair(1, COLOR_WHITE, COLOR_BLACK); 
	attron(COLOR_PAIR(1)); 
        attron(A_BOLD); 	
	getmaxyx(stdscr, row, col);  	
	mvprintw(row/14, (col-strlen(payup))/2, "%s", payup); 
        mvprintw(row/12, (col-strlen(info))/2, "%s", info);
	mvprintw(row/10, (col-strlen(use))/2, "%s", use); 	
	mvprintw(row/8, (col-strlen(author))/2, "%s", author);
	attron(A_BLINK); 
	mvprintw(row/4, (col-strlen(proceed))/2, "%s", proceed); 
	refresh(); 
	getch(); 
	endwin(); 	
} 
void inputBill(struct Bill bill)
{	
	float newBalance; 
	float *ptr_bal, *ptr_payment;	
	ptr_bal = &bill.balance; 
	ptr_payment = &bill.paymentDue; 

	initscr();
	attrset(A_DIM); 
        tab(11); 
       	printw("Enter bill Information\n");
        tab(11);
	printw("Company: ");
        scanw("%s", bill.company);
	tab(11); 
        printw("Due Date (year/mo/day): ");
        scanw("%s", bill.dueDate);
	tab(11);
        printw("Account Number: ");
        scanw("%d", &bill.accountNumber);
	tab(11);
        printw("Total Balance: ");
        scanw("%f", &bill.balance);
	tab(11);
        printw("Payment Due: ");
        scanw("%f", &bill.paymentDue);
	bill.newBalance = computeBalance(ptr_bal, ptr_payment);
	tab(11);
        printw("New Balance: %.2f", bill.newBalance);

	FILE *fptr;
        fptr = fopen("benjis.txt", "w");
        if(fptr == NULL)
        {
                printf("![ERROR] FILE NOT FOUND!");
                exit(1);
        }
        fprintf(fptr, "Company: %s\n", bill.company);
	fprintf(fptr, "Due Date: %s\n", bill.dueDate); 
	fprintf(fptr, "ACC#: %d\n", bill.accountNumber); 
	fprintf(fptr, "TOT BAL: %.2f\n", bill.balance); 
	fprintf(fptr, "PAYMT Due: %.2f\n", bill.paymentDue); 
	fprintf(fptr, "BAL after PAYMT: %.2f\n", bill.newBalance); 
        fclose(fptr);
	
        refresh();
        getch();
        endwin(); 	    
} 
 




	
	


	


