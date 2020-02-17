#ifndef ISVALID_H_INCLUDED
#define ISVALID_H_INCLUDED
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
const int maxyear = 2020;
const int minyear = 1950;

bool containcomma(char* test)
{
    int i;
    for(i=0;i<strlen(test);i++)
    {
        if(test[i]==',')
        {
            return true;
        }
    }
    return false;
}
bool isdigits(char* phone)
{
    //printf("%s",phone);
    int i;
    for(i=3; i<strlen(phone); i++)
    {
        if(*(phone+i)<'0' || *(phone+i)>'9')
        {
            return false;
        }
    }
    for(i=0; i<2; i++)
    {
        if(phone[i]<'0' || phone[i]>'9')
        {
            return false;
        }
    }
    if(phone[2]!='-' && strlen(phone)==10)
    {
        return false;
    }

    else
    {
        return true;
    }
}

bool isvalidnumber(char* phone)
{
    if(isdigits(phone)==false)
    {
        return false;
    }
    if (strlen(phone)!=10 && strlen(phone)!=11)
    {
        return false;
    }
    if(strlen(phone)==11 && (phone[0]!='0' || phone[1]!='1' ))
    {
        return false;
    };


    return true;

}

bool isvalidEMAIL(char* mail)
{
    if(containcomma(mail)==true)
    {
        return false;
    }

else{

    int atcounter=0;
    int dotcounter=0;
    int i,n;
    n=strlen(mail);
    for(i=0; i<n; i++)
    {
        if(mail[i]=='@')
        {
            atcounter++;
            if(atcounter>1)
            {
                return false;

            }

        }
        if(mail[i]=='.')
        {

            dotcounter++;


            if(mail[i+1]=='.')
            {
                return false;
            }
        }
        if(mail[i]==' ')
        {
            return false;
        }
    }


    if(mail[n-1]=='.' || mail[n-1]=='@' || mail[0]=='.' || mail[0]=='@' || atcounter!=1 || dotcounter<1 || (mail[n-4]!='.' && mail[n-3]!='.'))
    {
        return false;
    }
    else
        return true;

}
}
bool isLeap(int year)
{
// Return true if year
// is a multiple pf 4 and
// not multiple of 100.
// OR year is multiple of 400.
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}
bool isValidDate(int d, int m, int y)
{

    if (y > maxyear ||
            y < minyear)
        return false;
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > 31)
        return false;

    if (m == 2)
    {
        if (isLeap(y))
            return (d <= 29);
        else
            return (d <= 28);
    }

    if (m == 4 || m == 6 ||
            m == 9 || m == 11)
            {
            return (d <= 30);
            }


    return true;
}
bool isstring(char *test)
{
    int i;
    for(i=0;i<strlen(test);i++)
    {
        if (!(isalpha(test[i]) || isblank(test[i])))
        {
            return false;
        }
    }
    return true;
}
#endif // ISVALID_H_INCLUDED
