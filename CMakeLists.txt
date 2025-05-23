cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME steering_wheel_test)

# Include toolchain file
include("cmake/gcc-arm-none-eabi.cmake")

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
    ${CMAKE_SOURCE_DIR}/steering_wheel/Inc
    ${CMAKE_SOURCE_DIR}/steering_wheel
    ${CMAKE_SOURCE_DIR}/steering_wheel/lvgl
    ${CMAKE_SOURCE_DIR}/steering_wheel/lvgl/src
    ${CMAKE_SOURCE_DIR}/can_ids
    ${CMAKE_SOURCE_DIR}/steering_wheel/ui
)

file(GLOB STEERING_WHEEL_SOURCES
    ${CMAKE_SOURCE_DIR}/steering_wheel/Src/*.c
    ${CMAKE_SOURCE_DIR}/steering_wheel/ui/*.c
    # ${CMAKE_SOURCE_DIR}/steering_wheel/lvgl/*.c
    # ${CMAKE_SOURCE_DIR}/steering_wheel/lvgl/src/*.c
)

file(GLOB_RECURSE LVGL_SOURCES
     ${CMAKE_SOURCE_DIR}/steering_wheel/lvgl/src/*.c
    
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
    ${STEERING_WHEEL_SOURCES}
    ${LVGL_SOURCES}
)


# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx

    # Add user defined libraries
)
