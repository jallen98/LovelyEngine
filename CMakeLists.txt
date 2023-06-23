cmake_minimum_required(VERSION 3.22)

# Create project
project(LovelyEngine)

# Set output destinations
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add source files
file(GLOB_RECURSE lovelyEngineSources core/*.cpp external/glad/src/glad.c)

# Compile submodules
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Disable GLFW examples")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Disable GLFW tests")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Disable GLFW docs")
add_subdirectory(external/glfw)

# Create executable
add_executable(LovelyEngine ${lovelyEngineSources})

# Add include directories
file(GLOB lovelyEngineHeaders LIST_DIRECTORIES true core/*/include)
target_include_directories(LovelyEngine PRIVATE lovelyEngineHeaders)

# Add external includes
target_include_directories(LovelyEngine PRIVATE external/glfw/include external/glad/include)

# Link external libraries
target_link_libraries(LovelyEngine glfw ${GLFW_LIBRARIES})
