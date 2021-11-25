/*
* @name: CStringSearch.c
* @author: Liu Hejian
* @date: 2021-10-21
* @version: 1.0
*/

#include "../include/cstring.h"
#include "stdio.h"
#include "string.h"
int main(int argc,char** argv)
{
    
    CString* string=CreateCString("abcd123abcd");
    char c='c';
    size_t num=0;
    FILE* file=fopen("TestLog.txt","a+");
    //6.Testing Function CStringSearchChar
    num=fwrite("6.Testing Function CStringSearchChar\n",sizeof(char),
                    strlen("6.Testing Function CStringSearchChar\n"),file);
    num=fwrite("6.Testing Function CStringSearchChar\n",sizeof(char),
                    strlen("6.Testing Function CStringSearchChar\n"),stdout);
    char buffer[100];
    size_t pos=0;
    sprintf(buffer,"The string is \"abcd123abcd\", find the \'c\' position is %ld\n",pos=CStringSearchChar(string,c,0));
    num=fwrite(buffer,sizeof(char),strlen(buffer),file);
    num=fwrite(buffer,sizeof(char),strlen(buffer),stdout);
    sprintf(buffer,"The string is \"abcd123abcd\", find the \'c\' position is %ld\n",pos=CStringSearchChar(string,c,pos+1));
    num=fwrite(buffer,sizeof(char),strlen(buffer),file);
    num=fwrite(buffer,sizeof(char),strlen(buffer),stdout);
    DestroyCString(string);
    fputc('\n',file);
    fputc('\n',stdout);

    //7.Testing Function CStringSearchString
    string=CreateCString("abcd123123");
    num=fwrite("7.Testing Function CStringSearchString\n",sizeof(char),
                    strlen("7.Testing Function CStringSearchString\n"),file);
    num=fwrite("7.Testing Function CStringSearchString\n",sizeof(char),
                    strlen("7.Testing Function CStringSearchString\n"),stdout);
    pos=0;
    CString* substring=CreateCString("123");
    sprintf(buffer,"The string is \"abcd123123\", find the \"123\" position is %ld\n",
                    pos=CStringSearchString(string,substring,0));
    num=fwrite(buffer,sizeof(char),strlen(buffer),file);
    num=fwrite(buffer,sizeof(char),strlen(buffer),stdout);
    sprintf(buffer,"The string is \"abcd123123\", find another \"123\" position is %ld\n",
                    pos=CStringSearchString(string,substring,pos+CStringLength(substring)));
    num=fwrite(buffer,sizeof(char),strlen(buffer),file);
    num=fwrite(buffer,sizeof(char),strlen(buffer),stdout);
    DestroyCString(substring);
    DestroyCString(string);
    fputc('\n',file);
    fputc('\n',stdout);
    fclose(file);
    return 0;
}