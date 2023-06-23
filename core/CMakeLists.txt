cmake_minimum_required(VERSION 3.22)

# Create project
project(LovelyEngineGraphics)

# Set output destinations
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add source files
file(GLOB_RECURSE lovelyEngineGraphicsSources src/*.cpp external/glad/src/glad.c)

# Compile submodules
add_subdirectory(external/glfw)

# Create executable
add_executable(LovelyEngineGraphics ${lovelyEngineGraphicsSources})

# Add include directory
target_include_directories(LovelyEngineGraphics PRIVATE include)

# Add external includes
target_include_directories(LovelyEngineGraphics PRIVATE external/glfw/include external/glad/include)

# Link external libraries
target_link_libraries(LovelyEngineGraphics glfw ${GLFW_LIBRARIES})