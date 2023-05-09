#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include <unistd.h>

char ch[5][40] = { "Asansol SuperFast", "Kharagpur SuperFast ", "Digha SuperFast", "Burdwan SuperFast", "Durgapur SuperFast" };
void details(char arr[][40][20], char ch[][40]);
void booking(char arr[][40][20], char ch[][40]);
void buslist();
void Bus_status(char arr[][40][20], char ch[][40]);
void status(char arr[][40][20], char ch[][40], int Bn);
int Fare(int Bn, int n);
void login(char arr[][40][20], char ch[][40]);
void Slogin(char arr[][40][20], char ch[][40]);
void menu(char arr[][40][20], char ch[][40]);
void main_menu(char arr[][40][20], char ch[][40]);
void cardMethod(int a);
void cardMethod(int a);

int main()
{
    system("COLOR E0");
    int num, i, c, a = 1;
    char Scode[12];
    char arr[6][40][20];
    char name[20];
    char number[10];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 50; j++)
            strcpy(arr[i][j], "AVAILABLE");
    }
    main_menu(arr, ch);
    return 0;
}

void details(char arr[][40][20], char ch[][40])
{
    int f1 = 0;
    int f2 = 0;
    int f = 0;
    char x, y;
    char name[20];
    char number[10];
    system("CLS");
    printf("\n\n================================= WELCOME TO BUS TICKET VENDING SYSTEM USER INTERFACE  =================================\n\n\n");
    printf("\n\n\n");
    printf("\t\t\tEnter Your Name :-  ");
    fflush(stdin);
    gets(name);
    printf("\n\n");
    printf("\t\t\tEnter Your Mobile No. :-  +91 ");
    fflush(stdin);
    gets(number);
    for (int i = 1;i < 10;i++)
    {
        x = number[i];
        if (x == '0' || x == '1' || x == '2' || x == '3' || x == '4' || x == '5' || x == '6' || x == '7' || x == '8' || x == '9')
        {
            f++;
        }
    }
    if (f == 9)
    {
        f1 = 1;
    }
    y = number[0];
    if (y == '6' || y == '7' || y == '8' || y == '9')
    {
        f2 = 1;
    }
    if (f1 == 1 && f2 == 1 && strlen(number) == 10)
    {
        menu(arr, ch);
    }
    else
    {
        printf("\n\n\t\t\t Please Enter A Valid Mobile No. !");
        getch();
    }
}

void Slogin(char arr[][40][20], char ch[][40])
{
    int a = 0;
    char ans;
    char Scode[12];
    login(arr, ch);
    printf("\n\n\n\t\t\t Enter The Staff Code To Reset The System :- ");
    while (a <= 2)
    {
        scanf("%s", &Scode);
        if (strcmp(Scode, "*#SReset7890") == 0)
        {
            printf("\n\n\t\t\tAre you Sure You Want To Reset System ? ");
            printf("\n\n\t\t\t (Enter Y For Yes Or N For No)  :-      ");
            scanf(" %c", &ans);
            if (ans == 'y' || ans == 'Y')
            {
                for (int i = 0; i < 6; i++)
                {
                    for (int j = 0; j < 50; j++)
                        strcpy(arr[i][j], "AVAILABLE");
                }

                main_menu(arr, ch);
            }
            else
                main_menu(arr, ch);
        }
        else
        {
            system("CLS");
            printf(" \n\n\t\t\tStaff Code Is Incorrect !");
            a++;
            if (a > 2)
            {
                printf("\n\n\n\n\t\t\t You have Entered Wrong Staff Code Three Times ! \n\n\t\t\t Please Try After Some Time ");
                getch();
            }
            else
            {
                printf("\n\n\n\t\t\tEnter Correct Staff Code ! ");
                getch();
            }
        }
    }
}

void booking(char arr[][40][20], char ch[][40])
{
    int n, Bn, j, ln, choice, fare;
    int s[40];
    char S = { ' ' };
    char t[][10] = { "07:00 AM", "09:30 AM", "11:15 AM", "02:00 PM", "05:30 PM" };
    system("CLS");
    printf("\n\n\n\t======================= Ticket Booking =======================\n\n");
    printf("\n\t\t\t(Bus No.s Are From 1 To 5)");
    printf("\n\n\t\t\tEnter The Bus Number :- ");
    scanf("%d", &Bn);
    status(arr, ch, Bn);
    printf("\n");
    fflush(stdin);
    if (Bn >= 1 && Bn <= 5)
    {
        printf("\n\t\t ( You Can Only Book Maximum Four Tickets At A Time ) ");
        printf("\n\n\t\t\tEnter The  Number Of Tickets :- ");
        scanf("%d", &n);
    }
    else
    {
        printf("\n\t\t\tPlease Enter A Valid Bus No. !");
        getch();
        booking(arr, ch);
    }
    if (n >= 1 && n <= 4)
    {
        for (int i = 0; i < n; i++)
        {
            system("CLS");
            printf("\n       _________________________________________________________________________________");
            printf("\n\t\t\t\t   Passenger %d Details :- \n ", i + 1);
            printf("      _________________________________________________________________________________\n");
            printf("\n\n\t\t\tEnter the Seat No. :- ");
            fflush(stdin);
            scanf("%d", &j);
            s[i] = j;
            if (j < 1 || j > 40)
            {
                printf("\n\t\t\tPlease Enter A Valid Seat No. !");
                getch();
                i = i - 1;
            }
            else if (j >= 1 && j <= 40)
            {
                if (strcmp(arr[Bn - 1][j - 1], "AVAILABLE") != 0)
                {
                    printf("\n\t\t\tSeat No %d is Already Booked ! ", j);
                    i = i - 1;
                    getch();
                }
                else
                {
                    printf("\n\t\t\tEnter Passenger's Name :- ");
                    fflush(stdin);
                    gets(arr[Bn - 1][j - 1]);

                }
            }
            else
            {
                printf("\n\t\t\tPlease Enter A Valid Seat No. !");
                getch();
                i = i - 1;
            }
            system("CLS");
        }
        fare = Fare(Bn, n);
        printf("\n\n\t\t\tTotal Fare = Rs. %d /-\n\n", fare);
        printf("\n-----------------------Payment Methods------------------------\n\n\n");
        printf("                        1-> Cash              \n");
        printf("                        2-> Debit Card              \n");
        printf("                        3-> QR code                   \n\n\n");
        printf("\t\tEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            cashMethod(fare);
            break;
        case 2:
            cardMethod(fare);
            break;
        case 3:
            printf("\t\tMethod Under Maintainance. Try to make payment using other methods.\n");
            break;
        default:
            printf("\t\tInvalid choice. Please choose again.\n");
            break;
        }
        printf("\n       _________________________________________________________________________________\n");
        printf("\n\t Booking Summary :- ");
        printf("\n       _________________________________________________________________________________\n\n");
        printf("\n\t Bus Name : %s \t\t   Departure Time :  %s \n", ch[Bn - 1], t[Bn - 1]);
        printf("\n\t--------------------------------------------------------------------------------");
        printf("\n\n\t\tSl. No.       Passenger's Name                Seat No.  ");
        printf("\n\t--------------------------------------------------------------------------------\n\n");
        for (int i = 0; i < n; i++)
        {
            ln = strlen(arr[Bn - 1][s[i] - 1]);
            printf("\n\t\t  %d              %s", i + 1, arr[Bn - 1][s[i] - 1]);
            for (int j = 0; j < 15 - ln; j++)
            {
                printf("%c", S);
            }
            printf("\t\t %d", s[i]);
        }
        printf("\n\n\n\t\t\t\t   Total Fare = Rs. %d /-\n", fare);
        printf("\n\t--------------------------------------------------------------------------------\n");
        printf("\n\t\t\t___________ HAVE A SAFE JOURNEY !!! ______________");
        printf("\n       _________________________________________________________________________________");
        getch();
    }
    else
    {
        printf("\n\t\t\tEnter Valid No. Of Tickets ! ");
        getch();
        fflush(stdin);
        booking(arr, ch);
    }
}

void status(char arr[][40][20], char ch[][40], int Bn)
{

    int i, j, k, n = 0;
    if (Bn >= 1 && Bn <= 5)
    {
        system("CLS");
        printf("\t________________________________________________________________________________________________________________\n\n");
        printf("                                      Bus No. %d             %s                                                            \n", Bn, ch[Bn - 1]);
        printf("\t________________________________________________________________________________________________________________\n\n");
        for (i = 0; i < 10; i++)
        {
            printf("\t\t\t   ");
            for (j = 0; j < 4; j++)
            {
                if (k <= 8)
                {
                    if (strcmp(arr[Bn - 1][n], "AVAILABLE") != 0)
                    {
                        printf("0%d.BOOKED  !\t\t", n + 1);
                        n++;
                        k++;
                    }
                    else
                    {
                        printf("0%d.AVAILABLE\t\t", n + 1);
                        n++;
                        k++;
                    }
                }
                else
                {
                    if (strcmp(arr[Bn - 1][n], "AVAILABLE") != 0)
                    {
                        printf("%d.BOOKED  !\t\t", n + 1);
                        n++;
                    }
                    else
                    {
                        printf("%d.AVAILABLE\t\t", n + 1);
                        n++;
                    }
                }
            }
            printf("\n");
        }
        printf("\t________________________________________________________________________________________________________________\n\n");

    }
}

void Bus_status(char arr[][40][20], char ch[][40])
{
    int i, j, k, Bn;
    printf("\n\t\t\t(Bus No.s Are From 1 To 5)");
    printf("\n\n\t\t\tEnter Bus No. :- ");
    scanf("%d", &Bn);
    if (Bn >= 1 && Bn <= 5)
    {
        status(arr, ch, Bn);
        getch();
    }
    else
    {
        printf("\n\n\t\t\tEnter A Valid Bus Serial No ! ");
        getch();
        fflush(stdin);
    }
    menu(arr, ch);
}

void buslist()
{
    system("cls");
    printf("\n\n\n");
    printf("\t==================================================  BUS LIST  ============================================\n\n\n");
    printf("\n\t\t\t________________________________________________________________________________\n");
    printf("\n\t\t\t\t  S.No.\t      Bus Name\t          Departure Timing        Fare ");
    printf("\n\t\t\t________________________________________________________________________________");
    printf("\n\n\t\t\t\t   1.  =>  %s          7:00 AM          Rs. 185 /-      \n", ch[0]);
    printf("\n");
    printf("\t\t\t\t   2.  =>  %s       9:30 AM          Rs. 130 /- \n", ch[1]);
    printf("\n");
    printf("\t\t\t\t   3.  =>  %s           11:15 AM          Rs. 160 /-  \n", ch[2]);
    printf("\n");
    printf("\t\t\t\t   4.  =>  %s          2:00 PM          Rs. 115 /-  \n", ch[3]);
    printf("\n");
    printf("\t\t\t\t   5.  =>  %s         5:30 PM          Rs. 155 /-  \n", ch[4]);
    printf("\n\t\t\t________________________________________________________________________________");
    getch();
}

int Fare(int Bn, int n)
{
    switch (Bn)
    {
    case 1:
        return 185 * n;
        break;
    case 2:
        return 130 * n;
        break;
    case 3:
        return 160 * n;
        break;
    case 4:
        return 115 * n;
        break;
    case 5:
        return 155 * n;
        break;
    default:
        return 0;
    }
}

void login(char arr[][40][20], char ch[][40])
{
    int a = 0, i = 0;
    char uname[10];
    char c = ' ';
    char pword[10];
    char user[10] = "staff0127";
    char pass[10] = "pass0127";
    do
    {
        system("cls");
        printf("");
        printf("\n\n\n  ========================= STAFF LOGIN INTERFACE  =========================  \n\n");
        printf(" \n\t\t\t  ENTER USERNAME :- ");
        scanf("%s", &uname);
        printf(" \n\t\t\t  ENTER PASSWORD :- ");
        while (i < 10)
        {
            pword[i] = getch();
            c = pword[i];
            if (c == 13)
                break;
            else
                printf("*");
            i++;
        }
        pword[i] = '\0';
        i = 0;
        if (strcmp(uname, "staff0127") == 0 && strcmp(pword, "pass0127") == 0)
        {
            printf("  \n\n\n       WELCOME TO OUR SYSTEM !!!  STAFF LOGIN IS SUCCESSFUL\n\n");
            printf("\t");
            system("pause");
            break;
        }
        else
        {
            printf("\n\n\n\t        SORRY !!!!  LOGIN ATTEMPT WAS UNSUCESSFUL");
            a++;
            getch();
        }
    } while (a <= 2);
    if (a > 2)
    {
        printf("\n\n\n\t\tSorry You Have Entered The Wrong Username And Password For Three Times!!!");
        printf("\n\n\n\t\t\tPlease Try After Sometime !");
        getch();
        main_menu(arr, ch);
    }
    system("cls");
}

void menu(char arr[][40][20], char ch[][40])
{
    int num;
    do
    {
        system("cls");
        printf("\n\n\n==================================== WELCOME TO AUTOMATED BUS TICKET VENDING SYSTEM ====================================\n\n\n");
        printf("\t\t\t\t\tPress [1] :- To View Bus List\n");
        printf("\n");
        printf("\t\t\t\t\tPress [2] :- To Book Tickets\n");
        printf("\n");
        printf("\t\t\t\t\tPress [3] :- To View Available Seats\n");
        printf("\n");
        printf("\t\t\t\t\tPress [4] :- To Go Back To Main Menu\n");
        printf("\n");
        printf("========================================================================================================================\n\n");
        printf("\t\t\tEnter Your Choice :-  ");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            buslist();
            break;
        case 2:
            booking(arr, ch);
            break;
        case 3:
            Bus_status(arr, ch);
            break;
        case 4:
            main_menu(arr, ch);
        default:
            printf("Enter A Valid Choice ! ");
        }
    } while (1);
    system("CLS");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\tThank You For Using This Bus Ticket Vending System !\t\t\t\t\t\t\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    getch();
}

void main_menu(char arr[][40][20], char ch[][40])
{
    int c;
    while (1)
    {
        system("CLS");
        printf("\n\n----------------- Welcome to Automated Bus Ticket Vending System -----------------\n");
        printf("\n\n\n\t\t        Press [1] :-  To Continue as User \n\n\n\n\t\t        Press [2] :- To Continue as Staff \n\n\n\n");
        fflush(stdin);
        printf("\t\t\tEnter Your Choice :-  ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            details(arr, ch);
            break;
        case 2:
            Slogin(arr, ch);
            break;
        default:
            printf(" \n\n\t\t\t Please Enter A Valid Choice !");
            getch();
            main_menu(arr, ch);
            break;
        }
    }
}

void cashMethod(int a)
{
    int cash, remaining, change, fare;
    fare = a;
    printf("\n\t\tYou have to pay %d rs.\n", fare);
    printf("\n\t\tEnter the cash amount that you are paying: ");
    scanf("%d", &cash);
    remaining = fare;
    if (cash < fare)
    {
        while (cash < remaining)
        {
            remaining = remaining - cash;
            printf("\n\t\tYou have to give more %d rs to get the tickets.\n", remaining);
            printf("\n\t\tEnter the cash amount that you are paying: ");
            scanf("%d", &cash);
            if (remaining < cash)
            {
                change = cash - remaining;
            }
        }
        printf("\n\t\tYour change is %d rs.\n", change);
        sleep(1.5);
        system("CLS");
    }
    else
    {
        change = cash - fare;
        printf("\n\t\tYour change is %d rs.\n", change);
        sleep(1.5);
        system("CLS");
    }
}

void cardMethod(int a)
{
    char name[20], cvv[4], number[13], date[5];
    int fare;
    fare = a;
    printf("\n\n\t\tYour payment amount is %d rs.\n\n", fare);
    printf("\t\tEnter card holder name: ");
    fflush(stdin);
    gets(name);
    printf("\n\t\tEnter the card number: ");
    scanf("%s", number);
    while (strlen(number) != 12 || !isdigit(number[0]))
    {
        printf("\n\t\tError: Invalid card number format.\n");
        printf("\t\tEnter the valid card number: ");
        scanf("%s", number);
    }
    printf("\n\t\tEnter the expiry date (ex: DD/MM): ");
    scanf("%s", &date);
    while (strlen(date) != 4 || !isdigit(number[0]))
    {
        printf("\n\t\tError: Invalid Expiray date.\n");
        printf("\t\tEnter a valid expiry date: ");
        scanf("%s", &date);
    }
    printf("\n\t\tEnter your CVV: ");
    scanf("%s", cvv);
    while (strlen(cvv) != 3 || !isdigit(cvv[0]))
    {
        printf("\n\t\tError: Invalid CVV format.\n");
        printf("\t\tEnter the valid CVV: ");
        scanf("%s", cvv);
    }
    printf("\n\n\t\tThe payment is processing, please do not press any key...\n");
    sleep(3);
    system("CLS");
}
