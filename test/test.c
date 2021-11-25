/*
* @name: test.c
* @author: Liu Hejian
* @date: 2021-11-24
* @version: 1.0
*/
#include "./cstring/include/cstring.h"
#include "../include/Array.h"
#include "stdio.h"
void CStringPrint(void* string);
int DestroyString(void* string);
void* CStringCreateWithString(void* string);
int main(int argc,char** argv)
{
    CString* string1=CreateCString("123456");
    CString* string2=CreateCString("abcde");
    CString* string3=CreateCString("123abc");
    Array* array=CreateArray();
    int ret=ArrayAddObject(array,0,string1);
    ret=ArrayAddObject(array,ArrayLength(array),string2);
    ret=ArrayAddObject(array,ArrayLength(array),string3);
    for(int i=3;i!=10;i++)
    {
        CString* string=CreateCString("ABC123ABC123113131313");
        ret=ArrayAddObject(array,ArrayLength(array),string);
        printf("%ld %ld\n",ArrayLength(array),ArrayCapacity(array));
    }
    ArrayPrintObject(array,CStringPrint);
    putc('\n',stdout);
    for(int i=0;i!=10;i++)
    {
        ret=ArrayEmplace(array,0,CStringCreateWithString,(void*)("Emplace"));
        printf("%ld %ld\n",ArrayLength(array),ArrayCapacity(array));
    }
    ArrayPrintObject(array,CStringPrint);
    putc('\n',stdout);
    for(int i=0;i!=10;i++)
    {
        ret=ArrayEmplaceBack(array,CStringCreateWithString,(void*)("EmlpaceBack"));
        printf("%ld %ld\n",ArrayLength(array),ArrayCapacity(array));
    }
    ArrayPrintObject(array,CStringPrint);
    putc('\n',stdout);
    for(int i=0;i!=15;i++)
    {
        ret=ArrayDeleteObject(array,7,DestroyString);
        printf("%ld %ld\n",ArrayLength(array),ArrayCapacity(array));
    }
    ArrayPrintObject(array,CStringPrint);
    putc('\n',stdout);
    DestroyArray(array,DestroyString);
    return 0;
}
void CStringPrint(void* string)
{
    printf("%s",CStringToCharArray((CString*)string));
    
}
int DestroyString(void* string)
{
    DestroyCString((CString*)string);
    return 0;
}
void* CStringCreateWithString(void* string)
{
    return CreateCString((char*)string);
}
