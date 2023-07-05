#pragma once

#include "System/Types.h"

/// @file Material.h
/// @brief Defines materials for objects to be rendered

namespace lov {
    namespace Graphics {
        struct Material {
            lov_uint diffuseMapID; ///< ID of a diffuse map texture for this material
            lov_uint specularMapID; ///< ID of a specular map texture for this material
            float shininess; ///< Shininess of this material
        };
    }
}
