#include <stdio.h>

typedef struct {
	int day, month, year;
} date;


typedef struct {
	char name[50];
	int accountNumber;
	double balance;
	date lastTrans;
} customer;


void getCustomerName(customer* cptr);
void getAccountNumber(customer* cptr);
void getLastTransDate(customer* cptr);
void getBalance(customer* cptr);
void printCustomer(customer* cptr);


void main() {
	int i;
	char temp[100];
	customer customers[3];

	for (i = 0; i < 3; i++) {
		getCustomerName(&customers[i]);
		getAccountNumber(&customers[i]);
		getLastTransDate(&customers[i]);
		getBalance(&customers[i]);
		gets_s(temp, 100);
		printf("\n");
	}

	printf("\n\n%25s\t%13s\t%12s\t%s\n\n", "Name", "Account Number", "Balance", "Date of Last Transaction");
	
	for (i = 0; i < 3; i++) {
		printCustomer(&customers[i]);
	}
}

void getCustomerName(customer* cptr) {
	char customerName[50];
	printf("Enter Customer Name: ");
	scanf_s("%s", (*cptr).name, 50);
}

void getAccountNumber(customer* cptr) {
	int accountNumber;
	printf("Enter Account Number: ");
	scanf_s("%d", &accountNumber);
	(*cptr).accountNumber = accountNumber;
}


void getLastTransDate(customer* cptr) {
	date lastTransDate;
	printf("Enter Last Transaction Date in format dd/mm/yyyy: ");
	scanf_s("%d/%d/%d", &lastTransDate.day, &lastTransDate.month, &lastTransDate.year);
	(*cptr).lastTrans.day = lastTransDate.day;
	(*cptr).lastTrans.month = lastTransDate.month;
	(*cptr).lastTrans.year = lastTransDate.year;
}

void getBalance(customer* cptr) {
	double currentBalance;
	printf("Enter Current Balance: ");
	scanf_s("%lf", &currentBalance);
	(*cptr).balance = currentBalance;
}

void printCustomer(customer* cptr) {
	printf("%25s\t%13d\t%12.2f\t%d/%d/%d\n", cptr->name, cptr->accountNumber, cptr->balance, cptr->lastTrans.day, cptr->lastTrans.month, cptr->lastTrans.year);
}