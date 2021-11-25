/*
* @name: Array_private.c
* @author: Liu Hejian
* @date: 2021-11-23
* @version: 1.0
*/
#include "Array_private.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "assert.h"
#include "errno.h"

ICEAPI_PRIVATE Array* _CreateArray()
{
    Array *newarray = (Array *)malloc(sizeof(Array));
    if (newarray == NULL)
    {
        perror("function malloc failed!\n");
        exit(-1);
    }
    newarray->objects = (void **)malloc(8 * sizeof(void *));
    if (newarray->objects == NULL)
    {
        perror("function malloc failed!\n");
        exit(-1);
    }
    newarray->capacity = 8;
    newarray->length = 0;
    
    return newarray;
}

ICEAPI_PRIVATE  Array* _CreateArrayWithCapacity(unsigned long capacity)
{
    Array *newarray = (Array *)malloc(sizeof(Array));
    if (newarray == NULL)
    {
        perror("function malloc failed!\n");
        exit(-1);
    }
    newarray->length = 0;
    newarray->capacity = capacity;
    newarray->objects = (void **)malloc(capacity * sizeof(void *));
    if (newarray->objects == NULL)
    {
        perror("function malloc failed!\n");
        exit(-1);
    }
    return newarray;
}

ICEAPI_PRIVATE int _DestroyArray(Array *array, int (*DestoryObject)(void *object))
{
    if (array == NULL)
    {
        return 0;
    }
    if (DestoryObject != NULL)
    {
        for (unsigned long i = 0; i != array->length; i++)
        {
            if (0 != DestoryObject((void *)array->objects[i]))
            {
                perror("Destroy Object in Array is Failed\n");
                exit(-1);
            }
        }
    }
    free(array->objects);
    free(array);
    return 0;
}

ICEAPI_PRIVATE  int _ArraySetCapacity(Array *array, unsigned long capacity)
{
    assert(array != NULL);
    assert(array->length < capacity);
    //先开新的空间
    void **newobjects = (void **)malloc(capacity * sizeof(void *));
    if (newobjects == NULL)
    {
        perror("function malloc failed!\n");
        exit(-1);
    }
    //拷贝原来的到新开的空间里面
    for (unsigned long i = 0; i != array->length; i++)
    {
        newobjects[i] = array->objects[i];
    }
    free(array->objects);
    array->objects = newobjects;
    array->capacity = capacity;
    return 0;
}
ICEAPI_PRIVATE  int _ArrayAddObject(Array *array, unsigned long position, void *object)
{
    assert(array != NULL);
    assert(position <= array->capacity);
    assert(position <= array->length);
    
    
    if (array->length == array->capacity)
    {
        if (array->capacity >= 1)
        {
            _ArraySetCapacity(array, (unsigned long)(1.5 * array->capacity));
        }
        else
        {
            _ArraySetCapacity(array, 8);
        }
    }
    for (unsigned long i = array->length; i != position; i--)
    {
        array->objects[i] = array->objects[i - 1];
    }
    array->objects[position] = object;
    array->length++;
    
    return 0;
}

ICEAPI_PRIVATE int _ArrayEmplace(Array* array,unsigned long position,
                                    void* (*CreateObject)(void* parameter),void* parameter)
{
    assert(array!=NULL);
    assert(position <= array->capacity);
    assert(position <= array->length);
    
    if (array->length == array->capacity)
    {
        if (array->capacity >= 1)
        {
            _ArraySetCapacity(array, (unsigned long)(1.5 * array->capacity));
        }
        else
        {
            _ArraySetCapacity(array, 10);
        }
    }
    void* object=CreateObject(parameter);
    for (unsigned long i = array->length; i != position; i--)
    {
        array->objects[i] = array->objects[i - 1];
    }
    array->objects[position] = object;
    array->length++;
    
    
    return 0;
}

ICEAPI_PRIVATE  int _ArrayEmplaceBack(Array *array, void *(*CreateObject)(void *parameter), void *parameter)
{
    assert(array != NULL);
    if (array->length == array->capacity)
    {
        if (array->capacity >= 1)
        {
            _ArraySetCapacity(array, (unsigned long)(1.5 * array->capacity));
        }
        else
        {
            _ArraySetCapacity(array, 10);
        }
    }
    array->objects[array->length] = CreateObject(parameter);
    array->length++;
    return 0;
}
ICEAPI_PRIVATE int _ArrayDeleteObject(Array *array, unsigned long position, int (*DestroyObject)(void *))
{
    assert(array != NULL);
    assert(position < array->length);
    if (0 != DestroyObject(array->objects[position]))
    {
        perror("Destroy Object in Array Failed!\n");
        exit(-1);
    }
    for (unsigned long i = position; i != array->length - 1; i++)
    {
        array->objects[i] = array->objects[i + 1];
    }
    array->length--;
    return 0;
}
ICEAPI_PRIVATE int _ArrayIsEmpty(Array *array)
{
    assert(array != NULL);
    if (array->length == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
ICEAPI_PRIVATE unsigned long _ArrayLength(Array *array)
{
    assert(array != NULL);
    return array->length;
}
ICEAPI_PRIVATE unsigned long _ArrayCapacity(Array *array)
{
    assert(array != NULL);
    return array->capacity;
}
ICEAPI_PRIVATE void* _ArrayAt(Array *array, unsigned long position)
{
    assert(array != NULL);
    assert(position < array->length);
    return array->objects[position];
}
ICEAPI_PRIVATE void* _ArraySet(Array *array, unsigned long position, void *object)
{
    assert(array != NULL);
    assert(position < array->length);
    void *objtemp = NULL;
    objtemp = array->objects[position];
    array->objects[position] = object;
    return objtemp;
}
ICEAPI_PRIVATE int _ArraySetObject(Array *array, unsigned long position, void *object, int (*DestroyObject)(void *object))
{
    assert(array != NULL);
    assert(position < array->length);
    assert(DestroyObject != NULL);
    if (0 != DestroyObject(array->objects[position]))
    {
        array->objects[position] = object;
        return 0;
    }
    return -1;
}
ICEAPI_PRIVATE  void _ArrayPrintObject(Array *array, void (*ObjectPrint)(void *object))
{
    assert(array != NULL);
    assert(ObjectPrint != NULL);
    for (unsigned long i = 0; i != array->length; i++)
    {
        ObjectPrint(array->objects[i]);
        putc(' ', stdout);
    }
}
