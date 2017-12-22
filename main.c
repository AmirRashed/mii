// add libraries which we will need
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define  MIN(x, y) (((x) < (y)) ? (x) : (y))
// create a structure represent the date
struct Date
{
    // parts of date mm=month dd =day yy =year
    int mm,dd,yy;
};
// create a structure for info of the books
struct books
{
    // string contain book title
    char title[20];
    // string contain book author's name
    char author[20];
    // string contain publisher name
    char publisher[20];
    // string contain ISBN of Book
    char isbn[15];
    // internal structure represent Date of publishing of the book
    struct Date b;
    // Total number Of Books in library
    int quantity;
    // Number Of available Books after Borrowing operations
    int avaliablequantity;
    // string contains Category of the book
    char category[20];
    // Number represent how many this book borrowed
    int borrowedtimes;
};
// create a structure represent the address of the member
struct address
{
    // number represent the number of building of the member
    int building;
    // string contain the name of the street
    char st[20];
    // string contain the city
    char city[20];
};
// Create a structure for info of the members
struct member
{
    // string contains first name of the member
    char firstname[20];
    // string contains last name of the member
    char lastname[20];
    // number represent the id of the member
    int ID;
    // internal structure contains an address of the member
    struct address address;
    // float number represent member's number
    float phonenumber;
    // number represent age of the member
    int age;
    // string contains email of the member
    char email[20];
    // number represent the number of book that the member borrowing now (maximum=3)
    int borrowedbooksno;
};

// create a structure for info of borrowing operations
struct borrowed
{
    // string contains the ISBN of the book Borrowed
    char bisbn[15];
    // number represent the ID of the member who has borrowed the book
    int UserID;
    // internal structure represent the Date of borrowing operation
    struct Date dborrowed;
    // internal structure represent the date when the member has to return a book at
    struct Date duedate;
    // internal structure represent the date when the member had returned the book
    struct Date returned;
    // number that represent the book had been returned or not (1->not returned yet) (0-> the book had been returned)
    int flag;

};
// create an array of structure book and define capacity of the library
struct books b[1000];
// create an array of structure member and define capacity of the library
struct member m[500];
// create an array of structure borrowed and define capacity of the library
struct borrowed br[1000];
// number that represent number of books we have in library
int counterbooks=0;
// number that represent number of members we have in library
int countermembers=0;
// number that represent number of borrowing operations we have in library
int counterborrowed=0;
// create a main menu of the program
int main ()

{
     loadborrowed ();
     fflush(stdin);
     loadmembers ();
     fflush(stdin);
     loadbooks ();
    mainmenu(); return 0;
}
void mainmenu ()
{    popularbooks();
     fflush(stdin);
    char n='0';
    char x='0';
    int flag=0;
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
    printf("\xDB\xB2 Book Management (1) \n\xDB\xB2 Member Management (2) \n\xDB\xB2 Borrow Management (3) \n\xDB\xB2 Administrative actions (4) \n\xDB\xB2 Save changes (5) \n\xDB\xB2 print all (6) \n\xDB\xB2 Exit (7)  ");
    x=getch();

switch (x)
{
     case '1':
     LINE96532:
     system("cls");
     if (flag)
     {printf("***wrong input***\n");
     flag=0;}
     printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Library System");
     printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
     printf("\n\xDB\xB2 Insert (1) \n\xDB\xB2 search (2) \n\xDB\xB2 add new copies (3) \n\xDB\xB2 delete (4) \n\xDB\xB2 edit (5)\n\xDB\xB2 back (6) \n ");
     n=getch();
      if(n=='1')
      {addbook ();}
      if (n=='2')
      {searchbook();}
      if (n=='3')
      {addnewcopies ();}
      if (n=='4')
      {removebook ();}
      if (n=='5')
      {editbook();}
      if (n=='6')
      {system("cls");mainmenu();}
      if (n>'6' || n<'1')
      {flag=1;goto LINE96532;}
      break;
      case '2':
      flag=0;
      LINE2:
      system("cls");
      if (flag)
      {printf("***wrong input***\n");
      flag=0;}
      printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Library System");
      printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
      printf("\n\xDB\xB2 Register (1) \n\xDB\xB2 remove (2)\n\xDB\xB2 back (3)");

      n=getch();
      if (n=='1')
      {addmember();}
      if (n=='2')
      {deletemember ();}
      if (n=='3')
      {system("cls");mainmenu();}
      if (n>'3' || n<'1')
        {flag=1;goto LINE2;}
     break;
     case '3':
      flag=0;
      LINE3:
      system("cls");
      if (flag)
      {printf("***wrong input***\n");
      flag=0;}
      printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Library System");
      printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
      printf("\n%d\n",counterborrowed);
      printf("\n\xDB\xB2 Borrow (1) \n\xDB\xB2 return (2)\n\xDB\xB2 back (3)");
      n=getch();
      if (n=='1')
      {newborrowing();}
      if (n=='2')
      {returnbook();}
      if (n=='3')
      {system("cls");mainmenu();}
     if (n>'3' || n<'1')
      {flag=1;goto LINE3;}
      break;
     case '4':
     flag=0;
      LINE4:
      system("cls");
      if (flag)
      {printf("***wrong input***\n");
      flag=0;}
     printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Library System");
     printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
     printf("\n\xDB\xB2 overdue (1) \n\xDB\xB2 popular (2)\n\xDB\xB2 back (3)\n");
     n=getch();
     if (n=='1')
     {overdue ();}
     if (n=='2')
     {popularbooks ();}
    if (n=='3')
     {system("cls");mainmenu();}
     if (n>'3' || n<'1')
      {flag=1;goto LINE4;}
      break;
     case '5':
     system("cls");
     savemembers ();
     saveborrow ();
     savebooks ();
     printf("***the data has been saved***\n");
     getch();
     mainmenu();
     break;
     case '6':
     flag=0;
      LINE6:
      system("cls");
      if (flag)
      {printf("***wrong input***\n");
      flag=0;}
     printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 print all");
     printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
     printf("\n\xDB\xB2 Print all Books (1) \n\xDB\xB2 Print all members (2)\n\xDB\xB2 Print all borrowing (3)\n\xDB\xB2 back (4)");
     n=getch();
     if (n=='1')
     {PrintAllBooks ();}
     if (n=='2')
     {PrintAllMembers ();}
     if (n=='3')
     {PrintAllBorrowing ();}
     if (n=='4')
     {system("cls");mainmenu();}
     if (n>'4' || n<'1')
      {flag=1;goto LINE6;}
      break;

     case '7':
     flag=0;
      LINE7:
      system("cls");
      if (flag)
      {printf("***wrong input***\n");
      flag=0;}
     printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Exit");
     printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
     printf("\n\xDB\xB2 Exit with save (1) \n\xDB\xB2 Exit without save (2)\n\xDB\xB2 Back (3)");
     n=getch();
     if (n=='1')
     {
     savemembers ();
     saveborrow ();
     savebooks ();
     exit(0);
     }
     if (n=='2')
     {exit(0);}
     if (n=='3')
      {system("cls");mainmenu();}
     if (n>'3' || n<'1')
      {flag=1;goto LINE7;}
      break;
      /****/

     default:

     system("cls");
     printf("***wrong input please try again***\n");
     mainmenu();
     break;
}
}
//
void addbook ()
{
    system("cls");
    char sisbn[15];int i,flag=0;
    printf("\n\t\t   Book Addition Menu:");
    printf("\n\n\tThis will add the contents to database.\n");
    printf("\nwe have %d books in database\n",counterbooks);
    printf("\nenter Book ISBN : ");
    line55:
    gets(sisbn);
    if (strlen(sisbn)<10)
    {printf(" \n**ISBN must be greater than 10 digits**\n ISBN :- ");goto line55;}
   if(!checkdigit (sisbn))
    {printf(" \n**ISBN must contain only digits**\n ISBN :- ");goto line55;}
   for (i=0;i<counterbooks;i++)
        if (!strcmp(sisbn,b[i].isbn))
        {
            printf("the ISBN is already exist\npress any key to back to mainmenu");
            getch();
            system("cls");
            mainmenu();
            return;
        }
    strcpy(b[counterbooks].isbn,sisbn);
    printf("Enter Book title : ");
    gets(b[counterbooks].title);
    for(i = 0; b[counterbooks].title[i]; i++)
          b[counterbooks].title[i] = tolower(b[counterbooks].title[i]);
    line44:
    printf("Enter Author's name = ");
    gets(b[counterbooks].author);
    if (!checkalpha(b[counterbooks].author))
    {
        printf(" \n**author's name must't contain digits or symbols**\n ");
        goto line44;
    }
    for(i = 0; b[counterbooks].author[i]; i++)
          b[counterbooks].author[i] = tolower(b[counterbooks].author[i]);
    line46:
    printf("Publisher: ");
    gets(b[counterbooks].publisher);
    if (!checkalpha(b[counterbooks].publisher))
    {
        printf(" \n**publisher's name must't contain digits or symbols**\n ");
        goto line46;
    }
    for(i = 0; b[counterbooks].publisher[i]; i++)
          b[counterbooks].publisher[i] = tolower(b[counterbooks].publisher[i]);

    printf("enter Publication Date day-month-year : ");
    int flag1=0;
    while (!flag1)
    {scanf("%d",&b[counterbooks].b.dd);

    if (b[counterbooks].b.dd>31 || b[counterbooks].b.dd <0 )
        printf("day must be postive number less than 31 :- ");
        else flag1=1;
    }
    flag1=0;
    while (!flag1)
    {scanf("%d",&b[counterbooks].b.mm);
    if (b[counterbooks].b.mm>12 || b[counterbooks].b.mm <0)
        printf("month must postive number be less than 12 :- ");
        else flag1=1;
    }
    line24:
    scanf("%d",&b[counterbooks].b.yy);
    if (b[counterbooks].b.yy <0)
    {
        printf("\n**month must postive number**\n enter year :");
        goto line24;
    }
    line35:
    printf("total quantity: ");
    scanf("%d",&b[counterbooks].quantity);
    if (b[counterbooks].quantity<0)
        {printf("total quantity must be a postive number");goto line35;}
    b[counterbooks].avaliablequantity=b[counterbooks].quantity;
     line1000:
     printf("Enter category = ");
     fflush(stdin);
    gets(b[counterbooks].category);
    if (!checkalpha(b[counterbooks].category))
    {
        printf(" \n**category must't contain digits or symbols**\n ");
        goto line1000;
    }
       for(i = 0; b[counterbooks].category[i]; i++)
          b[counterbooks].category[i] = tolower(b[counterbooks].category[i]);
      b[counterbooks].borrowedtimes=0;
    counterbooks++;
    char choice;
    printf("\n\n\tEnter another record : ");
    printf("\n\n\tPress 'y' to enter another record.\n\tPress any other key to return to main menu.\n\n");
    printf("\tChoice = ");
    choice = getch();

    if (choice == 'y' || choice == 'Y')
    {
        addbook();
    }
    else
        system("cls");
        mainmenu();
}
int checkdigit (char *ch )
{
    int i,flag=0;
    for (i=0;i<strlen(ch);i++)
    {
        if (!isdigit(*(ch+i)))
        {flag=1;break;}
    }
    if (flag) return 0;
    else return 1;
}

int checkalpha (char *ch )
{
    int i,flag=0;
    for (i=0;i<strlen(ch);i++)
    {
        if (*(ch+i)==' ')
            continue;
        if (!isalpha(*(ch+i)))
        {flag=1;break;}
    }
    if (flag) return 0;
    else return 1;
}


void editbook()
{
    char sISBN[15];int target,i,flag=0;
    system("cls");
    printf("\n\t\t  Modify a Record :");
    printf("\n\n\tThis will modify the contents of the record\n\tin Book_DB Database.\n\n");

    printf("\n\t ISBN of the Book = ");
    gets(sISBN);
    for (i=0;i<counterbooks;i++)
    {
        if (!strcmp(sISBN,b[i].isbn))
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        printf("\n\tBook with ISBN '%s' is not present in  database.\n\n", sISBN);
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;

    }
    else
    {
        target=i;
    }
    printf("\n\t%c Book#%d : \n", 254, ++i);

            printf("\n\ttile       = %s", b[target].title);
            printf("\n\tAuthor     = %s", b[target].author);
            printf("\n\tPublisher     = %s", b[target].publisher);
            printf("\n\tPublicationDate      = %d-%d-%d", b[target].b.dd,b[target].b.mm,b[target].b.yy);
            printf("\n\tISBN       = %s", b[target].isbn);
            printf("\n\tquantity    = %d", b[target].quantity);
            printf("\n\tavaliable Quantity   = %d\n\n", b[target].avaliablequantity);
            printf("\n\tcategory   = %s\n\n", b[target].category);
            printf("\n\tModify this record : ");
            printf("\n\n\tPress 'y' to modify this record.\n\tPress any other key to return to main menu.\n\n");
            printf("\tChoice = ");
            char choice = getch();

            // new data is received on approval
            if(choice == 'y' || choice == 'Y')
            {
                system("cls");

                printf("\n\t\t   Modify a Record :");
                printf("\n\n\tThis will alter the contents of database.\n");
                printf("\n\n\tBook Name : %s\n", b[target].title);
                printf("\n\tEnter the Updated Info:\n");
                printf("\t title = ");
                gets(b[target].title);
                for(i = 0; b[counterbooks].title[i]; i++)
                b[counterbooks].title[i] = tolower(b[counterbooks].title[i]);
                printf("\tAuthor = ");
                gets(b[target].author);
                for(i = 0; b[counterbooks].author[i]; i++)
                b[counterbooks].author[i] = tolower(b[counterbooks].author[i]);
                printf("\tISBN = ");
                gets(b[target].isbn);
                printf("\tpublisher = ");
                gets(b[target].publisher);
                for(i = 0; b[counterbooks].publisher[i]; i++)
                b[counterbooks].publisher[i] = tolower(b[counterbooks].publisher[i]);
                printf("\t quantity  = ");
                scanf("%d",&b[target].quantity);
                printf("\t avaliable Quantity = ");
                scanf("%d",&b[target].avaliablequantity);
                printf("\tcategory = ");
                gets(b[target].category);
                gets(b[target].category);
            }

        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;
        }
    void searchbook()
{    system("cls");
     printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Search ");
     printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
     printf("\n\xDB\xB2 by book title  (1) \n\xDB\xB2 by ISBN (2) \n\xDB\xB2 by category (3) \n\xDB\xB2 by author (4) \n enter : ");
     char o='0';
     o=getch();
     if (o=='1')
     {titlesearch();}
     if(o=='2')
     {ISBNsearch();}
     if(o=='3')
     {categorysearch();}
     if (o=='4')
     {Authorsearch();}
}
void ISBNsearch ()
{
    char sISBN[15]; int i,flag=0;
    printf("\n\xDB\xB2 enter ISBN :");
    gets(sISBN);
    for (i=0;i<counterbooks;i++)
    {
        if (!strcmp(sISBN,b[i].isbn))
        {
            flag=1;
            break;
        }
    }
    if (!flag)
    {
        printf("\n\tBook with ISBN '%s' is not present in database.\n\n", sISBN);
        printf("\n\t Press any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;

    }
    else
    {
        int target=i;

    printf("\n\t%c Book#%d : \n", 254, ++i);

            printf("\n\ttile       = %s", b[target].title);
            printf("\n\tAuthor     = %s", b[target].author);
            printf("\n\tPublisher     = %s", b[target].publisher);
            printf("\n\tPublicationDate      = %d-%d-%d", b[target].b.dd,b[target].b.mm,b[target].b.yy);
            printf("\n\tISBN       = %s", b[target].isbn);
            printf("\n\tquantity    = %d", b[target].quantity);
            printf("\n\tavaliable Quantity   = %d", b[target].avaliablequantity);
            printf("\n\tcategory   = %s\n\n", b[target].category);
    }
    printf("to Back to mainmenu press any key");
    getch();
    system("cls");
    mainmenu();
    return;

}
void Authorsearch ()
{
    char sAuthor[20];
    int counter=1,i;
    printf("\n\xDB\xB2 enter Author name :");
    gets(sAuthor);
    for(i = 0; sAuthor[i]; i++)
          sAuthor[i] = tolower(sAuthor[i]);
    for (i=0;i<counterbooks;i++)
    {
        if (strcmp(b[i].author,sAuthor)==0)
        {
            printf("\n\t the book %d : \n",counter);
            printf("\n\ttile       = %s", b[i].title);
            printf("\n\tAuthor     = %s", b[i].author);
            printf("\n\tPublisher     = %s", b[i].publisher);
            printf("\n\tPublicationDate      = %d-%d-%d", b[i].b.dd,b[i].b.mm,b[i].b.yy);
            printf("\n\tISBN       = %s", b[i].isbn);
            printf("\n\tquantity    = %d", b[i].quantity);
            printf("\n\tavaliable Quantity   = %d", b[i].avaliablequantity);
            printf("\n\tcategory   = %s\n\n", b[i].category);
            counter++;

        }

    }
    if (counter!=1)
    {printf("\n\t Press any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;}
    if (counter==1)
    {
        printf("\n\tthe Author '%s' is not present in database.\n\n", sAuthor);
        printf("\n\t Press any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;
    }
}
void categorysearch ()
{
    char scategory[20];
    int counter=1,i;
    printf("\n\xDB\xB2 enter category :");
    gets(scategory);
    for(i = 0; scategory[i]; i++)
          scategory[i] = tolower(scategory[i]);
    for (i=0;i<counterbooks;i++)
    {
        if (strcmp(b[i].category,scategory)==0)
        {
            printf("\n\t the book %d : \n",counter);
            printf("\n\ttile       = %s", b[i].title);
            printf("\n\tAuthor     = %s", b[i].author);
            printf("\n\tPublisher     = %s", b[i].publisher);
            printf("\n\tPublicationDate      = %d-%d-%d", b[i].b.dd,b[i].b.mm,b[i].b.yy);
            printf("\n\tISBN       = %s", b[i].isbn);
            printf("\n\tquantity    = %d", b[i].quantity);
            printf("\n\tavaliable Quantity   = %d", b[i].avaliablequantity);
            printf("\n\tcategory   = %s\n\n", b[i].category);
            counter++;

        }

    }
    if (counter!=1)
    {printf("\n\t Press any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;}
    if (counter==1)
    {
        printf("\n\tthe category '%s' is not present in database.\n\n", scategory);
        printf("\n\t Press any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;
    }
}
void titlesearch ()
{

    system("cls");
    char st[20];
    int i;
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 search by title  ");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
    printf("enter the title or part of it : ");
    gets(st);
    for(i = 0; st[i]; i++)
          st[i] = tolower(st[i]);
    int counter=1;
    for (i=0;i<counterbooks;i++)
    {
        if (strstr(b[i].title, st)!=NULL)
        {
            printf("\n\t the book %d : \n",counter);
            printf("\n\ttile       = %s", b[i].title);
            printf("\n\tAuthor     = %s", b[i].author);
            printf("\n\tPublisher     = %s", b[i].publisher);
            printf("\n\tPublicationDate      = %d-%d-%d", b[i].b.dd,b[i].b.mm,b[i].b.yy);
            printf("\n\tISBN       = %s", b[i].isbn);
            printf("\n\tquantity    = %d", b[i].quantity);
            printf("\n\tavaliable Quantity   = %d", b[i].avaliablequantity);
            printf("\n\tcategory   = %s\n\n", b[i].category);
            counter++;

        }

    }
     printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;
}
void addnewcopies ()
{
   system("cls");
   printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 add new copies ");
   printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
   int sISBN,i,flag=0;
    printf("\n\xDB\xB2 enter ISBN :");
    gets(sISBN);
    for (i=0;i<counterbooks;i++)
    {
        if (!strcmp(sISBN,b[i].isbn))
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        printf("\n\tBook with ISBN '%d' is not present in database.\n\n", sISBN);
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;
    }
    else
    {   int x=0;
        int target=i;
        int h=b[target].quantity;
        printf("\ntotal quantity now = %d , enter the quantity after icrement : ",h);

        do
        {
            scanf("%d",&b[target].quantity);
            if (b[target].quantity>=0)
                x=1;
            else
              printf("\nthe quantity must be a postive number , try again :");
        }while (x!=1 || b[target].quantity<0 );
        b[target].avaliablequantity+=b[target].quantity-h;


        printf("now total quantity = %d \n and the avaiable quantity = %d\n\tPress any key to back to mainmenu",b[target].quantity,b[target].avaliablequantity);
        getch();
        system("cls");
        mainmenu();
        return;
    }
}

void removebook ()
{
    system("cls");
   printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 remove a book ");
   printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
   char sISBN[15];int i,flag=0;
    printf("\n\xDB\xB2 enter ISBN :");
    gets(sISBN);
    for (i=0;i<counterbooks;i++)
    {
        if (!strcmp(sISBN,b[i].isbn))
        {
            flag=1;
            break;
        }
    }
    if (!flag)
    {
        printf("\n\tBook with ISBN '%s' is not present in database.\n\n", sISBN);
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;

    }
    else
    {

        int target=i;

          printf("\n\t the book : \n");

            printf("\n\ttile       : %s", b[target].title);
            printf("\n\tAuthor     : %s", b[target].author);
            printf("\n\tPublisher     : %s", b[target].publisher);
            printf("\n\tPublicationDate      : %d-%d-%d", b[target].b.dd,b[target].b.mm,b[target].b.yy);
            printf("\n\tISBN       : %s", b[target].isbn);
            printf("\n\tquantity    : %d", b[target].quantity);
            printf("\n\tavaliable Quantity   : %d", b[target].avaliablequantity);
            printf("\n\tcategory   : %s\n\n", b[target].category);
            printf("\n\tModify this record : ");
            printf("\n\n\tPress 'y' to delete this record.\n\tPress any other key to return to main menu.\n\n");
            printf("\tChoice = ");
            char choice = getch();
            if(choice == 'y' || choice == 'Y')
            {
            for (i=0;i<counterborrowed;i++)
            {
                 if (strcmp(br[i].bisbn,sISBN)==0 && br[i].returned.yy==0 )
                 {
                   system("cls");
                   printf("\n\n\n\t**book cant be deleted because there is a copy from it unreturened**\n\n");
                   printf("\n\tPress any key to back to mainmenu");
                   getch();
                   system("cls");
                   mainmenu();
                   return;

                 }
            }
            for (i=target;i<counterbooks-2;i++)
            b[i] = b[i+1];
            counterbooks--;
            system("cls");
            printf("\n***the book has been deleted***\n");
            mainmenu();
            return;
            }
    else
    {
         system("cls");
        mainmenu();
        return;
    }
    }
}

void addmember()
{
    system("cls");
    int x;
     printf("\n\t\t   member Addition Menu:");
    printf("\n\n\tThis will add the contents to members database.\n");
    printf("we have %d members in database \n",countermembers);
    printf("\nenter member ID : ");
    scanf("%d",&x);
    if (checkID(x))
    {
     printf("the ID is already exist\npress any key to back to mainmenu");
     getch();
        system("cls");
        mainmenu();
        return;
    }
    else {
    m[countermembers].ID=x;
    line404:
    printf("\nEnter first name = ");
    fflush(stdin);
    gets(m[countermembers].firstname);
    if (!checkalpha(m[countermembers].firstname))
    {
        printf(" \n**member's name must't contain digits or symbols**\n ");
        goto line404;
    }
    line40955:
    printf("Enter last name = ");
    gets(m[countermembers].lastname);
    if (!checkalpha(m[countermembers].lastname))
    {
        printf(" \n**member's name must't contain digits or symbols**\n ");
        goto line40955;
    }
    printf("email: ");
    int flag4=0,i;
     do
     {
         gets(m[countermembers].email);
         int len=strlen(m[countermembers].email);
         if(m[countermembers].email[len-1]=='m' || m[countermembers].email[len-1]=='M' && m[countermembers].email[len-2]=='o' || m[countermembers].email[len-2]=='O' && m[countermembers].email[len-3]=='c' || m[countermembers].email[len-3]=='C'&& m[countermembers].email[len-4]=='.')
           {flag4++;
            for (i=0;i<len;i++)
                if (m[countermembers].email[i]=='@')
                flag4++;
           }else {flag4=0;printf("the email is wrong \n please try again :-");}

     }while(flag4 !=2);

    printf("age: ");
    int flags=0;
    do{
    scanf("%d",&m[countermembers].age);
    if (m[countermembers].age<0)
    {printf("his age must be postive :-  ");}
    else flags=1;
    }while(flags==0);
    printf("phone number: ");
    float sphone;
    int flagp=0;
    do { scanf("%f",&sphone);
        if (1000000000<sphone)
        flagp++;
        else
        {
            printf("phone no is not correct :-   ");
            flagp=0;
        }}while(flagp!=1);

    m[countermembers].phonenumber=sphone;

    printf("enter the adress building number - street -city \n ");
    int flagx=0;
    do{
    scanf("%d",&m[countermembers].address.building);
    if (m[countermembers].address.building<0)
    {printf("building no must be a postive number\n");}
    else flagx=1;
    }while(flagx==0);
    line4098:
    printf("\nstreet : ");
    fflush(stdin);
    gets(m[countermembers].address.st);
    if (!checkalpha(m[countermembers].address.st))
    {
        printf(" \n**street's name must't contain digits or symbols**\n ");
        goto line4098;
    }
    line4097:
    printf("\ncity : ");
    gets(m[countermembers].address.city);
    m[countermembers].borrowedbooksno=0;
    if (!checkalpha(m[countermembers].address.city))
    {
        printf(" \n**city's name must't contain digits or symbols**\n ");
        goto line4097;
    }
    m[countermembers].borrowedbooksno=0;
    countermembers++;
    char choice;
    printf("\n\n\tEnter another record : ");
    printf("\n\n\tPress 'y' to enter another record.\n\tPress any other key to return to main menu.\n\n");
    printf("\tChoice = ");
    choice = getch();

    if (choice == 'y' || choice == 'y')
    {
        addmember();
    }
    else
        system("cls");
        mainmenu();

    }
    }
    int checkID (int x)
{
    int i,flag=0;

    for (i=0;i<countermembers;i++)
      if (m[i].ID==x)
      {
          flag=1;
      }
      if (flag==0)
         return 0;
      if (flag==1)
         return 1;

}
void deletemember ()
{    system("cls");
   printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 remove a member ");
   printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
   int sID,i,flag=0;
    printf("\n\xDB\xB2 enter ID :");
    scanf("%d",&sID);
    for (i=0;i<countermembers;i++)
    {
        if (sID==m[i].ID)
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        printf("\n\t meber with ID '%d' is not present in database.\n\n", sID);
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;

    }
    else
    {


        int target=i;

          printf("\n\t the member info. : \n");

            printf("\n\tfirst name      = %s", m[target].firstname);
            printf("\n\tlast name     = %s", m[target].lastname);
            printf("\n\tID     = %d", m[target].ID);
            printf("\n\taddress      = %d-%s-%s", m[target].address.building,m[target].address.st,m[target].address.city);
            printf("\n\tphonenumber       = 0%.0f", m[target].phonenumber);
            printf("\n\tage    = %d", m[target].age);
            printf("\n\temail   = %s\n\n", m[target].email);
            printf("\n\tModify this record : ");
            printf("\n\n\tPress 'y' to delete this record.\n\tPress any other key to return to main menu.\n\n");
            printf("\tChoice = ");
            char choice = getch();
            if(choice == 'y' || choice == 'Y')
            {

            if (m[target].borrowedbooksno)
            {   system("cls");
                printf("\n***member can't be deleted because he has a book must be returned***\n");
                mainmenu();
                return;
            }

        for (i=target;i<counterbooks-2;i++)
        {
            m[i]=m[i+1];
        }

                countermembers--;
                system("cls");
                printf("\n***the member has been deleted***\n");
                mainmenu();
                return;

            }
    else
    {
         system("cls");
        mainmenu();
        return;
    }
}
}

void newborrowing ()
{
    int sID,i,flag=0;
    system("cls");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 new borrowing");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
    printf("\n\xDB\xB2 enter ID :");
    scanf("%d",&sID);
    for (i=0;i<countermembers;i++)
    {
        if (sID==m[i].ID)
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        printf("\n\t member with ID '%d' is not present in database.\n\n", sID);
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;

    }
    else
    {

        int target=i;
        if (m[target].borrowedbooksno==3)
        {
            printf("\n\t member has the maximum number of borrowing.\n\n");
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;
        }
        else
            printf("\n\xDB\xB2 Book ISBN: ");
            char sisbn[15];
            fflush(stdin);
            gets(sisbn);
            flag=0;
            for (i=0;i<counterbooks;i++)
    {
        if (!strcmp(sisbn,b[i].isbn))
        {
            flag=1;
            break;
        }
    }int btareget=i;
    if (flag==0)
    {
        printf("\n\t the book with ISBN '%s' is not present in database.\n\n", sisbn);
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;


    }
    else
    {    for (i=0;i<counterborrowed+1;i++)
             if (sID==br[i].UserID && strcmp(sisbn,br[i].bisbn)==0 && br[i].flag==1 )
                {
                  printf("\n\t member already has this book \n\n");
                  printf("\n\tPress any key to back to mainmenu");
                  getch();
                  system("cls");
                  mainmenu();
                  return;
                }

            strcpy(br[counterborrowed].bisbn,sisbn);
            br[counterborrowed].UserID=sID;
            int flager=0;
            do{
            printf("enter borrowed Date day-month-year :\n ");
            int flag1=0;
            while (flag1==0)
            {printf("day : ");scanf("%d",&br[counterborrowed].dborrowed.dd);
            if (br[counterborrowed].dborrowed.dd>31 || br[counterborrowed].dborrowed.dd<=0 )
            printf("day must be postive number less than 31 :- ");
            else flag1=1;
            }
            flag1=0;
            while (flag1==0)
            {
                printf("month : ");scanf("%d",&br[counterborrowed].dborrowed.mm);
            if (br[counterborrowed].dborrowed.mm>12 || br[counterborrowed].dborrowed.mm<=0 )
            printf("month must be postive number less than 12 :- ");
            else flag1=1;
            }
            printf("year : ");
            scanf("%d",&br[counterborrowed].dborrowed.yy);
            if (br[counterborrowed].dborrowed.dd+30*br[counterborrowed].dborrowed.mm+365*br[counterborrowed].dborrowed.yy>b[btareget].b.dd+30*b[btareget].b.mm+365*b[btareget].b.yy)
            {
                flager=1;
            }
            else
            {
                printf("the borrowed date must be greater than publish date \n ");
            }
            }while (flager==0);
            flager=0;
            do{
            printf("enter due date Date day-month-year :\n ");
            int flag1=0;
            while (flag1==0)
            {printf("day : ");scanf("%d",&br[counterborrowed].duedate.dd);
            if (br[counterborrowed].duedate.dd>31)
            printf("day must be postive number less than 31 : ");
            else flag1=1;
            }
            flag1=0;
            while (flag1==0)
            {printf("month : ");scanf("%d",&br[counterborrowed].duedate.mm);
            if (br[counterborrowed].duedate.mm>12)
            printf("month must be postive number less than 12 : ");
            else flag1=1;
            }printf("year : ");
            scanf("%d",&br[counterborrowed].duedate.yy);
            if (br[counterborrowed].duedate.dd+30*br[counterborrowed].duedate.mm+365*br[counterborrowed].duedate.yy>br[counterborrowed].dborrowed.dd+30*br[counterborrowed].dborrowed.mm+365*br[counterborrowed].dborrowed.yy)
            {
                flager=1;
            }
            else
            {
                printf("the date must be greater than borrowed date \n ");
            }
            }while (flager==0);
            br[counterborrowed].flag=1;
            counterborrowed++;
            m[target].borrowedbooksno++;
            b[btareget].avaliablequantity--;
            b[btareget].borrowedtimes++;
            printf("\n\t Press any key to back to mainmenu");
            getch();
            system("cls");
            mainmenu();
            return;
    }
    }
    }

void returnbook()
{
    system("cls");
    int sID,i,flag=0;
    char sISBN[15];
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 return book");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
    printf("\n\xDB\xB2 enter student ID :");
    scanf("%d",&sID);
    printf("\n\xDB\xB2 enter Book ISBN :");
    fflush(stdin);
    gets(sISBN);
        for (i=0;i<counterborrowed;i++)
    {
        if (sID==br[i].UserID && strcmp(sISBN,br[i].bisbn)==0 && br[i].flag==1 )
        {
            flag=1;
            break;
        }
    }
    if (!flag)
    {
        printf("\n\t member with ID '%d' is not having this book \n\n", sID);
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;

    }
    else
    {
        int targetbr=i,targetm,targetb;
     printf("enter borrowed Date day-month-year :\n ");
     int flag1=0;
    while (flag1==0)
    {scanf("%d",&br[targetbr].returned.dd);
    if (br[targetbr].returned.dd>31)
        printf("day must be less than 31 :- ");
        else flag1=1;
    }
    flag1=0;
    while (flag1==0)
    {scanf("%d",&br[targetbr].returned.mm);
    if (br[targetbr].returned.mm>12)
        printf("month must be less than 12 :- ");
        else flag1=1;
    }
    scanf("%d",&br[targetbr].returned.yy);
     flag=0;
     for (i=0;i<countermembers;i++)
     { if (sID==m[i].ID)
         {
             flag=1;
             break;
         }
     }
     if (!flag)
     {
         printf("\n\t member with ID '%d' is not present in database.\n\n", sID);
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;
     }
     else
     { targetm=i;
     flag=0;
         for (i=0;i<counterbooks;i++)
     {

         if (!strcmp(sISBN,b[i].isbn))
         {
             flag=1;
             break;

         }
     }
     if (flag==0)
     {
         printf("\n\t the book with ISBN '%s'is not present in database.\n\n", sISBN);
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;
     }
     else
     {
       m[targetm].borrowedbooksno--;
       b[i].avaliablequantity++;
       br[targetbr].flag=0;
       printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;
    }
    }
    }
}

int GetBookISBN (char *x)
{   int i,flag=0;
    for (i=0;i<counterbooks;i++)
        if (strcmp(x,b[i].isbn))
    {flag=1; break;}
    if (flag) return i;
    else return 0;
}
void overdue ()
{   system("cls");
    int i,flager=0,counter=1;
    time_t     now;
    struct tm *ts;
    char       buf[80];
    now = time(NULL);
    ts = localtime(&now);
    int x,y,k;
    for (i=0;i<counterborrowed;i++)
    {
        x=ts->tm_mday+30*((ts->tm_mon)+1)+365*(ts->tm_year+1900);
        y=br[i].duedate.dd+30*br[i].duedate.mm+365*br[i].duedate.yy;
        k=GetBookISBN (br[i].bisbn);
        if (x>y && flager==0 && br[k].returned.yy==0 )
        {


            printf("\n\t the book %d : \n",counter);
            printf("\n\ttile       = %s", b[k].title);
            printf("\n\tAuthor     = %s", b[k].author);
            printf("\n\tPublisher     = %s", b[k].publisher);
            printf("\n\tPublicationDate      = %d-%d-%d", b[k].b.dd,b[k].b.mm,b[k].b.yy);
            printf("\n\tISBN       = %s", b[k].isbn);
            printf("\n\tquantity    = %d", b[k].quantity);
            printf("\n\tavaliable Quantity   = %d", b[k].avaliablequantity);
            printf("\n\tcategory   = %s", b[k].category);
            counter++;
            flager=1;
        }
        if (flager==0)
        {

            printf("there isn't book overdued");
        }
        flager=0;
    }
    printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;

}

void PrintAllBooks ()
{
    int i,counter=1;

    for (i=0;i<counterbooks;i++)
    {
            printf("\n\t the book %d : \n",counter);
            printf("\n\ttile       = %s", b[i].title);
            printf("\n\tAuthor     = %s", b[i].author);
            printf("\n\tPublisher     = %s", b[i].publisher);
            printf("\n\tPublicationDate      = %d-%d-%d", b[i].b.dd,b[i].b.mm,b[i].b.yy);
            printf("\n\tISBN       = %s", b[i].isbn);
            printf("\n\tquantity    = %d", b[i].quantity);
            printf("\n\tavaliable Quantity   = %d", b[i].avaliablequantity);
            printf("\n\tcategory   = %s\n\n", b[i].category);
            counter++;
    }
     printf("press any key to back mainmenu ");
    getch();
    system("cls");
    mainmenu();
    return;
}
void PrintAllMembers ()
{   int counter=1,i;
    for (i=0;i<countermembers;i++)
    {
            printf("\n\t the member #%d : \n",counter);
            printf("\n\tfirstname       = %s", m[i].firstname);
            printf("\n\tlastname     = %s", m[i].lastname);
            printf("\n\tID     = %d", m[i].ID);
            printf("\n\tAdress      = %d-%s-%s", m[i].address.building,m[i].address.st,m[i].address.city);
            printf("\n\tphonenumber       = 0%.0f", m[i].phonenumber);
            printf("\n\tage    = %d", m[i].age);
            printf("\n\tbook borrowing   = %d", m[i].borrowedbooksno);
            printf("\n\temail   = %s\n\n", m[i].email);
            counter++;
    }
     printf("press any key to back mainmenu ");
    getch();
    system("cls");
    mainmenu();
    return;
}
void PrintAllBorrowing ()
{
    int counter=1,i,l,k;
    for (i=0;i<counterborrowed;i++)
    {       k= Getisbn (br[i].bisbn);
            l= Getmemberid (br[i].UserID);
            printf("\n\t the borrowing #%d : \n",counter);
            printf("\n\t id of member       = %d", br[i].UserID);
            printf("\n\t book title       = %s", b[k].title);
            printf("\n\t his firstname       =%s",m[l].firstname);
            printf("\n\t borrowed date     = %d-%d-%d", br[i].dborrowed.dd,br[i].dborrowed.mm,br[i].dborrowed.yy);
            printf("\n\t duedate date     = %d-%d-%d", br[i].duedate.dd,br[i].duedate.mm,br[i].duedate.yy);
            if (br[i].flag==0)
                printf("\n\t returned date     = %d-%d-%d\n", br[i].returned.dd,br[i].returned.mm,br[i].returned.yy);
            else
                printf("\nthe book didn't returned yet\n");
            counter++;
    }
     printf("press any key to back mainmenu ");
    getch();
    system("cls");
    mainmenu();
    return;
}

int Getisbn (char *x)
{   int i,flag=0;
    for (i=0;i<counterbooks;i++)
        if (!strcmp(x,b[i].isbn))
    {flag=1; break;}
    if (flag) return i;
    else return 0;
}
int Getmemberid (int x)
{   int i,flag=0;
    for (i=0;i<countermembers;i++)
        if (x==m[i].ID)
    {flag=1; break;}
    if (flag) return i;
    else return 0;
}
void popularbooks ()
{   int i,j;
    struct books temp[counterbooks];
    struct books k;
    for(i=0;i<counterbooks;i++)
        {temp[i] = b[i];}
     for(i=0; i<counterbooks-1; i++)
    {for(j=0; j<counterbooks-i-1; j++)
        {
            if(temp[j].borrowedtimes < temp[j+1].borrowedtimes)
            {
                k = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = k;
            }
        }
    }
    printf("Popular books\n*****************\n");
    for(i = 0;i<MIN(counterbooks,5);i++)
        printf("Book : %s - Borrows Count: %d\n",temp[i].title,temp[i].borrowedtimes);
    printf("*****************\n");
}
void savebooks ()
{
     FILE *fp;
    int i;
    fp = fopen("books.txt", "w");
    // check if it has been opend succssesfully
    if (fp != NULL)
     for (i=0;i<counterbooks;i++)
     fprintf(fp, "%s,%s,%s,%s,%d/%d/%d,%d,%d,%s,%d\n",b[i].title,b[i].author,b[i].publisher,b[i].isbn,b[i].b.dd,b[i].b.mm,b[i].b.yy,b[i].quantity,b[i].avaliablequantity,b[i].category,b[i].borrowedtimes);
 fclose(fp);
}
void loadbooks ()
{

    FILE *fp;
    fp = fopen("books.txt", "r");
    if (fp != NULL)
    {
    while (!feof(fp))
     {
     fscanf(fp,"%[^,],",&b[counterbooks].title);
     fscanf(fp,"%[^,],",&b[counterbooks].author);
     fscanf(fp,"%[^,],",&b[counterbooks].publisher);
     fscanf(fp,"%[^,],",&b[counterbooks].isbn);
     fscanf(fp, "%d/",&b[counterbooks].b.dd);
     fscanf(fp,"%d/",&b[counterbooks].b.mm);
     fscanf(fp,"%d,",&b[counterbooks].b.yy);
     fscanf(fp,"%d,",&b[counterbooks].quantity);
     fscanf(fp,"%d,",&b[counterbooks].avaliablequantity);
     fscanf(fp,"%[^,],",&b[counterbooks].category);
     fscanf(fp,"%d,",&b[counterbooks].borrowedtimes);
     fscanf(fp, "\n");
     counterbooks++;

      }
     }
     fclose(fp);
}
void savemembers ()
{
    int i;
     FILE *fk;
    fk = fopen("members.txt", "w");
    // check if it has been opend succssesfully
    if (fk == NULL)
    {
        printf("there is an error ");
        return;
    }
    else
    {
        for (i=0;i<countermembers;i++)
     fprintf(fk, "%s,%s,%d,%d,%s,%s,0%.0f,%d,%s,%d\n",m[i].firstname,m[i].lastname,m[i].ID,m[i].address.building,m[i].address.st,m[i].address.city,m[i].phonenumber,m[i].age,m[i].email,m[i].borrowedbooksno);

    }
     fclose(fk);
}
void loadmembers ()
{


    FILE *fp;
    fp = fopen("members.txt", "r");
    if (fp != NULL)
    {
    while (!feof(fp))
     {
     fscanf(fp,"%[^,],",&m[countermembers].firstname);
     fscanf(fp,"%[^,],",&m[countermembers].lastname);
     fscanf(fp,"%d,",&m[countermembers].ID);
     fscanf(fp,"%d,",&m[countermembers].address.building);
     fscanf(fp,"%[^,],",&m[countermembers].address.st);
     fscanf(fp,"%[^,],",&m[countermembers].address.city);
     fscanf(fp,"%f,",&m[countermembers].phonenumber);
     fscanf(fp,"%d,",&m[countermembers].age);
     fscanf(fp,"%[^,],",&m[countermembers].email);
     fscanf(fp,"%d",&m[countermembers].borrowedbooksno);
     fscanf(fp, "\n");
     countermembers++;
      }
     }
     fclose(fp);

}

void saveborrow ()
{
     FILE *fp;
    int i;
    fp = fopen("borrow.txt", "w");
    // check if it has been opend succssesfully
    if (fp != NULL)
     for (i=0;i<counterborrowed;i++)
     fprintf(fp, "%s,%d,%d/%d/%d,%d/%d/%d,%d/%d/%d,%d\n",br[i].bisbn,br[i].UserID,br[i].dborrowed.dd,br[i].dborrowed.mm,br[i].dborrowed.yy,br[i].duedate.dd,br[i].duedate.mm,br[i].duedate.yy,br[i].returned.dd,br[i].returned.mm,br[i].returned.yy,br[i].flag);
 fclose(fp);
}

void loadborrowed ()
{
   FILE *fp;
    fp = fopen("borrow.txt", "r");
    if (fp != NULL)
    {
    while (!feof(fp))
     {
     fscanf(fp,"%[^,],",&br[counterborrowed].bisbn);
     fscanf(fp,"%d,",&br[counterborrowed].UserID);
     fscanf(fp,"%d/",&br[counterborrowed].dborrowed.dd);
     fscanf(fp,"%d/",&br[counterborrowed].dborrowed.mm);
     fscanf(fp,"%d,",&br[counterborrowed].dborrowed.yy);
     fscanf(fp,"%d/",&br[counterborrowed].duedate.dd);
     fscanf(fp,"%d/",&br[counterborrowed].duedate.mm);
     fscanf(fp,"%d,",&br[counterborrowed].duedate.yy);
     fscanf(fp,"%d/",&br[counterborrowed].returned.dd);
     fscanf(fp,"%d/",&br[counterborrowed].returned.mm);
     fscanf(fp,"%d,",&br[counterborrowed].returned.yy);
     fscanf(fp,"%d",&br[counterborrowed].flag);
     fscanf(fp, "\n");
     counterborrowed++;
    }
     }
     fclose(fp);
}

