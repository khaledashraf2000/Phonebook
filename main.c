#include<conio.h>
#include<windows.h>
#include "functions.h"
//#include "crypt.h"
void menu();
int main()
{
   printf("\t\t\t\t\t**********WELCOME TO THE PHONEBOOK*************");
    system("color 1f");
    menu();

    return 0;
}


void menu()
{
    //char* sere;
  //  sere=NULL;
    //system("cls");
    // printf("\t\t**********WELCOME TO THE PHONEBOOK*************");
   // getch();
    printf("\n\n\t\t\t\t\t\t\tMENU\t\t\n\n");
   // printf("%s",sere);
    printf("\t\t*******************************************************************************************\n");

    if(loaded==1)
    {
        printf("\tCurrent LOADED DIRECTORY : %s\n",directory);
        printf("\tCurrent number of contacts : %d\n\n",count);
    }
    else
    {
        printf("Current LOADED DIRECTORY : NULL\n\n");
    }

    printf("\t1.LOAD CONTACTS FROM AN EXISTING FILE   \t2.Print LOADED Contacts (SORTED)   \t3.Exit PHONEBOOK  \n");
    printf("\t4.Modify \t\t\t\t\t5.Search By Last Name\t\t\t6.Delete\n");
    printf("\t7.ADD CONTACT\t\t\t\t\t8.SAVE TO AN EXTERNAL FILE\t\t9.ADVANCED SEARCH\n");
    printf("\tEnter Your Choice\n");
    switch(getch())
    {
    case '1':
        LOAD();
        break;
    case '2':
        print();
        break;
    case '3':
        printf("Are you sure you wish to quit without saving (y/n)?");
        quit();
        break;
    case '4':
        if(count)
        {
            printf("You are now modifying an existing contact!\n");
        }
        MODIFY();
        break;
    case '5':
        if(loaded && count)
        {
            printf("Enter The name of the contact you want to search(by last name): ");
        }
        SEARCHBYLAST();
        break;
    case '6':
        if(count)
        {
            printf("You are Now Deleting an existing contact\n");
        }
        DELETECONTACT();
        break;
    case '7':
        ADD();
        break;
    case '8':
        save();
        break;
    case '9':
        printf("*********\tNow performing an advanced search using multiple queries\t*********\n\n");
        advancedSEARCH();
        break;
    case 'c':
        system("cls");
        main();
        break;
    default:
        // system("cls");
        printf("\nEnter 1 to 9 only");
        printf("\nPress any key to continue");
        getch();
        system("cls");

    }
    fflush(stdin);
    menu();

}
