cmake_minimum_required(VERSION 3.22)

# Create project
project(LovelyEngine)

# Options
option(BUILD_WITH_TESTS "Build LovelyEngine Google tests" OFF)

# Set output destinations
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add source files
file(GLOB_RECURSE lovelyEngineSources main.cpp core/*.cpp external/glad/src/glad.c external/stb_image/src/stb_image.cpp)

# Compile submodules
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Disable GLFW examples")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Disable GLFW tests")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Disable GLFW docs")
add_subdirectory(external/glfw)

# Create executable
add_executable(LovelyEngine ${lovelyEngineSources})

# Add include directories
target_include_directories(LovelyEngine PRIVATE core/include)

# Add external includes
target_include_directories(LovelyEngine PRIVATE external/glfw/include external/glad/include external/stb_image/include)

# Link external libraries
target_link_libraries(LovelyEngine glfw ${GLFW_LIBRARIES})

# Build test executable
if (BUILD_WITH_TESTS)
    # Build list of sources
    file(GLOB_RECURSE lovelyEngineTestSources test/*.cpp core/*.cpp external/glad/src/glad.c external/stb_image/src/stb_image.cpp)

    # Create executable
    add_executable(LovelyEngineTest ${lovelyEngineTestSources})

    # Compile gtest
    add_subdirectory(external/googletest)

    # Add include directories
    target_include_directories(LovelyEngineTest PRIVATE core/include)

    # Add external includes
    target_include_directories(LovelyEngineTest PRIVATE external/glfw/include external/glad/include external/stb_image/include)

    # Link external libraries
    target_link_libraries(LovelyEngineTest glfw ${GLFW_LIBRARIES})
    target_link_libraries(LovelyEngineTest GTest::gtest_main)
endif()
