/*
* @name: Array.c
* @author: Liu Hejian
* @date: 2021-11-24
* @version: 1.0
*/
#include "../include/Array.h"
#include "Array_private.h"

/*
* @function: CreateArray
* @para: void
* @result: Array*
* @description: Create a empty Array with Capacity 8 return the pointer of the new array object, the memory of array is only allocated on heap
*/
ICEAPI Array* CreateArray()
{
    return _CreateArray();
}
/*
* @function: CreateArrayWithCapacity
* @para: capacity(type unsigned long)
* @result: Array*
* @description: Create a Array with @capacity return the pointer of 
                    the new array object, the memory of array is only allocated on heap
*/
ICEAPI Array* CreateArrayWithCapacity(unsigned long capacity)
{
    return _CreateArrayWithCapacity(capacity);
}
/*
* @function: DestroyArray
* @para: array(type Array*)
* @para: Destroy
* @result: type int,
* @description: Destroy the array struct free the memory of the @array and the elements of @array,
                    failed will be aborted with code -1, the function @DestroyObject will destroy
                    every element of @array, if the @DestroyObject return 0, it will be successfull,
                    if not, program will exit with code -1
*/


ICEAPI int DestroyArray(Array* array, int (*DestroyObject)(void* object))
{
    return _DestroyArray(array,DestroyObject);
}

/*
* @function: ArrayAddObject
* @para: array(type Array*)
* @para: position(type unsigned long)
* @para: object(type void*)
* @result: int
* @description: add the @object into the @position of the @array, 
                    user must confirm the type of the @object is same with element in @array
*/
ICEAPI int ArrayAddObject(Array* array,unsigned long position,void* object)
{
    return _ArrayAddObject(array,position,object);
}
/*
* @function: ArrayEmplace
* @para: array(type Array*)
* @para: position(type unsigned long)
* @para: CreateObject(type void* (*)(void* parameter))
* @para: parameter(type void*)
* @result: type int
* @description: build a new object and insert it to the @position of @array
                    function use @CreateObject to build the new object, and 
                    @parameter is the parameter of the function @CreateObject   
*/
ICEAPI int ArrayEmplace(Array* array,unsigned long position,
                                    void* (*CreateObject)(void* parameter),void* parameter)
{
    return _ArrayEmplace(array,position,CreateObject,parameter);
}
/*
* @function: ArrayEmplaceBack 
* @para: array(type Array*)
* @para: position(type unsigned long)
* @para: CreateObject(type int (*)(void* parameter))
* @para: parameter(type void*)
* @result: type int
* @description: use user's function to create a new object insertin the position of @position
                    function pointer @CreateObject should use the parameter struct to finish creating of object
                    @CreateObject should analysis the @parameter itself and return the pointer(type void*) of the 
                    element to be inserted.
*/
ICEAPI int ArrayEmplaceBack(Array* array,void* (*CreateObject)(void* parameter),void* parameter)
{
    return _ArrayEmplaceBack(array,CreateObject,parameter);
}
/*
* @function: _ArrayDeleteObject
* @para: array(type Array*)
* @para: position(type unsigned long)
* @para: @DestroyObject(type int (*)(void* object))
* @result: type int
* @description: Delete the element in @position used the function DestroyObject to free the memory of the element,
                    if the @DestroyObject return 0, it will be successfull,
                    if not, program will exit with code -1
*/
ICEAPI int ArrayDeleteObject(Array* array, unsigned long position,int (*DestroyObject)(void* object))
{
    return _ArrayDeleteObject(array,position,DestroyObject);
}
/*
* @function: _ArrayAt
* @para: array(type Array*)
* @para: position(type unsigned long)
* @result: type void*
* @description: return the element pointer in position @position of @array
*/
ICEAPI void* ArrayAt(Array* array,unsigned long position)
{
    return _ArrayAt(array,position);
}
/*
* @function: _ArraySetCapacity
* @para: array(type Array*)
* @para: capacity(type unsigned long)
* @result: type int
* @description: Set larger capacity of @array, @capacity should be larger than length of @array
                    if return 0, this function will be successfull
*/
ICEAPI int ArraySetCapacity(Array* array,unsigned long capacity)
{
    return _ArraySetCapacity(array,capacity);
}
/*
* @function: _ArrayLength
* @para: array(type Array*)
* @result: type unsigned long
* @description: return the length of @array
*/
ICEAPI unsigned long ArrayLength(Array* array)
{
    return _ArrayLength(array);
}
/*
* @function: _ArrayCapacity
* @para: array(type Array*)
* @result: type unsigned long
* @description: return capacity of the @array
*/
ICEAPI unsigned long ArrayCapacity(Array* array)
{
    return _ArrayCapacity(array);
}
/*
* @function: _ArrayIsEmpty
* @para: array(type Array*)
* @result: int
* @description: if the length of @array is zero return 0;
                    else return -1.
*/
ICEAPI int ArrayIsEmpty(Array* array)
{
    return _ArrayIsEmpty(array);
}
/*
* @function: _ArraySet
* @para: array(type Array*)
* @para: position(type unsigned long)
* @para: object(type void*)
* @result: type void*
* @description: Set @object to @position of @array, return the object of @array
*/
ICEAPI void* ArraySet(Array* array, unsigned long position,void* object)
{
    return _ArraySet(array,position,object);
}
/*
* @function: _ArraySetObject
* @para: array(type Array*)
* @para: position(type unsigned long)
* @para: object(type void*)
* @para: DestroyObject(type int (*)(void* object))
* @result: type int
* @description: use new @object to replace the oringinal object in @position of @array and use @DestroyObject to 
                    destroy and free it
*/
ICEAPI int ArraySetObject(Array* array,unsigned long position,void* object,int (*DestroyObject)(void* object))
{
    return _ArraySetObject(array,position,object,DestroyObject);
}
/*
* @function: _ArrayPrintObject
* @para: array(type Array*)
* @para: ObjectPrint(type void (*)(void* object))
* @result: type void
* @description: use function pointer @ObjectPrint to print element fo @array 
*/
ICEAPI void ArrayPrintObject(Array* array,void (*ObjectPrint)(void* object))
{
    _ArrayPrintObject(array,ObjectPrint);
}