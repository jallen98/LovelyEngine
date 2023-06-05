cmake_minimum_required(VERSION 3.22)

# Create project
project(LovelyEngineGraphics)

# Set output destinations
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add source files
file(GLOB_RECURSE lovelyEngineGraphicsSources src/*.cpp)

# Create executable
add_executable(LovelyEngineGraphics ${lovelyEngineGraphicsSources})
target_include_directories(LovelyEngineGraphics PRIVATE include)