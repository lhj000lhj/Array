/*
* @name: CStringProcess.c
* @author: Liu Hejian
* @date: 2021-10-21
* @version: 1.0
*/
#include "stdio.h"
#include "../include/cstring.h"
#include "string.h"
int main(int argc,char** argv)
{
    CString* string=CreateCString("abcd");
    CString* substring=CreateCString("123");
    size_t num=0;
    FILE* file=fopen("TestLog.txt","a+");
    //8.Testing Function CStringCopy
    num=fwrite("8.Testing Function CStringCopy\n",sizeof(char),
                    strlen("8.Testing Function CStringCopy\n"),file);
    num=fwrite("8.Testing Function CStringCopy\n",sizeof(char),
                    strlen("8.Testing Function CStringCopy\n"),stdout);
    char buffer[100];
    
    //Copy substring to string
    CStringCopy(string,substring);
    sprintf(buffer,"The string is \"abcd\", copy the \"123\" to first string is %s\n",CStringToCharArray(string));
    num=fwrite(buffer,sizeof(char),strlen(buffer),file);
    num=fwrite(buffer,sizeof(char),strlen(buffer),stdout);
    
    DestroyCString(string);
    DestroyCString(substring);
    fputc('\n',file);
    fputc('\n',stdout);

    //9.Testing Function CStringConcatenate
    string=CreateCString("abcd");
    substring=CreateCString("123");
    num=fwrite("9.Testing Function CStringConcatenate\n",sizeof(char),
                    strlen("9.Testing Function CStringConcatenate\n"),file);
    num=fwrite("9.Testing Function CStringConcatenate\n",sizeof(char),
                    strlen("9.Testing Function CStringConcatenate\n"),stdout);
    
    CStringConcatenate(string,substring);
    sprintf(buffer,"The string is \"abcd\", concatenate the \"123\" to first string is %s\n",CStringToCharArray(string));
    num=fwrite(buffer,sizeof(char),strlen(buffer),file);
    num=fwrite(buffer,sizeof(char),strlen(buffer),stdout);
    DestroyCString(string);
    DestroyCString(substring);
    fputc('\n',file);
    fputc('\n',stdout);
    
    //10.Testing Function CStringInsertString
    string=CreateCString("abcd");
    substring=CreateCString("123");
    num=fwrite("10.Testing Function CStringInsertString\n",sizeof(char),
                    strlen("10.Testing Function CStringInsertString\n"),file);
    num=fwrite("10.Testing Function CStringInsertString\n",sizeof(char),
                    strlen("10.Testing Function CStringInsertString\n"),stdout);
    
    CStringInsertString(string,2,substring);
    sprintf(buffer,"The string is \"abcd\", insert the \"123\" to the position 2 is %s\n",CStringToCharArray(string));
    num=fwrite(buffer,sizeof(char),strlen(buffer),file);
    num=fwrite(buffer,sizeof(char),strlen(buffer),stdout);
    DestroyCString(string);
    DestroyCString(substring);
    fputc('\n',file);
    fputc('\n',stdout);

    //11.Testing Function CStringDelete
    string=CreateCString("abcd123abcd");
    num=fwrite("11.Testing Function CStringDelete\n",sizeof(char),
                    strlen("11.Testing Function CStringDelete\n"),file);
    num=fwrite("11.Testing Function CStringDelete\n",sizeof(char),
                    strlen("11.Testing Function CStringDelete\n"),stdout);
    
    CStringDelete(string,4,3);
    sprintf(buffer,"The string is \"abcd123abcd\", delete the \"123\" is %s\n",CStringToCharArray(string));
    num=fwrite(buffer,sizeof(char),strlen(buffer),file);
    num=fwrite(buffer,sizeof(char),strlen(buffer),stdout);
    DestroyCString(string);
    fputc('\n',file);
    fputc('\n',stdout);

    //11.Testing Function CStringSubString
    string=CreateCString("abcd123abcd");
    num=fwrite("11.Testing Function CStringDelete\n",sizeof(char),
                    strlen("11.Testing Function CStringDelete\n"),file);
    num=fwrite("11.Testing Function CStringDelete\n",sizeof(char),
                    strlen("11.Testing Function CStringDelete\n"),stdout);
    
    substring=CStringSubString(string,4,3);
    sprintf(buffer,"The string is \"abcd123abcd\", substring, the \"123\" is %s\n",CStringToCharArray(substring));
    num=fwrite(buffer,sizeof(char),strlen(buffer),file);
    num=fwrite(buffer,sizeof(char),strlen(buffer),stdout);
    DestroyCString(string);
    DestroyCString(substring);
    fputc('\n',file);
    fputc('\n',stdout);


    //12.Testing Function CStringIsEmpty
    string=CreateCString("abcd123abcd");
    num=fwrite("12.Testing Function CStringIsEmpty\n",sizeof(char),
                    strlen("12.Testing Function CStringIsEmpty\n"),file);
    num=fwrite("12.Testing Function CStringIsEmpty\n",sizeof(char),
                    strlen("12.Testing Function CStringIsEmpty\n"),stdout);
    sprintf(buffer,"The string is \"abcd123abcd\", result of CStringIsEmpty is %d\n",CStringIsEmpty(string));
    num=fwrite(buffer,sizeof(char),strlen(buffer),file);
    num=fwrite(buffer,sizeof(char),strlen(buffer),stdout);
    DestroyCString(string);
    string=CreateCString("");
    sprintf(buffer,"The string is \"\", result of CStringIsEmpty is %d\n",CStringIsEmpty(string));
    num=fwrite(buffer,sizeof(char),strlen(buffer),file);
    num=fwrite(buffer,sizeof(char),strlen(buffer),stdout);
    DestroyCString(string);
    string=CreateCString(NULL);
    sprintf(buffer,"The string is NULL, result of CStringIsEmpty is %d\n",CStringIsEmpty(string));
    num=fwrite(buffer,sizeof(char),strlen(buffer),file);
    num=fwrite(buffer,sizeof(char),strlen(buffer),stdout);
    DestroyCString(string);
    fputc('\n',file);
    fputc('\n',stdout);

    //13.Testing Function CStringSetChar
    string=CreateCString("abcd123abcd");
    num=fwrite("13.Testing Function CStringSetChar\n",sizeof(char),
                    strlen("13.Testing Function CStringSetChar\n"),file);
    num=fwrite("13.Testing Function CStringSetChar\n",sizeof(char),
                    strlen("13.Testing Function CStringSetChar\n"),stdout);
    
    int r=CStringSetChar(string,7,'c');
    sprintf(buffer,"The string is \"abcd123abcd\", set position 7 'c' is %s return %c\n",CStringToCharArray(string),(char)r);
    num=fwrite(buffer,sizeof(char),strlen(buffer),file);
    num=fwrite(buffer,sizeof(char),strlen(buffer),stdout);
    DestroyCString(string);
    fputc('\n',file);
    fputc('\n',stdout);
    fclose(file);
    return 0;
}