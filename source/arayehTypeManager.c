/** source/arayehTypeManager.c
 *
 * This file is a part of:
 * Azadeh Afzar - Arayehsaz (AA-A).
 *
 * Copyright (C) 2020 Mohammad Mahdi Baghbani Pourvahid.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgement in the product documentation would be
 * appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 */

#include "../include/arayehTypeManager.h"

// Initialize arayeh pointer.

int _initTypeChar(arayeh *self, arayehType *array, size_t initialSize)
{
    array->pChar = NULL;
    return (initialSize > (size_t) SIZE_MAX / sizeof *(array->pChar))
               ? AA_ARAYEH_FAILURE
               : AA_ARAYEH_SUCCESS;
}

int _initTypeSInt(arayeh *self, arayehType *array, size_t initialSize)
{
    array->pShortInt = NULL;
    return (initialSize > (size_t) SIZE_MAX / sizeof *(array->pShortInt))
               ? AA_ARAYEH_FAILURE
               : AA_ARAYEH_SUCCESS;
}

int _initTypeInt(arayeh *self, arayehType *array, size_t initialSize)
{
    array->pInt = NULL;
    return (initialSize > (size_t) SIZE_MAX / sizeof *(array->pInt))
               ? AA_ARAYEH_FAILURE
               : AA_ARAYEH_SUCCESS;
}

int _initTypeLInt(arayeh *self, arayehType *array, size_t initialSize)
{
    array->pLongInt = NULL;
    return (initialSize > (size_t) SIZE_MAX / sizeof *(array->pLongInt))
               ? AA_ARAYEH_FAILURE
               : AA_ARAYEH_SUCCESS;
}

int _initTypeFloat(arayeh *self, arayehType *array, size_t initialSize)
{
    array->pFloat = NULL;
    return (initialSize > (size_t) SIZE_MAX / sizeof *(array->pFloat))
               ? AA_ARAYEH_FAILURE
               : AA_ARAYEH_SUCCESS;
}

int _initTypeDouble(arayeh *self, arayehType *array, size_t initialSize)
{
    array->pDouble = NULL;
    return (initialSize > (size_t) SIZE_MAX / sizeof *(array->pDouble))
               ? AA_ARAYEH_FAILURE
               : AA_ARAYEH_SUCCESS;
}

// Allocate memory for arayeh.

int _mallocTypeChar(arayeh *self, arayehType *array, size_t initialSize)
{
    array->pChar = (char *) malloc(sizeof *array->pChar * initialSize);
    return (array->pChar == NULL) ? AA_ARAYEH_FAILURE : AA_ARAYEH_SUCCESS;
}

int _mallocTypeSInt(arayeh *self, arayehType *array, size_t initialSize)
{
    array->pShortInt = (short int *) malloc(sizeof *array->pShortInt * initialSize);
    return (array->pShortInt == NULL) ? AA_ARAYEH_FAILURE : AA_ARAYEH_SUCCESS;
}

int _mallocTypeInt(arayeh *self, arayehType *array, size_t initialSize)
{
    array->pInt = (int *) malloc(sizeof *array->pInt * initialSize);
    return (array->pInt == NULL) ? AA_ARAYEH_FAILURE : AA_ARAYEH_SUCCESS;
}

int _mallocTypeLInt(arayeh *self, arayehType *array, size_t initialSize)
{
    array->pLongInt = (long int *) malloc(sizeof *array->pLongInt * initialSize);
    return (array->pLongInt == NULL) ? AA_ARAYEH_FAILURE : AA_ARAYEH_SUCCESS;
}

int _mallocTypeFloat(arayeh *self, arayehType *array, size_t initialSize)
{
    array->pFloat = (float *) malloc(sizeof *array->pFloat * initialSize);
    return (array->pFloat == NULL) ? AA_ARAYEH_FAILURE : AA_ARAYEH_SUCCESS;
}

int _mallocTypeDouble(arayeh *self, arayehType *array, size_t initialSize)
{
    array->pDouble = (double *) malloc(sizeof *array->pDouble * initialSize);
    return (array->pDouble == NULL) ? AA_ARAYEH_FAILURE : AA_ARAYEH_SUCCESS;
}

// Re-allocate memory for arayeh.

int _reallocTypeChar(arayeh *self, arayehType *array, size_t newSize)
{
    array->pChar = (char *) realloc(self->_internalProperties.array.pChar,
                                    sizeof *array->pChar * newSize);
    return (array->pChar == NULL) ? AA_ARAYEH_FAILURE : AA_ARAYEH_SUCCESS;
}

int _reallocTypeSInt(arayeh *self, arayehType *array, size_t newSize)
{
    array->pShortInt =
        (short int *) realloc(self->_internalProperties.array.pShortInt,
                              sizeof *array->pShortInt * newSize);
    return (array->pShortInt == NULL) ? AA_ARAYEH_FAILURE : AA_ARAYEH_SUCCESS;
}

int _reallocTypeInt(arayeh *self, arayehType *array, size_t newSize)
{
    array->pInt = (int *) realloc(self->_internalProperties.array.pInt,
                                  sizeof *array->pInt * newSize);
    return (array->pInt == NULL) ? AA_ARAYEH_FAILURE : AA_ARAYEH_SUCCESS;
}

int _reallocTypeLInt(arayeh *self, arayehType *array, size_t newSize)
{
    array->pLongInt = (long int *) realloc(self->_internalProperties.array.pLongInt,
                                           sizeof *array->pLongInt * newSize);
    return (array->pLongInt == NULL) ? AA_ARAYEH_FAILURE : AA_ARAYEH_SUCCESS;
}

int _reallocTypeFloat(arayeh *self, arayehType *array, size_t newSize)
{
    array->pFloat = (float *) realloc(self->_internalProperties.array.pFloat,
                                      sizeof *array->pFloat * newSize);
    return (array->pFloat == NULL) ? AA_ARAYEH_FAILURE : AA_ARAYEH_SUCCESS;
}

int _reallocTypeDouble(arayeh *self, arayehType *array, size_t newSize)
{
    array->pDouble = (double *) realloc(self->_internalProperties.array.pDouble,
                                        sizeof *array->pDouble * newSize);
    return (array->pDouble == NULL) ? AA_ARAYEH_FAILURE : AA_ARAYEH_SUCCESS;
}

// Free arayeh memory.

void _freeTypeChar(arayeh *self)
{
    free(self->_internalProperties.array.pChar);
    self->_internalProperties.array.pChar = NULL;
}

void _freeTypeSInt(arayeh *self)
{
    free(self->_internalProperties.array.pShortInt);
    self->_internalProperties.array.pShortInt = NULL;
}

void _freeTypeInt(arayeh *self)
{
    free(self->_internalProperties.array.pInt);
    self->_internalProperties.array.pInt = NULL;
}

void _freeTypeLInt(arayeh *self)
{
    free(self->_internalProperties.array.pLongInt);
    self->_internalProperties.array.pLongInt = NULL;
}

void _freeTypeFloat(arayeh *self)
{
    free(self->_internalProperties.array.pFloat);
    self->_internalProperties.array.pFloat = NULL;
}

void _freeTypeDouble(arayeh *self)
{
    free(self->_internalProperties.array.pDouble);
    self->_internalProperties.array.pDouble = NULL;
}

// Assign the initialized pointer of an array to the arayeh structs pointer.

void _setMemoryPointerTypeChar(arayeh *self, arayehType *array)
{
    self->_internalProperties.array.pChar = array->pChar;
}

void _setMemoryPointerTypeSInt(arayeh *self, arayehType *array)
{
    self->_internalProperties.array.pShortInt = array->pShortInt;
}

void _setMemoryPointerTypeInt(arayeh *self, arayehType *array)
{
    self->_internalProperties.array.pInt = array->pInt;
}

void _setMemoryPointerTypeLInt(arayeh *self, arayehType *array)
{
    self->_internalProperties.array.pLongInt = array->pLongInt;
}

void _setMemoryPointerTypeFloat(arayeh *self, arayehType *array)
{
    self->_internalProperties.array.pFloat = array->pFloat;
}

void _setMemoryPointerTypeDouble(arayeh *self, arayehType *array)
{
    self->_internalProperties.array.pDouble = array->pDouble;
}

// Add an element of a specific type to the arayeh.

void _addTypeChar(arayeh *self, size_t index, void *element)
{
    self->_internalProperties.array.pChar[index] = *((char *) element);
}

void _addTypeSInt(arayeh *self, size_t index, void *element)
{
    self->_internalProperties.array.pShortInt[index] = *((short int *) element);
}

void _addTypeInt(arayeh *self, size_t index, void *element)
{
    self->_internalProperties.array.pInt[index] = *((int *) element);
}

void _addTypeLInt(arayeh *self, size_t index, void *element)
{
    self->_internalProperties.array.pLongInt[index] = *((long int *) element);
}

void _addTypeFloat(arayeh *self, size_t index, void *element)
{
    self->_internalProperties.array.pFloat[index] = *((float *) element);
}

void _addTypeDouble(arayeh *self, size_t index, void *element)
{
    self->_internalProperties.array.pDouble[index] = *((double *) element);
}

// Merge a C standard array of a specific type into the arayeh.

void _mergeListTypeChar(arayeh *self, size_t startIndex, size_t listSize, void *list)
{
    char *temp = (char *) list;
    for (size_t i = 0; i < listSize; ++i) {
        (self->insert)(self, startIndex + i, temp + i);
    }
}

void _mergeListTypeSInt(arayeh *self, size_t startIndex, size_t listSize, void *list)
{
    short int *temp = (short int *) list;
    for (size_t i = 0; i < listSize; ++i) {
        (self->insert)(self, startIndex + i, temp + i);
    }
}

void _mergeListTypeInt(arayeh *self, size_t startIndex, size_t listSize, void *list)
{
    int *temp = (int *) list;
    for (size_t i = 0; i < listSize; ++i) {
        (self->insert)(self, startIndex + i, temp + i);
    }
}

void _mergeListTypeLInt(arayeh *self, size_t startIndex, size_t listSize, void *list)
{
    long int *temp = (long int *) list;
    for (size_t i = 0; i < listSize; ++i) {
        (self->insert)(self, startIndex + i, temp + i);
    }
}

void _mergeListTypeFloat(arayeh *self, size_t startIndex, size_t listSize,
                         void *list)
{
    float *temp = (float *) list;
    for (size_t i = 0; i < listSize; ++i) {
        (self->insert)(self, startIndex + i, temp + i);
    }
}

void _mergeListTypeDouble(arayeh *self, size_t startIndex, size_t listSize,
                          void *list)
{
    double *temp = (double *) list;
    for (size_t i = 0; i < listSize; ++i) {
        (self->insert)(self, startIndex + i, temp + i);
    }
}

// Get an element from arayeh.

void _getTypeChar(arayeh *self, size_t index, void *element)
{
    char *ptr = (char *) element;
    *ptr      = self->_internalProperties.array.pChar[index];
}

void _getTypeSInt(arayeh *self, size_t index, void *element)
{
    short int *ptr = (short int *) element;
    *ptr           = self->_internalProperties.array.pShortInt[index];
}

void _getTypeInt(arayeh *self, size_t index, void *element)
{
    int *ptr = (int *) element;
    *ptr     = self->_internalProperties.array.pInt[index];
}

void _getTypeLInt(arayeh *self, size_t index, void *element)
{
    long int *ptr = (long int *) element;
    *ptr          = self->_internalProperties.array.pLongInt[index];
}

void _getTypeFloat(arayeh *self, size_t index, void *element)
{
    float *ptr = (float *) element;
    *ptr       = self->_internalProperties.array.pFloat[index];
}

void _getTypeDouble(arayeh *self, size_t index, void *element)
{
    double *ptr = (double *) element;
    *ptr        = self->_internalProperties.array.pDouble[index];
}
