#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include<stdio.h>
#include<string.h>
#include"global.h"
#include"isvalid.h"
void save()
{
    fflush(stdin);
    char filename[50];
    printf("Please enter the file name you wish to save your contacts to: ");
    gets(filename);
    int i;
    FILE* fptr;
    fptr=fopen(filename,"w");
    if(fptr==NULL)
        printf("Error can't find file");
    else
    {
        for(i=0; i<count; i++)
        {
            fprintf(fptr,"%s,",c[i].first_name);
            fprintf(fptr,"%s,",c[i].last_name);
            fprintf(fptr,"%02d-%02d-%d,",c[i].date.day,c[i].date.month,c[i].date.year);
            fprintf(fptr,"%s,",c[i].address);
            fprintf(fptr,"%s,",c[i].email);
            fprintf(fptr,"%s\n",c[i].phone_number);

        }
        fclose(fptr);
        printf("\n************\tfile directory %s was saved succefully\t************",filename);

    }
}
void LOAD()
{
    fflush(stdin);
    strncpy(directory,"", sizeof(directory));
    count=0;
    printf("Enter the contact FILE you wish to LOAD: ");
    gets(directory);
    FILE* fptr;
    fptr=fopen(directory,"r");
    if(fptr==NULL)
    {
        printf("Error can't find file\nWould you like to create a file?(y/n)");
       // getchar();
       //printf("\n the bugger is : '%s' and ascii '%d'",directory,directory);
        switch(getchar())
        {
        case 'y':
            fflush(stdin);

            fptr=fopen(directory,"w+");
           // while(!feof(fptr))
       // {
          //  fscanf(fptr,"%[^,],%[^,],",c[count].first_name,c[count].last_name);
           // fscanf(fptr,"%d-%d-%d,",&c[count].date.day,&c[count].date.month,&c[count].date.year);
          //  fscanf(fptr,"%[^,],%[^,],%s\n",c[count].address,c[count].email,c[count].phone_number);
            //  printf("%s,%s,%d-%d-%d,%s,%s,%s\n",c[count].first_name,c[count].last_name,c[count].date.day,c[count].date.month,c[count].date.year,c[count].address,c[count].email,c[count].phone_number);
            loaded=1;
          //  printf("%d",count);
       // }
        // count--;
        // printf("%d",count);
        fclose(fptr);
        printf("File ""%s"" was created and loaded successfully\n\n",directory);
        count=0;
       // getch();
            break;
        case'n':
            loaded=0;
           // directory==NULL;

            break;
        default:
            printf("\nOnly y or n only allowed!");
            printf("\nPress any key to continue");
            getch();
            fflush(stdin);

        }

    }
    else
    {
        int i=0;
        count=0;
        char dateofbirth[100];
        printf("\n");

        while(!feof(fptr))
        {


            fscanf(fptr,"%[^,],%[^,],",c[count].first_name,c[count].last_name);
            fscanf(fptr,"%d-%d-%d,",&c[count].date.day,&c[count].date.month,&c[count].date.year);
            fscanf(fptr,"%[^,],%[^,],%s\n",c[count].address,c[count].email,c[count].phone_number);
            //  printf("%s,%s,%d-%d-%d,%s,%s,%s\n",c[count].first_name,c[count].last_name,c[count].date.day,c[count].date.month,c[count].date.year,c[count].address,c[count].email,c[count].phone_number);
            count++;

            loaded=1;
        }
        contact loadtemp[100];
        for(i=0; i<count; i++)
        {
            if(!isstring(c[i].first_name))
            {
                printf("Contact number %d first name is not valid!\n" , i+1);
                printf("%s,%s,%d-%d-%d,%s,%s,%s\n",c[i].first_name,c[i].last_name,c[i].date.day,c[i].date.month,c[i].date.year,c[i].address,c[i].email,c[i].phone_number);
                printf("Please enter a valid first name: ");
                gets(loadtemp[i].first_name);
                while(isstring(loadtemp[i].first_name)==false)
                {
                  printf("Please enter a valid first name: ");
                  gets(loadtemp[i].first_name);
                }

                strcpy(c[i].first_name,loadtemp[i].first_name);
//                printf("Please enter a valid last name: ");
//                gets(c[i].last_name);

            }
            if(!isstring(c[i].last_name))
            {
                printf("Contact number %d last name is not valid!\n" , i+1);
                printf("%s,%s,%d-%d-%d,%s,%s,%s\n",c[i].first_name,c[i].last_name,c[i].date.day,c[i].date.month,c[i].date.year,c[i].address,c[i].email,c[i].phone_number);
                printf("Please enter a valid last name: ");
                gets(loadtemp[i].last_name);
                while(isstring(loadtemp[i].last_name)==false)
                {
                  printf("Please enter a valid last name: ");
                  gets(loadtemp[i].last_name);
                }

                strcpy(c[i].last_name,loadtemp[i].last_name);

            }

            if(!isValidDate(c[i].date.day,c[i].date.month,c[i].date.year))
            {
                printf("Contact number %d Birthdate is not valid!\n" , i+1);
                printf("%s,%s,%d-%d-%d,%s,%s,%s\n",c[i].first_name,c[i].last_name,c[i].date.day,c[i].date.month,c[i].date.year,c[i].address,c[i].email,c[i].phone_number);
                printf("Please enter a valid birthdate: ");
                gets(dateofbirth);
                sscanf(dateofbirth , "%d-%d-%d" , &loadtemp[i].date.day, &loadtemp[i].date.month, &loadtemp[i].date.year);
                while(isValidDate(loadtemp[i].date.day,loadtemp[i].date.month,loadtemp[i].date.year)==false)
                {
                  printf("Please enter a valid birthdate: ");
                  gets(dateofbirth);
                sscanf(dateofbirth , "%d-%d-%d" , &loadtemp[i].date.day, &loadtemp[i].date.month, &loadtemp[i].date.year);
                }

                c[i].date.day=loadtemp[i].date.day;
                c[i].date.month=loadtemp[i].date.month;
                c[i].date.year=loadtemp[i].date.year;

            }

            if(containcomma(&c[i].address))
            {
                printf("Contact number %d address is not valid!\n" , i+1);
                printf("%s,%s,%d-%d-%d,%s,%s,%s\n",c[i].first_name,c[i].last_name,c[i].date.day,c[i].date.month,c[i].date.year,c[i].address,c[i].email,c[i].phone_number);
                printf("Please enter a valid address: ");
                gets(loadtemp[i].address);
                while(containcomma(&loadtemp[i].address)==true)
                {
                  printf("Please enter a valid address: ");
                  gets(loadtemp[i].address);
                }

                strcpy(c[i].address,loadtemp[i].address);

            }

            if(!isvalidEMAIL(&c[i].email))
            {
                printf("Contact number %d email is not valid!\n" , i+1);
                printf("%s,%s,%d-%d-%d,%s,%s,%s\n",c[i].first_name,c[i].last_name,c[i].date.day,c[i].date.month,c[i].date.year,c[i].address,c[i].email,c[i].phone_number);
                printf("Please enter a valid email: ");
                gets(loadtemp[i].email);
                while(isvalidEMAIL(&loadtemp[i].email)==false)
                {
                  printf("Please enter a valid email: ");
                  gets(loadtemp[i].email);
                }

                strcpy(c[i].email,loadtemp[i].email);

            }

//            if(!isvalidnumber(&c[i].phone_number))
//            {
//                printf("Contact number %d phone number is not valid!\n" , i+1);
//                printf("%s,%s,%d-%d-%d,%s,%s,%s\n",c[i].first_name,c[i].last_name,c[i].date.day,c[i].date.month,c[i].date.year,c[i].address,c[i].email,c[i].phone_number);
//                printf("Please enter a valid phone number: ");
//                gets(loadtemp[i].phone_number);
//                while(isvalidnumber(&loadtemp[i].phone_number)==false)
//                {
//                  printf("Please enter a valid phone number: ");
//                  gets(loadtemp[i].phone_number);
//                }
//
//                c[i].phone_number=loadtemp[i].phone_number;
//
//            }


//            while(isstring(c[i].last_name)==false)
//            {
//                printf("Contact number %d last name is not valid!\n" , i+1);
//                printf("%s,%s,%d-%d-%d,%s,%s,%s\n",c[i].first_name,c[i].last_name,c[i].date.day,c[i].date.month,c[i].date.year,c[i].address,c[i].email,c[i].phone_number);
//                printf("Please enter a last name: ");
//                gets(c[i].last_name);
//            }
//
//            while(isValidDate(c[i].date.day,c[i].date.month,c[i].date.year)==false)
//            {
//                printf("Contact number %d Birthdate is not valid!\n" , i+1);
//                printf("%s,%s,%d-%d-%d,%s,%s,%s\n",c[i].first_name,c[i].last_name,c[i].date.day,c[i].date.month,c[i].date.year,c[i].address,c[i].email,c[i].phone_number);
//                printf("Please enter a valid birthdate :");
//                gets(dateofbirth);
//                sscanf(dateofbirth , "%d-%d-%d" , &c[i].date.day, &c[i].date.month, &c[i].date.year);
//            }
//            while(containcomma(&c[i].address)==true)
//            {
//                printf("Contact number %d address is not valid!\n" , i+1);
//                printf("%s,%s,%d-%d-%d,%s,%s,%s\n",c[i].first_name,c[i].last_name,c[i].date.day,c[i].date.month,c[i].date.year,c[i].address,c[i].email,c[i].phone_number);
//                printf("Please enter a valid address: ");
//                gets(c[i].address);
//            }
//            while(isvalidEMAIL(&c[i].email)==false)
//            {
//                printf("Contact number %d email is not valid!\n" , i+1);
//                printf("%s,%s,%d-%d-%d,%s,%s,%s\n",c[i].first_name,c[i].last_name,c[i].date.day,c[i].date.month,c[i].date.year,c[i].address,c[i].email,c[i].phone_number);
//                printf("Please enter a valid email: ");
//                gets(c[i].email);
//            }
//            while(isvalidnumber(&c[i].phone_number)==false)
//            {
//                printf("Contact number %d phone number is not valid!\n" , i+1);
//                printf("%s,%s,%d-%d-%d,%s,%s,%s\n",c[i].first_name,c[i].last_name,c[i].date.day,c[i].date.month,c[i].date.year,c[i].address,c[i].email,c[i].phone_number);
//
//                printf("Please enter a valid phone number: ");
//                gets(c[i].phone_number);
//            }
       }

        // count--;
        // printf("%d",count);
        fclose(fptr);
        if(count==1 && !(isValidDate(c[0].date.day,c[0].date.month,c[0].date.year)) )
        {
            count =0;

        }
        printf("File ""%s"" was loaded succefully\n\n",directory);
    }


    // getch();
}


#endif // FILE_H_INCLUDED
