cmake_minimum_required(VERSION 3.15)
project(WebUICpp)

# Set C++ standard to C++17 (or later if desired)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories for your code and third-party libraries
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/third_party/boost
    ${CMAKE_SOURCE_DIR}/third_party/crow/include
)

# List your source files
set(SOURCE_FILES
    src/main.cpp
    src/page_handler.cpp
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

