/*
* @name: cstring.c
* @author: Liu Hejian
* @date: 2021-10-20
* @version: 1.0
*/
#include "stdint.h"
#include "../include/cstring_private.h"
#include "ctype.h"
#include "stddef.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

/*
* @function: CreateCString
* @para: newString(type cstring*)
* @para: cstr(type const char*)
* @result: type cstring*
* @description: create new cstring struct, fill the new cstring member string with character of cstr, 
*               fill the new cstring
*/
CString *CreateCString(const char *cstr)
{
    CString *newstring = (CString *)malloc(sizeof(CString));
    if (!cstr)
    {
        newstring->string = NULL;
        newstring->length = 0;
        newstring->capcity = 0;
    }
    else
    {
        newstring->length = 0;
        char *str = (char *)cstr;
        for (; *str != '\0'; str++)
        {
            newstring->length++;
        }
        
        newstring->string = (char *)malloc(newstring->length + 1);

        
        newstring->capcity = newstring->length + 1;
        str = (char *)cstr;
        for (size_t i = 0; i != newstring->length + 1; i++)
        {
            (newstring->string)[i] = str[i];
        }
    }
    return newstring;
}
/*
* @function: CreateCStringWithChar
* @para: newstring(type CString*)
* @para: number(type size_t)
* @para: c(type char)
* @result: type CString*
* @description: createa new string filled of "number" characters "c" 
*/
CString *CreateCStringWithChar(const size_t number, const char c)
{
    CString *newstring = (CString *)malloc(sizeof(CString));
    if (number == 0)
    {
        newstring->string = NULL;
        newstring->capcity = 0;
        newstring->length = 0;
    }
    newstring->string = (char *)malloc((number + 1) * sizeof(char));
    newstring->length = number;
    newstring->capcity = number + 1;
    for (int i = 0; i != newstring->length; i++)
    {
        (newstring->string)[i] = c;
    }
    (newstring->string)[newstring->length] = '\0';
    return newstring;
}
/*
* @function: DestroyCString
* @para: string(type CString*)
* @result: void
* @description: Free the memory of CString, let the pointer of CString to be NULL
*/
void DestroyCString(CString *string)
{
    if (!string)
    {
        return;
    }
    else
    {
        if (string->length == 0)
        {
            string->string = NULL;
            string->capcity = 0;
        }
        else
        {
            free(string->string);
            string->length = 0;
            string->capcity = 0;
        }
        free(string);
        return;
    }
}
/*
* @function: CStringLength
* @para: string
* @result: size_t
* @description: return the length of characters in CString
*/
size_t CStringLength(const CString *string)
{
    return string->length;
}
/*
* @function: CStringCopy
* @para: lhs(type CString*)
* @para: rhs(type const CString*)
* @result: type void
* @description: copy CString rhs to CString lhs
*/
void CStringCopy(CString *lhs, const CString *rhs)
{
    if (rhs->length > lhs->capcity)
    {
        DestroyCString(lhs);
        lhs = CreateCStringWithChar(rhs->length + 1, 0);
    }
    for (size_t i = 0; i != rhs->length + 1; i++)
    {
        (lhs->string)[i] = (rhs->string)[i];
    }

    for (size_t i = lhs->length + 1; i < lhs->capcity; i++)
    {
        (lhs->string)[i] = 0;
    }
}
/*
* @function: CStringSearchChar
* @para: string(type CString*)
* @para: c(type char)
* @result: type long return the position of c found first in CString
* @description: Search 
*/
size_t CStringSearchChar(const CString *string, const char c,const size_t position)
{
    if(position>=string->length)
    {
        return string->length;
    }
    for (size_t i = position; i != string->length; i++)
    {
        if ((string->string)[i] == c)
        {
            return i;
        }
    }
    return string->length;
}
/*
* @function: CStringAt
* @para: position(type size_t)
* @result: return character which is copyed of character on the position of the CString
* @description: return character which is copyed of character on the position of the CString
*/
char CStringAt(const CString *string, const size_t position)
{
    if (position > string->length)
    {
        return -1;
    }
    else
    {
        return (string->string)[position];
    }
}
/*
* @function: CStringSearchString
* @para: string(type CString)
* @para: cstr(type const CString*)
* @result: type size_t
* @description: return the "cstr" first position in "string"
*/
size_t CStringSearchString(CString *string, const CString *cstr,const size_t position)
{
    if(position>=string->length)
    {
        return string->length;
    }
    size_t left = position;
    if (CStringLength(cstr) == 0)
    {
        return string->length;
    }
    while (left != string->length)
    {
        if (CStringAt(string, left) == CStringAt(cstr, 0))
        {
            size_t i = 0;
            for (i = 1; i != CStringLength(cstr); i++)
            {
                if (CStringAt(string, left + i) != CStringAt(cstr, i))
                {
                    break;
                }
            }
            if (i == CStringLength(cstr))
            {
                return left;
            }
        }
        left++;
    }
    return string->length;
}
/*
* @function: CStringCompare
* @para: lhs(type const CString*)
* @para: rhs(type const CString*)
* @result: type int
* @description: Negative value if lhs appears before rhs in lexicographical order.
*               Zero if lhs and rhs compare equal.
*               Positive value if lhs appears after rhs in lexicographical order.
*/
int CStringCompare(const CString *lhs, const CString *rhs)
{
    size_t length = lhs->length < rhs->length ? lhs->length : rhs->length;
    for (int i = 0; i != length; i++)
    {
        if (CStringAt(lhs, i) < CStringAt(rhs, i))
        {
            return -1;
        }
        else if (CStringAt(lhs, i) > CStringAt(rhs, i))
        {
            return 1;
        }
    }
    return CStringLength(lhs) < CStringLength(rhs) ? -1 : (CStringLength(lhs) > CStringLength(rhs) ? 1 : 0);
}
/*
* @function: CStringConcatenate
* @para: lhs(type CString)
* @para: rhs(type const CString)
* @result: type void
* @description: concatenate CString lhs with CString rhs
*/
void CStringConcatenate(CString *lhs, const CString *rhs)
{
    size_t length=CStringLength(lhs);
    CString* temp;
    if (rhs->length != 0)
    {
        if (lhs->capcity - lhs->length < rhs->length)
        {
            temp = CreateCStringWithChar(lhs->length + rhs->length, 0);
            CStringCopy(temp, lhs);
            //由于CString结构体的内存是在堆内存中的，因此在这里不能使用DestroyCString函数
            //DestroyCString函数会释放CString结构体的内存
            //因此这里这么设计
            //创建CString* temp，将temp中的内容浅拷贝到lhs中，释放temp结构体本身,让lhs接管temp内存
            lhs->string=temp->string;
            lhs->length=temp->length;
            lhs->capcity=temp->capcity;
            free(temp);
        }

        for (size_t i = 0; i <= rhs->length; i++)
        {
            (lhs->string)[length + i] = (rhs->string)[i];
        }
        (lhs->string)[lhs->length]='\0';
        
        
    }
}
/*
* @function: CStringInsertString
* @para: lhs(type CString*)
* @para: rhs(const CString*)
* @para: position(type const size_t)
* @result: type void
* @description: Insert the rhs to the position of the CString lhs  
*/
void CStringInsertString(CString *lhs, const size_t position, const CString *rhs)
{
    if (rhs->length != 0)
    {
        CString *temp = CreateCStringWithChar(rhs->length + lhs->length, 0);
        size_t pos;
        if (position < 0 || position >= lhs->length)
        {
            pos = lhs->length;
        }
        else
        {
            pos = position;
        }
        for (size_t i = 0; i != pos; i++)
        {
            (temp->string)[i] = (lhs->string)[i];
            
        }
        for (size_t i = 0; i != rhs->length; i++)
        {
            (temp->string)[pos + i] = (rhs->string)[i];
            
        }
        for (size_t i = 0; i != lhs->length - pos; i++)
        {
            (temp->string)[pos+rhs->length + i] = (lhs->string)[pos + i];
            
        }
        (temp->string)[temp->length] = '\0';
        //由于CString结构体的内存是在堆内存中的，因此在这里不能使用DestroyCString函数
        //DestroyCString函数会释放CString结构体的内存
        //因此这里这么设计
        //创建CString* temp，将temp中的内容浅拷贝到lhs中，释放temp结构体本身,让lhs接管temp内存
        lhs->string=temp->string;
        lhs->length=temp->length;
        lhs->capcity=temp->capcity;
        free(temp);
    }
}
/*
* @function: CStringDelete
* @para: string(type CString)
* @para: position(type const size_t)
* @para: length(type const size_t)
* @result: type void
* @description: delete fragment(length is the parameter length) of the CString from 
                    the position of the parameter position
*/
void CStringDelete(CString *lhs, const size_t position, const size_t length)
{
    if (position <= lhs->length)
    {
        size_t posleft = position;
        size_t posright = 0;
        if (position + length >= lhs->length)
        {
            posright = lhs->length;
        }
        else
        {
            posright = position + length;
        }
        for (size_t i = posleft; i <= posright; i++)
        {
            (lhs->string)[i] = (lhs->string)[posright + i - posleft];
        }
        for (size_t i = 0; i != length; i++)
        {
            (lhs->string)[lhs->length - length  + i] = 0;
        }
        lhs->length -= length;
        (lhs->string)[lhs->length] = '\0';
    }
}
/*
* @function: CStringSubString
* @para: string(type CString)
* @para: position(type const size_t)
* @para: length(type const size_t)
* @result: type CString* the copy of the substring
* @description: return the copy CString of the substring from the "position" with the "length" 
*/
CString *CStringSubString(CString *string, const size_t position, const size_t length)
{
    CString *result = CreateCStringWithChar(length, 0);
    for (size_t i = 0; i != length; i++)
    {
        (result->string)[i] = (string->string)[position + i];
    }
    (result->string)[result->length] = '\0';
    return result;
}
/*
* @function: CStringToCharArray
* @para: string(type CString*)
* @result: type char*
* @description: return a c style string.
*/
char *CStringToCharArray(CString *string)
{
    return string->string;
}
/*
* @function: CSTringIsEmpty
* @para: string(type CString*)
* @result: int
* @description: if the character array in CString is NULL return -2;
*               if the character array in CString has only one character such as '\0' return -1
*               else return 0; 
*/
extern int CStringIsEmpty(CString* string)
{
    if(!string->string)
    {
        return -1;
    }
    else if(string->length==0)
    {
        return -2;
    }
    else
    {
        return 0;
    }
}
/*
* @function: CStringSetChar
* @para: string(type CString*)
* @para: position(type size_t)
* @para: c(type char)
* @result: type int
* @description: if "position" is more than the length of "string", return -2;
*               if "string" is empty return -1;
*               else return "c";
*/
extern int CStringSetChar(CString* string,size_t position, char c)
{
    if(CStringIsEmpty(string)==0)
    {
        if(position>CStringLength(string))
        {
            return -2;
        }
        else
        {
            (string->string)[position]=c;
            return (int)c;
        }
    }
    else
    {
        return -1;
    }
}