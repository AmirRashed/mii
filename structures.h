#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED


struct Date
{
    int mm,dd,yy;
};
struct books
{
    char title[20];
    char Author[20];
    char Publisher[20];
    int ISBN;
    struct Date b;
    int quantity;
    int avaliableQuantity;
    char category[20];
    int borrowedtimes;
};
struct address
{
    int building;
    char st[20];
    char city[20];
};
struct member
{
    char firstname[20];
    char lastname[20];
    int ID;
    struct address address;
    float phonenumber;
    int age;
    char email[20];
    int borrowedbooksno;
};
struct borrowed
{
    int bISBN;
    int UserID;
    struct Date dborrowed;
    struct Date duedate;
    struct Date returned;
    int flag;

};
struct borrowed br[1000];
struct member m[500];
struct books b[1000];
int counterborrowed=0;
int counterbooks=0;
int countermembers=0;

#endif // STRUCTURES_H_INCLUDED
