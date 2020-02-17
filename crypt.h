#ifndef CRYPT_H_INCLUDED
#define CRYPT_H_INCLUDED
void encrypt(char* string)
{
    int n;
    n=strlen(string);
    int i;
    for(i=0;i<n;i++)
    {
        string[i]=string[i]+100;

    }
}
void decrypt(char*string)
{
 int i, n;
 n=strlen(string);
  for(i=0;i<n;i++)
    {
        string[i]=string[i]-100;

    }

}
void digitencrypt(int a, int b , int c)
{
    a += 7;
    b += 7;
    c += 7;
    a /= 10;
    b /= 10;
    c /= 10;
}
void digit_decrypt(int a,int b ,int c)
{
    a *= 10;
    b *= 10;
    c *= 10;
    a -= 7;
    b -= 7;
    c -= 7;
}
#endif // CRYPT_H_INCLUDED
