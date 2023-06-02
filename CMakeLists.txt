cmake_minimum_required(VERSION 3.0)
project(LoggerExample)

# Set compile_commands to true 
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Set paths
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(EXAMPLES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/examples)

# Add include directory
include_directories(${INCLUDE_DIR})

# Add source files
set(SOURCES
    ${SRC_DIR}/logger.cpp
    ${EXAMPLES_DIR}/main.cpp
)

# Create executable
add_executable(example ${SOURCES})

# Add compilation flags
if(MSVC)
    target_compile_options(example PRIVATE /W4)
else()
    target_compile_options(example PRIVATE -Wall -Wextra -Werror)
endif()