#pragma once

#include <glad/glad.h>

/// @file Types.h
/// @brief Defines common types used by OpenGL

namespace lov {
    /// @brief Types definitions used for functions that require a type specification, like VertexArrays
    enum LovelyType {
        LOV_BYTE            = GL_BYTE,
        LOV_UNSIGNED_BYTE   = GL_UNSIGNED_BYTE,
        LOV_SHORT           = GL_SHORT,
        LOV_UNSIGNED_SHORT  = GL_UNSIGNED_SHORT,
        LOV_INT             = GL_INT,
        LOV_UNSIGNED_INT    = GL_UNSIGNED_INT,
        LOV_HALF_FLOAT      = GL_HALF_FLOAT,
        LOV_FLOAT           = GL_FLOAT,
        LOV_DOUBLE          = GL_DOUBLE
    };

    typedef GLbyte      lov_byte;   ///< Type definition for OpenGL byte
    typedef GLubyte     lov_ubyte;  ///< Type definition for OpenGL unsigned byte
    typedef GLshort     lov_short;  ///< Type definition for OpenGL short
    typedef GLushort    lov_ushort; ///< Type definition for OpenGL unsigned short
    typedef GLint       lov_int;    ///< Type definition for OpenGL int
    typedef GLuint      lov_uint;   ///< Type definition for OpenGL unsigned int
    typedef GLhalf      lov_half;   ///< Type definition for OpenGL half float
    typedef GLfloat     lov_float;  ///< Type definition for OpenGL float
    typedef GLdouble    lov_double; ///< Type definition for OpenGL double
    typedef GLsizei     lov_size;   ///< Type defintion for OpenGL sizes
}
