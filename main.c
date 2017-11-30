#include <windows.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "fun.h"
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


int main()
{     loaddata ();
      mainmenu();

return 0;
}
void mainmenu()
{
    popularbooks ();
    char n='0';
    char x='0';


        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU");
        printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
        printf("\xDB\xB2 Book Management (1) \n\xDB\xB2 Member Management (2) \n\xDB\xB2 Borrow Management (3) \n\xDB\xB2 Administrative actions (4) \n\xDB\xB2 Save changes (5) \n\xDB\xB2 Exit (6) \n enter :");
        x=getch();

        if (x=='1' || x=='2' || x=='3' || x=='4' || x=='6' )
        {
            if(x=='1')
            {   system("cls");
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Library System");
                printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
                printf("\n\xDB\xB2 Insert (1) \n\xDB\xB2 search (2) \n\xDB\xB2 add new copies (3) \n\xDB\xB2 delete (4) \n\xDB\xB2 edit (5)\n\xDB\xB2 back (6) \nenter : ");
                n=getch();




                    if(n=='1')
                      {addbook();

                      }
                    if (n=='2')
                      {
                       searchbook();
                      }
                    if (n=='3')
                      {
                       addnewcopies ();
                      }
                    if (n=='4')
                      {
                       removebook ();
                      }
                    if (n=='5')
                      {
                       editbook();
                      }
                    if (n=='6')
                    {
                        system("cls");
                        mainmenu();
                    }
            }
            if (x=='2')
            {   system("cls");
              printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Library System");
              printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
              printf("\n\xDB\xB2 Register (1) \n\xDB\xB2 remove (2)\n\xDB\xB2 back (3)");
              char k;
              k=getch();
              if (k=='1')
              {addmember();
              }
              if (k=='2')
              {deletemember ();}
              if (k=='3')
              {
                  system("cls");
                  mainmenu();
              }
            }
            if (x=='3')
            {   system("cls");
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Library System");
                printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
              printf("\n\xDB\xB2 Borrow (1) \n\xDB\xB2 return (2)");
               char p;
              p=getch();
              if (p=='1')
              {newborrowing ();
              }
              if (p=='2')
              {returnbook();}
              if (p=='3')
              {
                  system("cls");
                  mainmenu();
              }
            }
            if (x=='4')
            {   system("cls");
              printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Library System");
              printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
               printf("\n\xDB\xB2 overdue (1) \n\xDB\xB2 popular (2)");
               char sa;
              sa=getch();
              if (sa=='1')
              { overdue ();
              }
              if (sa=='2')
              { popularbooks ();
                printf("press any key ");
                getch();
                system("cls");
                  mainmenu();
              }
              if (sa=='3')
              {
                  system("cls");
                  mainmenu();
              }
            }
            if (x=='5')
            {
            system("cls");
            printf("***the data has been saved***\n");
            savedata();
            mainmenu();
            }
            if (x=='6')
            {
                system("cls");
              printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Exit");
              printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n");
              printf("\n\xDB\xB2 Exit with save (1) \n\xDB\xB2 Exit without save (2)\n\xDB\xB2 Back");
              char s;
              s=getch();
              if (s=='1')
              { savedata ();
                exit(0);
                return;
              }
              if (s=='2')
              {
                   exit(0);
                   exit(0);
                   return;
              }
              if (s=='3')
              {
                system("cls");
                mainmenu();
              }
            }

    }
    else
    {

        system("cls");
        printf("\n***wrong input***\n");
        mainmenu();
    }



}
