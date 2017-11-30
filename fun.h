#ifndef FUN_H_INCLUDED
#define FUN_H_INCLUDED
#include "struct.h"
void mainmenu();
void addbook();
void editbook();
void searchbook();
void categorysearch ();
void popularbooks ();
void addnewcopies ();
void removebook ();
void addmember();
void deletemember ();
void newborrowing ();
void returnbook();
void overdue ();
void savedata ();
void titlesearch ();
void ISBNsearch ();
void Authorsearch();
void loaddata ();
int checkISBN (int);
int checkID (int);
char getch();
void addbook()
{   system("cls");
     printf("\n\t\t   Book Addition Menu:");
    printf("\n\n\tThis will add the contents to database.\n");
    printf("\nenter Book ISBN : ");
    int sISBN,x;
    scanf("%d",&sISBN);
    x=checkISBN (sISBN);
    if(x)
    {
     printf("the ISBN is already exist\npress any key to back to mainmenu");
     getch();
        system("cls");
        mainmenu();
        return;
    }
    else{
    b[counterbooks].ISBN=sISBN;
    printf("\nEnter Book title = ");
    // gets() function is used to get spaced inputs
    gets(b[counterbooks].title);
    gets(b[counterbooks].title);
    printf("Enter Author's name = ");
    gets(b[counterbooks].Author);
    printf("Publisher: ");
    gets(b[counterbooks].Publisher);
    printf("enter Publication Date day-month-year : ");
    int flag1=0;
    while (flag1==0)
    {scanf("%d",&b[counterbooks].b.dd);
    if (b[counterbooks].b.dd>31)
        printf("day must be less than 31 :- ");
        else flag1=1;
    }
    flag1=0;
    while (flag1==0)
    {scanf("%d",&b[counterbooks].b.mm);
    if (b[counterbooks].b.mm>12)
        printf("month must be less than 12 :- ");
        else flag1=1;
    }
    scanf("%d",&b[counterbooks].b.yy);
    printf("total quantity: ");
    scanf("%d",&b[counterbooks].quantity);
    printf("avalibale Quantity: ");
    scanf("%d",&b[counterbooks].avaliableQuantity);
    printf("Enter category = ");
    gets(b[counterbooks].category);
    gets(b[counterbooks].category);
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

}
void editbook()
{
    int sISBN,target,i,flag=0;
    system("cls");

    printf("\n\t\t  Modify a Record :");
    printf("\n\n\tThis will modify the contents of the record\n\tin Book_DB Database.\n\n");

    printf("\n\t ISBN of the Book = ");
    scanf("%d",&sISBN);
    for (i=0;i<counterbooks;i++)
    {
        if (sISBN==b[i].ISBN)
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        printf("\n\tBook with ISBN '%d' is not present in  database.\n\n", sISBN);
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
            printf("\n\tAuthor     = %s", b[target].Author);
            printf("\n\tPublisher     = %s", b[target].Publisher);
            printf("\n\tPublicationDate      = %d-%d-%d", b[target].b.dd,b[target].b.mm,b[target].b.yy);
            printf("\n\tISBN       = %d", b[target].ISBN);
            printf("\n\tquantity    = %d", b[target].quantity);
            printf("\n\tavaliable Quantity   = %d\n\n", b[target].avaliableQuantity);
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
                gets(b[target].title);
                printf("\tAuthor = ");
                gets(b[target].Author);

                printf("\tISBN = ");
               scanf("%d",&b[target].ISBN);
                printf("\tpublisher = ");
                gets(b[target].Publisher);
                gets(b[target].Publisher);
                printf("\t quantity  = ");
                scanf("%d",&b[target].quantity);
                printf("\t avaliable Quantity = ");
                scanf("%d",&b[target].avaliableQuantity);
            }

        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;

        }
  void searchbook()
{


    system("cls");
                       printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Search ");
                       printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
                       printf("\n\xDB\xB2 by book title  (1) \n\xDB\xB2 by ISBN (2) \n\xDB\xB2 by category (3) \n\xDB\xB2 by author (4) \n enter : ");
                       char o='0';
                       o=getch();
                       if (o=='1')
                       {titlesearch ();
                       }
                       if(o=='2')
                       {ISBNsearch ();
                       system("cls");
                       mainmenu();
                       return;


                       }
                       if(o=='3')
                       {categorysearch ();
                       }
                       if (o=='4')
                       { Authorsearch();
                       }
}
void ISBNsearch (void)
{
    int sISBN,i,flag=0;
    printf("\n\xDB\xB2 enter ISBN :");
    scanf("%d",&sISBN);
    for (i=0;i<counterbooks;i++)
    {
        if (sISBN==b[i].ISBN)
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        printf("\n\tBook with ISBN '%d' is not present in database.\n\n", sISBN);
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
            printf("\n\tAuthor     = %s", b[target].Author);
            printf("\n\tPublisher     = %s", b[target].Publisher);
            printf("\n\tPublicationDate      = %d-%d-%d", b[target].b.dd,b[target].b.mm,b[target].b.yy);
            printf("\n\tISBN       = %d", b[target].ISBN);
            printf("\n\tquantity    = %d", b[target].quantity);
            printf("\n\tavaliable Quantity   = %d", b[target].avaliableQuantity);
            printf("\n\tcategory   = %s\n\n", b[target].category);
    }
    printf("to Back to mainmenu press any key");
    getch();
    return;

}
void addnewcopies ()
{
   system("cls");
   printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 add new copies ");
   printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
   int sISBN,i,flag=0;
    printf("\n\xDB\xB2 enter ISBN :");
    scanf("%d",&sISBN);
    for (i=0;i<counterbooks;i++)
    {
        if (sISBN==b[i].ISBN)
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
        printf("\nenter the total number of quantity after increment");

        do
        {
            scanf("%d",&b[target].quantity);
            if (b[target].quantity>=0)
                x=1;
            else
              printf("\nthe quantity must be a postive number");
        }while (x!=1 || b[target].quantity<0 );


        printf("\nenter avalibale number of quantity after increment");

        do
        {
            scanf("%d",&b[target].avaliableQuantity);
            if (b[target].avaliableQuantity>=0)
                x=1;
            else
              printf("\nthe quantity must be a postive number");
        }while (x!=1 || b[target].quantity<0);

        printf("\n\tPress any key to back to mainmenu");
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
   int sISBN,i,flag=0;
    printf("\n\xDB\xB2 enter ISBN :");
    scanf("%d",&sISBN);
    for (i=0;i<counterbooks;i++)
    {
        if (sISBN==b[i].ISBN)
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        printf("\n\tBook with ISBN '%d' is not present in Book_DB database.\n\n", sISBN);
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;

    }
    else
    {
        /***/
        int target=i;

          printf("\n\t the book : \n");

            printf("\n\ttile       = %s", b[target].title);
            printf("\n\tAuthor     = %s", b[target].Author);
            printf("\n\tPublisher     = %s", b[target].Publisher);
            printf("\n\tPublicationDate      = %d-%d-%d", b[target].b.dd,b[target].b.mm,b[target].b.yy);
            printf("\n\tISBN       = %d", b[target].ISBN);
            printf("\n\tquantity    = %d", b[target].quantity);
            printf("\n\tavaliable Quantity   = %d\n\n", b[target].avaliableQuantity);
            printf("\n\tcategory   = %s\n\n", b[target].category);
            printf("\n\tModify this record : ");
            printf("\n\n\tPress 'y' to delete this record.\n\tPress any other key to return to main menu.\n\n");
            printf("\tChoice = ");
            char choice = getch();
            if(choice == 'y' || choice == 'Y')
            {

        /***/
        struct books temp;

        for (i=target;i<counterbooks;i++)
        {
            strcpy(temp.title,b[i+1].title);
            strcpy(temp.Author,b[i+1].Author);
            strcpy(temp.Publisher,b[i+1].Publisher);
            temp.ISBN=b[i+1].ISBN;
            temp.b.dd=b[i+1].b.dd;
            temp.b.mm=b[i+1].b.mm;
            temp.b.yy=b[i+1].b.yy;
            temp.quantity=b[i+1].quantity;
            temp.avaliableQuantity=b[i+1].avaliableQuantity;
            strcpy(temp.category,b[i+1].category);
            /**/
            strcpy(b[i].title,b[i+1].title);
            strcpy(b[i].Author,b[i+1].Author);
            strcpy(b[i].Publisher,b[i+1].Publisher);
            b[i].ISBN=b[i+1].ISBN;
            b[i].b.dd=b[i+1].b.dd;
            b[i].b.mm=b[i+1].b.mm;
            b[i].b.yy=b[i+1].b.yy;
            b[i].quantity=b[i+1].quantity;
            b[i].avaliableQuantity=b[i+1].avaliableQuantity;
            strcpy(b[i].category,b[i+1].category);
            /***/
            strcpy(b[i+1].title,temp.title);
            strcpy(b[i+1].Author,temp.Author);
            strcpy(b[i+1].Publisher,temp.Publisher);
            b[i+1].ISBN=temp.ISBN;
            b[i+1].b.dd=temp.b.dd;
            b[i+1].b.mm=temp.b.mm;
            b[i+1].b.yy=temp.b.yy;
            b[i+1].quantity=temp.quantity;
            b[i+1].avaliableQuantity=temp.avaliableQuantity;
            strcpy(b[i+1].category,temp.category);


        }
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
void categorysearch (void)
{
    char scategory[20];
    int counter=1,i;
    printf("\n\xDB\xB2 enter category :");
    gets(scategory);
    for (i=0;i<counterbooks;i++)
    {
        if (strcmp(b[i].category,scategory)==0)
        {
            printf("\n\t the book %d : \n",counter);
            printf("\n\ttile       = %s", b[i].title);
            printf("\n\tAuthor     = %s", b[i].Author);
            printf("\n\tPublisher     = %s", b[i].Publisher);
            printf("\n\tPublicationDate      = %d-%d-%d", b[i].b.dd,b[i].b.mm,b[i].b.yy);
            printf("\n\tISBN       = %d", b[i].ISBN);
            printf("\n\tquantity    = %d", b[i].quantity);
            printf("\n\tavaliable Quantity   = %d", b[i].avaliableQuantity);
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
void Authorsearch (void)
{
    char sAuthor[20];
    int counter=1,i;
    printf("\n\xDB\xB2 enter Author name :");
    gets(sAuthor);
    for (i=0;i<counterbooks;i++)
    {
        if (strcmp(b[i].Author,sAuthor)==0)
        {
            printf("\n\t the book %d : \n",counter);
            printf("\n\ttile       = %s", b[i].title);
            printf("\n\tAuthor     = %s", b[i].Author);
            printf("\n\tPublisher     = %s", b[i].Publisher);
            printf("\n\tPublicationDate      = %d-%d-%d", b[i].b.dd,b[i].b.mm,b[i].b.yy);
            printf("\n\tISBN       = %d", b[i].ISBN);
            printf("\n\tquantity    = %d", b[i].quantity);
            printf("\n\tavaliable Quantity   = %d", b[i].avaliableQuantity);
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

void addmember()
{
    system("cls");
    int x;
     printf("\n\t\t   member Addition Menu:");
    printf("\n\n\tThis will add the contents to members database.\n");
    printf("%d",countermembers);
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
    printf("\nEnter first name = ");
    gets(m[countermembers].firstname);
    gets(m[countermembers].firstname);
    printf("Enter last name = ");
    gets(m[countermembers].lastname);
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
/**/
    printf("phone number: ");
    int flagp=0;
    float sphone;
    do { scanf("%f",&sphone);
        if (1000000000<sphone)
        flagp++;
        else
        {
            printf("phone no is not correct :-  ");
            flagp=0;
        }
        if (countermembers==0) flagp==2;
        if (flagp==1 && countermembers>0)
        {
            for (i=0;i<countermembers;i++)
              if (sphone==m[i].phonenumber);
              {printf("the number is already exist\n try again :- ");flagp=0;}
            if (flagp==1)
            {
             flagp++;
            }

        }
        }while(flagp!=2);
    m[countermembers].phonenumber=sphone;
/**/
    printf("enter the adress building number - street -city \n ");
    int flagx=0;
    do{
    scanf("%d",&m[countermembers].address.building);
    if (m[countermembers].address.building<0)
    {printf("building no must be a postive number\n");}
    else flagx=1;
    }while(flagx==0);
    gets(m[countermembers].address.st);
    gets(m[countermembers].address.st);
    gets(m[countermembers].address.city);
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

        /***/
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
                struct member temp;
            if (m[target].borrowedbooksno)
            {   system("cls");
                printf("\n***member can't be deleted because he has a book must be returned***\n");
                mainmenu();
                return;
            }

        for (i=target;i<counterbooks;i++)
        {
            strcpy(temp.firstname,m[i+1].firstname);
            strcpy(temp.lastname,m[i+1].lastname);
            strcpy(temp.email,m[i+1].email);
            temp.ID=m[i+1].ID;
            temp.address.building=m[i+1].address.building;
            strcpy(temp.address.st,m[i+1].address.st);
            strcpy(temp.address.city,m[i+1].address.city);

            /**/
            strcpy(m[i].firstname,m[i+1].firstname);
            strcpy(m[i].lastname,m[i+1].lastname);
            strcpy(m[i].email,m[i+1].email);
            m[i].ID=m[i+1].ID;
            m[i].address.building=m[i+1].address.building;
            strcpy(m[i].address.st,m[i+1].address.st);
            strcpy(m[i].address.city,m[i+1].address.city);
            /***/
            strcpy(m[i].firstname,temp.firstname);
            strcpy(m[i].lastname,temp.lastname);
            strcpy(m[i].email,temp.email);
            m[i].ID=temp.ID;
            m[i].address.building=temp.address.building;
            strcpy(m[i].address.st,temp.address.st);
            strcpy(m[i].address.city,temp.address.city);
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
void newborrowing (void)
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
        { /***/
            printf("\n\xDB\xB2 Book ISBN: ");
            scanf("%d",&br[counterborrowed].bISBN);
            int sISBN=br[counterborrowed].bISBN;
            flag=0;
            for (i=0;i<counterbooks;i++)
    {
        if (sISBN==b[i].ISBN)
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
    {
        printf("\n\t the book with ISBN '%d' is not present in database.\n\n", sISBN);
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;

    }
    else
    { int btareget=i;
            br[counterborrowed].UserID=sID;
            int flager=0;
            do{
            printf("enter borrowed Date day-month-year :\n ");
            int flag1=0;
            while (flag1==0)
            {scanf("%d",&br[counterborrowed].dborrowed.dd);
            if (br[counterborrowed].dborrowed.dd>31)
            printf("day must be less than 31 :- ");
            else flag1=1;
            }
            flag1=0;
            while (flag1==0)
            {scanf("%d",&br[counterborrowed].dborrowed.mm);
            if (br[counterborrowed].dborrowed.mm>12)
            printf("month must be less than 12 :- ");
            else flag1=1;
            }
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
            {scanf("%d",&br[counterborrowed].duedate.dd);
            if (br[counterborrowed].duedate.dd>31)
            printf("day must be less than 31 :- ");
            else flag1=1;
            }
            flag1=0;
            while (flag1==0)
            {scanf("%d",&br[counterborrowed].duedate.mm);
            if (br[counterborrowed].duedate.mm>12)
            printf("month must be less than 12 :- ");
            else flag1=1;
            }
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
            counterborrowed++;
            m[target].borrowedbooksno++;
            b[btareget].avaliableQuantity--;
            br[counterborrowed].flag=1;
            b[btareget].borrowedtimes++;
            printf("\n\t Press any key to back to mainmenu");
            getch();
            system("cls");
            mainmenu();
            return;
    }
    }
    }
}
void returnbook()
{
    system("cls");
    int sID,sISBN,i,flag=0;
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 return book");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
    printf("\n\xDB\xB2 enter student ID :");
    scanf("%d",&sID);
    printf("\n\xDB\xB2 enter Book ISBN :");
    scanf("%d",&sISBN);
        for (i=0;i<counterborrowed;i++)
    {
        if (sID==br[i].UserID && sISBN==br[i].bISBN && br[i].flag==1 )
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
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
     { targetm=i;
         for (i=0;i<counterbooks;i++)
     { if (sISBN==b[i].ISBN)
         {
             flag=1;
             break;
         }
     }
     if (flag==0)
     {
         printf("\n\t the book with ISBN '%d'is not present in database.\n\n", sISBN);
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;
     }
     else
     { targetb=i;
       m[targetm].borrowedbooksno--;
       b[targetb].avaliableQuantity++;
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

void overdue ()
{   system("cls");
    int dd,mm,yy,i,flager=0,counter=1;
    printf("please enter the date of today dd-mm-yyyy :- \n");
    scanf("%d%d%d",&dd,&mm,&yy);
    for (i=0;i<counterborrowed;i++)
    {
        if (dd+30*mm+365*yy>br[i].duedate.dd+30*br[i].duedate.mm+365*br[i].duedate.yy && br[i].flag==1)
        {
            printf("book no.#%d \n His ISBN %d \n user ID %d \n\n ",counter,br[i].bISBN,br[i].UserID);
            flager=1;
        }
        if (flager==0)
        {
            printf("there isn't book overdued");
        }
    }
    printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;

}
void popularbooks ()
{
    system("cls");
    int i,k1=0,k2=0,k3=0,k4=0,k5=0;
    int flag=0;
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Popular Books ");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");


    if (counterbooks>0){
    for (i=0;i<counterbooks;i++)
    {
        if(b[i].borrowedtimes>b[i+1].borrowedtimes)
            k1=i;
    }

    if (b[k1].borrowedtimes==0)
    {
        printf("\nthere is not borrowed books\n");
           return;flag=1;
    }
    if (flag==0)
    {for (i=0;i<counterbooks;i++)
    {   if (i==k1) continue;
        if(b[i].borrowedtimes>b[i+1].borrowedtimes)
            k2=i;
    }
    if (b[k2].borrowedtimes==0)
    {
        printf("#no\ttitle\ttimeborrowed \n#%d \t %s \t %d",1,b[k1].title,b[k1].borrowedtimes);

        flag=1;
            return;
    }
    if (flag==0){
    for (i=0;i<counterbooks;i++)
    {   if (i==k1 || i==k2) continue;
        if(b[i].borrowedtimes>b[i+1].borrowedtimes)
            k3=i;
    }
    if (b[k3].borrowedtimes==0)
    {
        printf("#%d \t %s \t %d \n#%d \t %s \t %d",1,b[k1].title,b[k1].borrowedtimes,2,b[k2].title,b[k2].borrowedtimes);
       return;    flag=1;
    }
    if (flag==0){
     for (i=0;i<counterbooks;i++)
    {   if (i==k1 || i==k2 || i==k3) continue;
        if(b[i].borrowedtimes>b[i+1].borrowedtimes)
            k4=i;
    }
    if (b[k4].borrowedtimes==0)
    {
        printf("#%d \t %s \t %d \n#%d \t %s \t %d\n#%d \t %s \t %d",1,b[k1].title,b[k1].borrowedtimes,2,b[k2].title,b[k2].borrowedtimes,3,b[k3].title,b[k3].borrowedtimes);
        return;   flag=1;
    }
    if (flag==0){
    for (i=0;i<counterbooks;i++)
    {   if (i==k1 || i==k2 || i==k3) continue;
        if(b[i].borrowedtimes>b[i+1].borrowedtimes)
            k4=i;
    }
    if (b[k5].borrowedtimes==0)
    {
       printf("#%d \t %s \t %d \n#%d \t %s \t %d\n#%d \t %s \t %d \n#%d \t %s \t %d",1,b[k1].title,b[k1].borrowedtimes,2,b[k2].title,b[k2].borrowedtimes,3,b[k3].title,b[k3].borrowedtimes,4,b[k4].title,b[k4].borrowedtimes);
       return;
    flag=1;
    }
    else if (flag==0){
   printf("#%d \t %s \t %d \n#%d \t %s \t %d\n#%d \t %s \t %d \n#%d \t %s \t %d\n#%d \t %s \t %d\n",1,b[k1].title,b[k1].borrowedtimes,2,b[k2].title,b[k2].borrowedtimes,3,b[k3].title,b[k3].borrowedtimes,4,b[k4].title,b[k4].borrowedtimes,5,b[k5].title,b[k5].borrowedtimes);
   return;
    }}}}}}}

void titlesearch ()
{

    system("cls");
    char st[20];
    int i;
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 search by title  ");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
    printf("enter the title or part of it");
    gets(st);
    int counter=0;
    for (i=0;i<counterbooks;i++)
    {
        if (strstr(b[i].title, st)!=NULL)
        {
            printf("\n\t the book %d : \n",counter);
            printf("\n\ttile       = %s", b[i].title);
            printf("\n\tAuthor     = %s", b[i].Author);
            printf("\n\tPublisher     = %s", b[i].Publisher);
            printf("\n\tPublicationDate      = %d-%d-%d", b[i].b.dd,b[i].b.mm,b[i].b.yy);
            printf("\n\tISBN       = %d", b[i].ISBN);
            printf("\n\tquantity    = %d", b[i].quantity);
            printf("\n\tavaliable Quantity   = %d", b[i].avaliableQuantity);
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
void savedata ()
{
    FILE *fbook1,*fmember1,*fborrowed1,*fcounter1;
    int i;
    fbook1=fopen("Books.txt", "w");
    if (fbook1==NULL)
    {   printf("error in saving data ");
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;
    }
    for (i=0;i<counterbooks;i++)
     fprintf(fbook1,"%s,%s,%d,%d/%d/%d,%d,%d,%s,%d\n",b[i].title,b[i].Author,b[i].ISBN,b[i].b.dd,b[i].b.mm,b[i].b.yy,b[i].quantity,b[i].avaliableQuantity,b[i].category,b[i].borrowedtimes);
    fclose(fbook1);
    /***/
    fmember1=fopen("members.txt", "w");
    if (fmember1==NULL)
    {   printf("error in saving data ");
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;
    }
    for (i=0;i<countermembers;i++)
      fprintf(fmember1,"%s,%s,%d,%d,%s,%s,0%.0f,%d,%s,%d\n",m[i].firstname,m[i].lastname,m[i].ID,m[i].address.building,m[i].address.st,m[i].address.city,m[i].phonenumber,m[i].age,m[i].email,m[i].borrowedbooksno);
     fclose(fmember1);
     /**/
     fborrowed1=fopen("borrowed.txt", "w");
    if (fborrowed1==NULL)
    {   printf("error in saving data ");
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;
    }
    for (i=0;i<counterborrowed;i++)
      fprintf(fborrowed1,"%d,%d,%d/%d/%d,%d/%d/%d,%d/%d/%d,%d\n",br[i].bISBN,br[i].UserID,br[i].dborrowed.dd,br[i].dborrowed.mm,br[i].dborrowed.yy,br[i].duedate.dd,br[i].duedate.mm,br[i].duedate.yy,br[i].returned.dd,br[i].returned.mm,br[i].returned.yy,br[i].flag);
     fclose(fborrowed1);
     /**/

     fcounter1=fopen("counter.txt", "w");
    if (fcounter1==NULL)
    {   printf("error in saving data ");
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;
    }
      fprintf(fcounter1,"%d,%d,%d\n",counterbooks,counterborrowed,countermembers);
      fclose(fcounter1);
      loaddata ();
      printf("\n***the data has been saved***\n");
      printf("\n\tPress any key ");
        getch();
        system("cls");
        return;

}
void loaddata ()
{
    FILE *fbook,*fmember,*fborrowed,*fcounter;
    int i;
    fbook=fopen("Books.txt", "r");
    if (fbook==NULL)
    {   printf("error in reading data ");
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;
    }
    for (i=0;i<counterbooks;i++)
     fscanf(fbook,"%s,%s,%d,%d/%d/%d,%d,%d,%s,%d\n",&b[i].title,&b[i].Author,&b[i].ISBN,&b[i].b.dd,&b[i].b.mm,&b[i].b.yy,&b[i].quantity,&b[i].avaliableQuantity,&b[i].category,&b[i].borrowedtimes);
    fclose(fbook);

    /***/
    fmember=fopen("members.txt", "r");
    if (fmember==NULL)
    {   printf("error in reading data ");
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;
    }
    for (i=0;i<countermembers;i++)
      fscanf(fmember,"%s,%s,%d,%d,%s,%s,0%.0f,%d,%s,%d\n",&m[i].firstname,&m[i].lastname,&m[i].ID,m[i].address.building,&m[i].address.st,&m[i].address.city,&m[i].phonenumber,&m[i].age,&m[i].email,&m[i].borrowedbooksno);
     fclose(fmember);
     /**/
     fborrowed=fopen("borrowed.txt", "r");
    if (fborrowed==NULL)
    {   printf("error in reading data ");
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;
    }
    for (i=0;i<counterborrowed;i++)
      fscanf(fborrowed,"%d,%d,%d/%d/%d,%d/%d/%d,%d/%d/%d,%d\n",&br[i].bISBN,&br[i].UserID,&br[i].dborrowed.dd,&br[i].dborrowed.mm,&br[i].dborrowed.yy,&br[i].duedate.dd,&br[i].duedate.mm,&br[i].duedate.yy,&br[i].returned.dd,&br[i].returned.mm,&br[i].returned.yy,&br[i].flag);
     fclose(fborrowed);
     /**/

     fcounter=fopen("counter.txt", "r");
    if (fcounter==NULL)
    {   printf("error in reading data ");
        printf("\n\tPress any key to back to mainmenu");
        getch();
        system("cls");
        mainmenu();
        return;
    }
      fprintf(fcounter,"%d,%d,%d\n",&counterbooks,&counterborrowed,&countermembers);
      fclose(fcounter);
        return;
}
int checkISBN (int x)
{   int i,flag=0;

    for (i=0;i<counterbooks;i++)
      if (b[i].ISBN==x)
      {
          flag=1;
      }
      if (flag==0)
         return 0;
      if (flag==1)
         return 1;
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

#endif // FUN_H_INCLUDED
