/** source/algorithms.c
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

#include "../include/algorithms.h"

size_t growthFactorPython(arayeh *arayeh)
{
    /*
     * This function will calculate the extension size of memory.
     *
     * This is the default function to calculate memory growth size,
     * users can use their appropriate functions and ignore this.
     *
     * ARGUMENTS:
     * self             pointer to the arayeh object.
     *
     * RETURN:
     * extension_size   the size of extra memory space to be
     *                  added to the current memory space.
     *
     */

    // shorten names for god's sake.
    struct privateProperties *privateProperties = &arayeh->_privateProperties;

    // derived from python source code.
    // calculate the extension size of memory.
    // This over-allocates proportional to the ARAYEH size,
    // making room for additional growth. The over-allocation is mild,
    // but is enough to give linear-time amortized behavior over a long
    // sequence of adding elements to arayeh in the presence of
    // a poorly-performing system realloc().
    // The growth pattern is:  0, 4, 8, 16, 25, 35, 46, 58, 72, 88, ...
    size_t current_size   = privateProperties->size;
    size_t extension_size = (current_size >> 3) + (current_size < 9 ? 3 : 6);
    return extension_size;
}

void updateNextIndex(arayeh *self)
{
    /*
     * This function purpose is to update
     * array.next variable to point to next empty [available]
     * slot in the arayeh.
     *
     * ARGUMENTS:
     * self         pointer to the arayeh object.
     *
     * RETURN:
     * no return, it's void dude.
     *
     */

    // shorten names for god's sake.
    struct privateProperties *privateProperties = &self->_privateProperties;

    while (privateProperties->next < privateProperties->size &&
           privateProperties->map[privateProperties->next] == AA_ARAYEH_ON) {
        privateProperties->next++;
    }

    // update public next property.
    self->next = privateProperties->next;
}