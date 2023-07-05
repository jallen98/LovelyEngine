#include "System/Exceptions.h"

lov::Exceptions::Exception::Exception(const char* message): message(message) {}

lov::Exceptions::Exception::Exception(const std::string& message): message(message) {}

const char* lov::Exceptions::Exception::what() const noexcept {
    return message.c_str();
}

lov::Exceptions::ShaderException::ShaderException(const char* message): Exception(message) {}
lov::Exceptions::ShaderException::ShaderException(const std::string& message): Exception(message) {}
