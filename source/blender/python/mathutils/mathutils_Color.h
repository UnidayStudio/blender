/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * Contributor(s): Joseph Gilbert
 *
 * ***** END GPL LICENSE BLOCK *****
 *
 */

/** \file blender/python/mathutils/mathutils_Color.h
 *  \ingroup pymathutils
 */


#ifndef __MATHUTILS_COLOR_H__
#define __MATHUTILS_COLOR_H__

extern PyTypeObject color_Type;
#define ColorObject_Check(v) PyObject_TypeCheck((v), &color_Type)
#define ColorObject_CheckExact(v) (Py_TYPE(v) == &color_Type)

typedef struct {
	BASE_MATH_MEMBERS(col);

	int size; /* color size 3 or 4 (alpha) */
} ColorObject;

/* struct data contains a pointer to the actual data that the
 * object uses. It can use either PyMem allocated data (which will
 * be stored in py_data) or be a wrapper for data allocated through
 * blender (stored in blend_data). This is an either/or struct not both*/

/* prototypes */
PyObject *Color_CreatePyObject(
        const float *col, int size,
        PyTypeObject *base_type
        ) ATTR_WARN_UNUSED_RESULT;
PyObject *Color_CreatePyObject_wrap(
        float *col, int size,
        PyTypeObject *base_type
        ) ATTR_WARN_UNUSED_RESULT ATTR_NONNULL(1);
PyObject *Color_CreatePyObject_cb(
        PyObject *cb_user, int size,
        unsigned char cb_type, unsigned char cb_subtype
        ) ATTR_WARN_UNUSED_RESULT;

#endif /* __MATHUTILS_COLOR_H__ */
