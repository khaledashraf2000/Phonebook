#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int day;
    int month;
    int year;

}dob;

typedef struct
{
    char first_name[200];
    char last_name[200];
    dob date;
    char address[500];
    char email[500];
    char phone_number[500];
    int found_first_name;
    int found_last_name;
    int found_address;
    int found_date;
    int found_phonenumber;
    int found_email;
} contact;

contact c[100];
int searchIndex[100];
int count = 0;
int loaded=0;
char directory[50];
//contact nullawy;
//nullawy.address = NULL;
//nullawy.email=NULL;
//nullawy.first_name=NULL;
//nullawy.last_name=NULL;
//nullawy.phone_number=NULL;
#endif // GLOBAL_H_INCLUDED
