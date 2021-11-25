/*
* @name: cstring.h
* @author: Liu Hejian
* @date: 2021-10-20
* @version: 1.0
*/
#ifndef __CSTRING_H__ 
#define __CSTRING_H__ //__CSTRING_H__
#include "ctype.h"
#include "stddef.h"
#include "stdint.h"

typedef struct CString CString;

/*
* @function: CreateCString
* @para: newString(type cstring*)
* @para: cstr(type const char*)
* @result: type cstring*
* @description: create new cstring struct, fill the new cstring member string with character of cstr, fill the new cstring
*/
extern CString* CreateCString(const char* cstr);
/*
* @function: CreateCStringWithChar
* @para: newstring(type CString*)
* @para: number(type size_t)
* @para: c(type char)
* @result: type CString*
* @description: createa new string filled of "number" characters "c" 
*/
extern CString* CreateCStringWithChar(const size_t number,const char c);
/*
* @function: DestroyCString
* @para: string(type CString*)
* @result: void
* @description: Free the memory of CString, let the pointer of CString to be NULL
*/
extern void DestroyCString(CString* string);
/*
* @function: CStringLength
* @para: string
* @result: size_t
* @description: return the length of characters in CString
*/
extern size_t CStringLength(const CString* string);
/*
* @function: CStringSearchChar
* @para: string(type CString*)
* @para: c(type char)
* @result: type long return the position of c found first in CString
* @description: Search "c" first position
*/
extern size_t CStringSearchChar(const CString* string, const char c,const size_t position);
/*
* @function: CStringAt
* @para: position(type size_t)
* @result: return character which is copyed of character on the position of the CString
* @description: return character which is copyed of character on the position of the CString
*/
extern char CStringAt(const CString* string, const size_t position);
/*
* @function: CStringSearchString
* @para: string(type CString)
* @para: cstr(type const CString*)
* @result: type size_t
* @description: return the "cstr" first position in "string"
*/
extern size_t CStringSearchString(const CString* string,const CString* cstr,const size_t position);
/*
* @function: CStringCompare
* @para: lhs(type const CString*)
* @para: rhs(type const CString*)
* @result: type int
* @description: Negative value if lhs appears before rhs in lexicographical order.
*               Zero if lhs and rhs compare equal.
*               Positive value if lhs appears after rhs in lexicographical order.
*/
extern int CStringCompare(const CString* lhs,const CString* rhs);
/*
* @function: CStringCopy
* @para: lhs(type CString*)
* @para: rhs(type const CString*)
* @result: type void
* @description: copy CString rhs to CString lhs
*/
extern void CStringCopy(CString* lhs,const CString* rhs);
/*
* @function: CStringConcatenate
* @para: lhs(type CString)
* @para: rhs(type const CString)
* @result: type void
* @description: concatenate CString lhs with CString rhs
*/
extern void CStringConcatenate(CString* lhs, const CString* rhs);
/*
* @function: CStringInsertString
* @para: lhs(type CString*)
* @para: rhs(const CString*)
* @para: position(type const size_t)
* @result: type void
* @description: Insert the rhs to the position of the CString lhs  
*/
extern void CStringInsertString(CString* lhs,const size_t position, const CString* rhs);
/*
* @function: CStringDelete
* @para: string(type CString)
* @para: position(type const size_t)
* @para: length(type const size_t)
* @result: type void
* @description: delete fragment(length is the parameter length) of the CString from 
                    the position of the parameter position
*/
extern void CStringDelete(CString* lhs,const size_t position, const size_t length);
/*
* @function: CStringSubString
* @para: string(type CString)
* @para: position(type const size_t)
* @para: length(type const size_t)
* @result: type CString* the copy of the substring
* @description: return the copy CString of the substring from the "position" with the "length" 
*/
extern CString* CStringSubString(CString* string,const size_t position,const size_t length);
/*
* @function: CStringToCharArray
* @para: string(type CString*)
* @result: type char*
* @description: return a c style string.
*/
extern char* CStringToCharArray(CString* string);
/*
* @function: CSTringIsEmpty
* @para: string(type CString*)
* @result: type int
* @description: if the character array in CString is NULL return -2;
*               if the character array in CString has only one character as '\0' return -1
*               else return 0; 
*/
extern int CStringIsEmpty(CString* string);
/*
* @function: CStringSetChar
* @para: string(type CString*)
* @para: position(type size_t)
* @para: c(type char)
* @result: type int
* @description: if "position" is more than the length of "string", return -1;
*               if "string" is empty return -2;
*               else return "c";
*/
extern int CStringSetChar(CString* string,size_t position, char c); 
#endif //!__CSTRING_H__