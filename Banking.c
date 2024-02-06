                                   // ABC Online Banking Portal


#include <stdio.h>  //printf(),scanf()
#include <stdlib.h> //exit(0),system()
#include <conio.h>  //getch()

char struct user_Details{
    char name[20];
    int acc_no;
}

float deposit_amount, amount = 0;
int account, count = 0;   // Global variables
float trans_amount;
float with_amount;


void withdraw_money();
void transfer_money();
void checkDetail();      //Function Declarations
void Exits();
void menu();

//Print "---" line Function
void divider()
{
    for (int i = 0; i < 110; i++)
    {
        printf("-");
    }
}

//Main function
int main()
{
    FILE *ptr = fopen("Account.txt", "a+");
    int ch;
    printf("\n\n\t\t\t\t\tABC Online Banking Portal\n");
    divider();
    printf("\n\n\t\t\t\t\tEnter your name : ");
    gets(name);
    fprintf(ptr, "\n\nName : %s\n", name);
    printf("\n\t\t\t\t\tEnter your account no. : ");
    scanf("%d", &acc_no);
    fprintf(ptr, "Account no. : %d\n", acc_no);

    fclose(ptr);
    while (1){
        menu();
        printf("\n\n\t\t\t\t\tEnter your choice : ");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            system("cls");
            deposit_money();
            break;
        case 2:
            system("cls");
            withdraw_money();
            break;
        case 3:
            system("cls");
            transfer_money();
            break;
        case 4:
            system("cls");
            checkDetail();
            break;
        case 5:
            system("cls");
            Exits();
            exit(0);

        default:
            printf("\n\t\t\t\t\t========================");
            printf("\n\t\t\t\t\t#####Invalid choice#####");
            printf("\n\t\t\t\t\t========================");
        }
    }

    return 0;
}

void menu()
{

    system("cls");
    divider();
    printf("\n\t\t\t\t\t\tMENU\n\n");
    divider();
    printf("\n\n\t\t\t\t\t1.Deposit Money\n");
    printf("\t\t\t\t\t2.Withdraw Money\n");
    printf("\t\t\t\t\t3.Transfer Money\n");
    printf("\t\t\t\t\t4.Account details\n");
    printf("\t\t\t\t\t5.Exit\n\n");
    divider();
}


void deposit_money()
{

    FILE *ptr = fopen("Account.txt", "a");
    printf("\n\t\t\t\t\t*****DEPOSITING MONEY*****\n");
    for (int i = 0; i < 110; i++){
        printf("-");
    }

    printf("\n\t\t\t\t\tEnter the amount you want to deposit : ");
    scanf("%f", &deposit_amount);
    amount += deposit_amount;
    printf("\n\t\t\t\t\t========================");
    printf("\n\t\t\t\t\t****Money Deposited****");
    printf("\n\t\t\t\t\t========================");
    printf("\n\n\t\t\t\t\tNow balance : %.2f\n", amount);
    fprintf(ptr, "\nRs%.2f had been deposited to your account \n", deposit_amount);
    count++;

    fclose(ptr);
    printf("\n\n\t\t\t\t\tPress any key....");
    getch();
}



void withdraw_money()
{
    FILE *ptr = fopen("Account.txt", "a");
    printf("\n\n\t\t\t\t\t*****WITHDRAWING MONEY*****\n");
    for (int i = 0; i < 110; i++){
        printf("-");
    }
    printf("\n\n\t\t\t\t\tEnter the amount you want to withdraw : ");
    scanf("%f", &with_amount);

    if (amount < with_amount){
        printf("\n\t\t\t\t\t========================");
        printf("\n\t\t\t\t\t****Insufficient balance****");
        printf("\n\t\t\t\t\t========================");

    }
    else{
        amount = amount - with_amount;
        printf("\n\t\t\t\t\t========================");
        printf("\n\t\t\t\t\t*****Money withdrawn*****");
        printf("\n\t\t\t\t\t========================");
        printf("\n\t\t\t\t\tCurrent balance : %.2f\n", amount);
        fprintf(ptr, "\nRs%.2f had been withdrawn from your account \n", with_amount);
        count++;
    }
    fclose(ptr);
    printf("\n\n\t\t\t\t\tPress any key....");
    getch();
}



void transfer_money(){
    FILE *ptr = fopen("Account.txt", "a");
    printf("\n\n\t\t\t\t\t*****TRANSFERRING MONEY*****\n");
    for (int i = 0; i < 110; i++){
        printf("-");
    }
    printf("\n\n\t\t\t\t\tEnter the Beneficiary account no : ");
    scanf("%d", &account);
    printf("\n\n\t\t\t\t\tEnter the amount you want to transfer : ");
    scanf("%f", &trans_amount);

    if (amount < trans_amount){
        printf("\n\t\t\t\t\t========================");
        printf("\n\t\t\t\t\t****You have not sufficient balance****");
        printf("\n\t\t\t\t\t========================");
    }
    else{
        amount = amount - trans_amount;
        printf("\n\t\t\t\t\t========================");
        printf("\n\t\t\t\t\t****Money Transferred****");
        printf("\n\t\t\t\t\t========================");
        printf("\n\t\t\t\t\tCurrent balance : %.2f\n", amount);
        fprintf(ptr, "\nRs%.2f had been transferred from your account to %d\n\n", trans_amount, account);
        count++;
    }
    fclose(ptr);
    printf("\n\n\t\t\t\t\tPress any key....");
    getch();
}



void checkDetail()
{
    printf("\n\n\t\t\t\t\tACCOUNT DETAILS\n");
    for (int i = 0; i < 110; i++)
    {
        printf("-");
    }

    printf("\n\n\t\t\t\t\tName : %s\n", name);
    printf("\n\t\t\t\t\tAccount No. : %d\n", acc_no);
    printf("\n\t\t\t\t\tTotal balance = %.2f\n ", amount);
    printf("\n\n\t\t\t\t\t%d transactions have been made from your account \n", count);
    printf("\n\n\t\t\t\t\tPress any key.....");
    getch();
}



void  Exits()
{
    FILE*ptr = fopen("Account.txt","a");
    printf("\n\n\t\t\t\t\tACCOUNT DETAILS\n");
    for (int i = 0; i < 110; i++)
    {
        printf("-");
    }
    printf("\n\n\t\t\t\t\tName : %s\n", name);
    printf("\n\t\t\t\t\tAccount No. : %d\n", acc_no);
    printf("\n\t\t\t\t\tTotal balance = %.2f\n ", amount);
    printf("\n\n\n\t\t\t\t\tPress any key to exit.....");
    getch();
    fprintf(ptr,"==========================================================\n");
}
