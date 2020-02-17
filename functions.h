#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include"sort.h"
#include "filehandle.h"
void ADD()
{
    if(loaded==0)
    {
        printf("Please make sure you have loaded a contact directory first");
    }
    else
    {
        fflush(stdin);
        // getch();
        int day,month,year;
        char date_of_birth[50];
        printf("***************You are now adding a new contact***************\n\n");
        printf("Enter the first name: ");
//        getchar();
        gets(c[count].first_name);
        while(isstring(c[count].first_name)==false)
        {
            printf("Please enter a valid first name\n");
            gets(c[count].first_name);
        }
        printf("Enter the last name: ");
        gets(c[count].last_name);
        while(isstring(c[count].last_name)==false)
        {
            printf("Please enter a valid last name\n");
            gets(c[count].last_name);
        }
        printf("Enter the birth date of contact(DD-MM-YYYY): ");
        gets(date_of_birth);

        // if (date_of_birth[0] != '\0')
        {
            sscanf(date_of_birth, "%d-%d-%d",&day, &month, &year);
            while(isValidDate(day,month,year)== false)
            {
                //getchar();
                printf("Please enter a valid date of birth(DD-MM-YYYY): ");
                gets(date_of_birth);
                sscanf(date_of_birth, "%d-%d-%d",&day, &month, &year);
            }
            c[count].date.day=day;
            c[count].date.month=month;
            c[count].date.year=year;
        }
        // fprintf(fptr,"%02d-%02d-%d,",c[count].date.day,c[count].date.month,c[count].date.year);
        printf("Enter the address: ");
        // scanf("\n");
        gets(c[count].address);
        // fprintf(fptr,"%s,",c[count].address);
        while( containcomma(c[count].address) == true )
        {
            printf("Please enter a valid address\n");
            gets(c[count].address);
        }
        printf("Enter the e-mail: ");
        gets(c[count].email);
        while(isvalidEMAIL(c[count].email)== false)
        {
            printf("Invalid E-mail!\nplease enter a valid email address : ");
            gets(c[count].email);
        }
        //  fprintf(fptr,"%s,",c[count].email);
        printf("Enter the phone number: ");
        gets(c[count].phone_number);
        while(isvalidnumber(c[count].phone_number)== false)
        {
            printf("Invalid phone number!\nplease enter a valid phone number : ");
            gets(c[count].phone_number);
        }
        printf("Contact has been added succesfully !\n%s,%s,%s,%s,%s\n",c[count].first_name,c[count].last_name,c[count].address,c[count].email,c[count].phone_number);
        count++;
    }
}

void DELETECONTACT()
{
    if(loaded==0)
    {
        printf("Please make sure you have loaded a contact directory first");
    }
    else if(loaded==1 && count==0)
    {
        printf("Please make sure you have contacts in your LOADED directory");
    }
    else
    {
        char firstname[100],lastname[100];
        printf("Enter the first name: ");
        gets(firstname);
        printf("Enter the last name: ");
        gets(lastname);
        int i,flag=0;
        for(i=0; i<count; i++)
        {
            if(!strcasecmp(c[i].last_name,lastname) && !strcasecmp(c[i].first_name,firstname))
            {
                for(; i<count; i++)
                {
                    c[i]=c[i+1];

                }
                printf("************\tContact has been deleted Successfully\t************");
                count--;
                //for(i=0;i<count;i++)
                //printf("%s,%s,%d-%d-%d,%s,%s,%s\n",c[i].first_name,c[i].last_name,c[i].date.day,c[i].date.month,c[i].date.year,c[i].address,c[i].email,c[i].phone_number);
                flag=1;
                //break;
            }
            if(flag) break;
        }
        if (flag==0)
        {
            printf("not found");
        }

        getchar();
    }
}

void MODIFY()
{
    fflush(stdin);
    int day,month,year;
    char date_of_birth[50];
    if(loaded==0)
    {
        printf("Please make sure you have loaded a contact directory first");
    }
    else if(loaded==1 && count==0)
    {
        printf("Please make sure you have contacts in your LOADED directory");
    }
    else
    {
        printf("Please enter the last name of the contact you wish to modify: ");
        if(SEARCHBYLAST())
        {
            printf("Please make sure you entered the name of an existing contact!\n");

        }
        else
        {
            int i=0;
            printf("\n***Enter the number of the contact you wish to edit***\n");
            scanf("%d",&i);
            i=i-1;
            getchar();
            fflush(stdin);
            printf("Enter the new first name: ");
            gets(c[searchIndex[i]].first_name);
            printf("Enter the new last name : ");
            gets(c[searchIndex[i]].last_name);
            printf("Enter the Date Of Birth: ");
            gets(date_of_birth);

            if (date_of_birth[0] != '\0')
            {
                sscanf(date_of_birth, "%d-%d-%d",&day, &month, &year);
                while(isValidDate(day,month,year)== false)
                {
                    //getchar();
                    printf("Please enter a valid date of birth(DD-MM-YYYY): ");
                    gets(date_of_birth);
                    sscanf(date_of_birth, "%d-%d-%d",&day, &month, &year);
                }
                // printf("%d %d %d\n", day, month, year);
            }
            printf("Enter the new address: ");
            getchar();
            gets(c[searchIndex[i]].address);
            printf("Enter the new email: ");
            gets(c[searchIndex[i]].email);
            while(isvalidEMAIL(c[searchIndex[i]].email)== false)
            {
                printf("Invalid E-mail!\nplease enter a valid email address : ");
                //getchar();
                gets(c[searchIndex[i]].email);
            }
            printf("Enter the new Phone number : ");
            gets(c[searchIndex[i]].phone_number);
            while(isvalidnumber(c[searchIndex[i]].phone_number)== false)
            {
                printf("Invalid phone number!\nplease enter a valid phone number : ");
                gets(c[searchIndex[i]].phone_number);
            }
            printf("************\tYour contact has been modified succefully\t************\nNew contact info is :");
            printf("%s,%s,%d-%d-%d,%s,%s,%s\n",c[searchIndex[i]].first_name,c[searchIndex[i]].last_name,c[searchIndex[i]].date.day,c[searchIndex[i]].date.month,c[searchIndex[i]].date.year,c[searchIndex[i]].address,c[searchIndex[i]].email,c[searchIndex[i]].phone_number);
        }


    }
}

void print()
{
    fflush(stdin);
    if(loaded==0)
    {
        printf("Please make sure you have loaded a contact directory first");
        getch();
    }
    else if(loaded==1 && count==0)
    {
        printf("Please make sure you have contacts in your LOADED directory");
        getch();
    }


    else
    {
        fflush(stdin);
        printf("\n\n\n");
        printf("How do you wish to display your contacts: \n");
        printf("1-Sorted by their dates of birth\n2-Sorted by their last names\n");
        // char choice1;
        //scanf("%c",&choice1);
        //getchar();
        switch(getchar())
        {
        case '1':
            sortbydob();
            getch();
            break;
        case '2':
            sortbylastname();
            getch();
            break;

        default:
            print("Please press '1' or '2'\n");
            print();
            getchar();

        }

    }
}

void quit()
{
//    char choice;
//    scanf("%c",&choice);
    switch(getchar())
    {
    case 'y':
        exit(0);
        break;
    case 'n':
        break;
    default:
        printf("\nEnter (y) or (n) only ");
        break;
    }
}

void advancedSEARCH()
{
    if(loaded==0)
    {
        printf("Please make sure you have loaded a contact directory first");
        getch();
    }
    else if(loaded==1 && count==0)
    {
        printf("Please make sure you have contacts in your LOADED directory");
        getch();
    }
    else
    {
        fflush(stdin);
        char first_name[20];
        char last_name[20];
        char date_of_birth[20];
        int day,month,year;
        char address[30];
        char email[30];
        char phone_number[30];
        // getchar();
        printf("Enter the first name: ");
        gets(first_name);
        printf("Enter the last name : ");
        gets(last_name);
        printf("Enter the Date Of Birth: ");
        gets(date_of_birth);

        if (date_of_birth[0] != '\0')
        {
            sscanf(date_of_birth, "%d-%d-%d",&day, &month, &year);
            while(isValidDate(day,month,year)== false)
            {
                //getchar();
                printf("Please enter a valid date of birth(DD-MM-YYYY): ");
                gets(date_of_birth);
                sscanf(date_of_birth, "%d-%d-%d",&day, &month, &year);
            }
            // printf("%d %d %d\n", day, month, year);
        }
        printf("Enter the address: ");
        gets(address);
//        printf(address);
        printf("Enter the email: ");
        gets(email);
        if(email[0]!='\0')
        {
            while(isvalidEMAIL(email)== false)
            {
                printf("Invalid E-mail!\nplease enter a valid email address : ");
                gets(email);
            }

        }
        printf("Enter the Phone number : ");
        gets(phone_number);
        if(phone_number[0]!='\0')
        {
            while(isvalidnumber(phone_number)== false)
            {
                printf("Invalid phone number!\nplease enter a valid phone number : ");
                gets(phone_number);
            }
        }


//    int o;
//    for(o=0; o<100; o++)
//        searchIndex[o]=-1;


        int i,flag=0;
        for(i=0; i<count; i++)
        {
            c[i].found_first_name=1;
            c[i].found_last_name=1;
            c[i].found_date=1;
            c[i].found_address=1;
            c[i].found_email=1;
            c[i].found_phonenumber=1;

            if(first_name[0] != '\0' && strcasecmp(c[i].first_name,first_name))
            {
                c[i].found_first_name = -1;
            }

            if(last_name[0] != '\0' && strcasecmp(c[i].last_name,last_name))
            {
                c[i].found_last_name = -1;
            }



            if(date_of_birth[0] != '\0')
            {
                if (day==c[i].date.day && month==c[i].date.month && year==c[i].date.year)
                {
                    c[i].found_date = 1;
                }
                else
                {
                    c[i].found_date = -1;
                }

            }
            else
            {
                c[i].found_date= 1;
            }



            if(address[0] != '\0' && strcasecmp(c[i].address,address))
            {
                c[i].found_address= -1;
            }



            if(email[0] != '\0' && strcasecmp(c[i].email,email))
            {
                c[i].found_email= -1;
            }



            if(phone_number[0] != '\0' && strcasecmp(c[i].phone_number,phone_number))
            {
                c[i].found_phonenumber = -1;
            }




        }
        int number=1;
        flag=0;
        for (i=0; i<count; i++)
        {
            if(c[i].found_first_name==1 && c[i].found_last_name==1 && c[i].found_date==1 && c[i].found_address==1 && c[i].found_email==1 && c[i].found_phonenumber==1 )
            {
                printf("%d-%s,%s,%d-%d-%d,%s,%s,%s\n",number,c[i].first_name,c[i].last_name,c[i].date.day,c[i].date.month,c[i].date.year,c[i].address,c[i].email,c[i].phone_number);
                number++;
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("Not found");
        }

    }
}

#endif // FUNCTIONS_H_INCLUDED
