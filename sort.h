#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include"global.h"
#include<stdio.h>
#include<string.h>
void sortbylastname()
{
    int i,j;
    contact temp;
    for(i=0; i<count; i++)
    {
        for(j=i+1; j<count; j++)
        {
            if(strcasecmp(c[i].last_name,c[j].last_name)<0)
            {
                temp=c[i];
                c[i]=c[j];
                c[j]=temp;

            }
        }
    }
    printf("************\tYour Contacts have been sorted by their last names succefully\t************\n\n");
    int countofsort;
    for(countofsort=0; countofsort<count; countofsort++)
    {
        printf("%s,%s,%d-%d-%d,%s,%s,%s\n",c[countofsort].first_name,c[countofsort].last_name,c[countofsort].date.day,c[countofsort].date.month,c[countofsort].date.year,c[countofsort].address,c[countofsort].email,c[countofsort].phone_number);
    }

}
void sortbydob()
{
    int i,j;
    contact temp;
    for(i=0; i<count; i++)
    {
        for(j=i+1; j<count; j++)
        {
            if((c[i].date.year>c[j].date.year))
            {
                temp=c[i];
                c[i]=c[j];
                c[j]=temp;

            }
        }

    }

     for(i=0; i<count; i++)
    {
        for(j=i+1; j<count; j++)
        {
            if(c[i].date.year==c[j].date.year)
            {
              if((c[i].date.month>c[j].date.month))
            {
                temp=c[i];
                c[i]=c[j];
                c[j]=temp;

            }
            else if (c[i].date.month=c[j].date.month)
            {
              if((c[i].date.day>c[j].date.day))
            {
                temp=c[i];
                c[i]=c[j];
                c[j]=temp;

            }
            }
            }
        }
    }



    printf("************\tYour Contacts have been sorted by their Dates Of Births succefully\t************\n\n");
    int countofsort;
    for(countofsort=0; countofsort<count; countofsort++)
    {
        printf("%s,%s,%d-%d-%d,%s,%s,%s\n",c[countofsort].first_name,c[countofsort].last_name,c[countofsort].date.day,c[countofsort].date.month,c[countofsort].date.year,c[countofsort].address,c[countofsort].email,c[countofsort].phone_number);
    }
}

int SEARCHBYLAST()
{
    if(loaded==0)
    {
        printf("Please make sure you have loaded a contact directory first");
    }
    else if(loaded==1 && count==0)
    {
        printf("\nPlease make sure you have contacts in your LOADED directory");
    }
    else
    {
        //printf("\n\nEnter the last name you wish to search: ");
        char name[20];
        gets(name);
        printf("\n");
//    FILE* fptr;
//    fptr=fopen("contacts.txt","r");
//    if(fptr==NULL)
//        printf("Error");
//    else
        //{
        int o;
        for(o=0; o<100; o++)
            searchIndex[o]=-1;

        int i,j=0,flag=0;
        for(i=0; i<count; i++)
        {
            if(!strcasecmp(c[i].last_name,name))
            {
                printf("%d-%s,%s,%s,%s\n",j+1,c[i].first_name,c[i].address,c[i].email,c[i].phone_number);
                searchIndex[j++]=i;
                flag =1;
            }


        }
//        for(j=0; searchIndex[j]>-1; j++)
//            printf("%d\n",searchIndex[j]);
        if(flag==0)
        {
            printf("not found!\n");
            return 1;
        }
        // fclose(fptr);
        //}
    }
    return 0;
}

#endif // SORT_H_INCLUDED
