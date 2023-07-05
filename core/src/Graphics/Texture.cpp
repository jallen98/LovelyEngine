#include "Graphics/Texture.h"

#include <stb_image.h>

lov::Graphics::Texture::Texture(const char* path) {
    // Generate the texture
    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);

    // Set texture wrapping and filtering options
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    stbi_set_flip_vertically_on_load(true);

    // Load the texture
    int width, height, numChannels;
    unsigned char* data = stbi_load(path, &width, &height, &numChannels, 0);
    GLenum format = numChannels < 4 ? GL_RGB : GL_RGBA;

    if (numChannels < 4) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    }
    else {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    }

    glGenerateMipmap(GL_TEXTURE_2D);

    // Free memory and unbind
    stbi_image_free(data);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void lov::Graphics::Texture::bind(lov_uint unit) const {
    // Bind this texture
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, m_id);
}

void lov::Graphics::Texture::unbind() const {
    // Unbind this texture
    glBindTexture(GL_TEXTURE_2D, 0);
}

lov::lov_uint lov::Graphics::Texture::getID() const {
    return m_id;
}
