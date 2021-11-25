/*
* @name: cstring_private.h
* @author: Liu Hejian
* @date: 2021-10-21
* @version: 1.0
*/
#ifndef __CSTRING_PRIVATE_H__
#define __CSTRING_PRIVATE_H__ //__CSTRING_PRIVATE_H__
#include "ctype.h"
#include "stddef.h"
#include "stdint.h"
/*
* @struct: CString
* @member: string(type char*)
* @member: length(type size_t)
* @method: 
* @description: the object to describe string coded by c language
*/
typedef struct CString
{
    char *string;
    size_t length;
    size_t capcity;
} CString;
#endif //!__CSTRING_PRIVATE_H__