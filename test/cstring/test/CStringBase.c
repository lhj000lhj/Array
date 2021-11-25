/*
* @name: cstringtest.c
* @author: Liu Hejian
* @date: 2021-10-21
* @version: 1.0
*/
#include "stdio.h"
#include "../include/cstring.h"
#include "string.h"
int main(int argc,char** argv)
{
    size_t num=0;
    FILE* file=fopen("TestLog.txt","w");

    //1. Create a new CString
    num=fwrite("1. Create a new CString\n",sizeof(char),strlen("1. Create a new CString\n"),file);
    num=fwrite("1. Create a new CString\n",sizeof(char),strlen("1. Create a new CString\n"),stdout);
    CString* string=CreateCString("abcd");
    fputc('\n',file);
    fputc('\n',stdout);

    //2.Testing Function CreateCString and CStringToCharArray
    num=fwrite("2.Testing Function CreateCString and CStringToCharArray\n",sizeof(char),
                    strlen("2.Testing Function CreateCString and CStringToCharArray\n"),file);
    num=fwrite("2.Testing Function CreateCString and CStringToCharArray\n",sizeof(char),
                    strlen("2.Testing Function CreateCString and CStringToCharArray\n"),stdout);
    char buffer[100];
    sprintf(buffer,"Create a new string is \"abcd\", the string in CString is %s\n",CStringToCharArray(string));
    num=fwrite(buffer,sizeof(char),strlen(buffer),file);
    num=fwrite(buffer,sizeof(char),strlen(buffer),stdout);
    DestroyCString(string);
    fputc('\n',file);
    fputc('\n',stdout);

    //3.Testing Function CreateCStringWithChar
    num=fwrite("3.Testing Function CreateCStringWithChar\n",sizeof(char),
                    strlen("3.Testing Function CreateCStringWithChar\n"),file);
    num=fwrite("3.Testing Function CreateCStringWithChar\n",sizeof(char),
                    strlen("3.Testing Function CreateCStringWithChar\n"),stdout);
    string=CreateCStringWithChar(6,'c');
    sprintf(buffer,"Create a new string is \"cccccc\", the string in CString is %s\n",CStringToCharArray(string));
    num=fwrite(buffer,sizeof(char),strlen(buffer),file);
    num=fwrite(buffer,sizeof(char),strlen(buffer),stdout);
    DestroyCString(string);
    fputc('\n',stdout);
    fputc('\n',file);
    

    //4.Testing Function CStringLength
    num=fwrite("4.Testing Function CStringLength\n",sizeof(char),
                    strlen("4.Testing Function CStringLength\n"),file);
    num=fwrite("4.Testing Function CStringLength\n",sizeof(char),
                    strlen("4.Testing Function CStringLength\n"),stdout);
    string=CreateCString("abcd123");
    sprintf(buffer,"Create a new string is \"abcd123\", the string length is %ld\n",CStringLength(string));
    num=fwrite(buffer,sizeof(char),strlen(buffer),file);
    num=fwrite(buffer,sizeof(char),strlen(buffer),stdout);
    DestroyCString(string);
    fputc('\n',stdout);
    fputc('\n',file);

    //5.Testing Function CStringAt
    num=fwrite("5.Testing Function CStringAt\n",sizeof(char),
                    strlen("5.Testing Function CStringAt\n"),file);
    num=fwrite("5.Testing Function CStringAt\n",sizeof(char),
                    strlen("5.Testing Function CStringAt\n"),stdout);
    string=CreateCString("abcd123");
    sprintf(buffer,"Create a new string is \"abcd123\", the char at the position 5 is %c\n",CStringAt(string,5));
    num=fwrite(buffer,sizeof(char),strlen(buffer),file);
    num=fwrite(buffer,sizeof(char),strlen(buffer),stdout);
    sprintf(buffer,"The string is \"abcd123\", the char at the position 2 is %c\n",CStringAt(string,2));
    num=fwrite(buffer,sizeof(char),strlen(buffer),file);
    num=fwrite(buffer,sizeof(char),strlen(buffer),stdout);
    DestroyCString(string);
    fputc('\n',stdout);
    fputc('\n',file);
    fclose(file);
    return 0;
}