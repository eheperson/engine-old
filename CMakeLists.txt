# Change version of the cmake accorting of your   <REQUIRED>
cmake_minimum_required(VERSION 3.21.3 FATAL_ERROR)

# SOME SETTINGS
set(CMAKE_BUILD_TYPE Debug)
option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

# Set some required variables 
# set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
# set(EXT_DIR ${PROJECT_SOURCE_DIR}/ext)

# Do not forget update the compiler path <REQUIRED>
# set(CMAKE_C_COMPILER "/usr/bin/gcc")
# set(CMAKE_CXX_COMPILER "/usr/bin/g++")
# add_definitions(-std=c++11)

# Specify C++ standards
# C++ standards declerations must be above the call to add_executable
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the project name with version
# ${PROJECT_NAME}
project(engine VERSION 0.0.0 LANGUAGES C CXX)
#-----------------------------------------------------------------------------------------
#-------------- DOWNLOAD ALL THE SUBMODULES
# first open terminal and type : 
#   git submodule add https://github.com/libsdl-org/SDL.git ext/sdl2
#   git submodule add -f https://github.com/libsdl-org/SDL.git ext/sdl2
#   git submodule add https://github.com/libsdl-org/SDL_image.git ext/sdl_image
#   git submodule add -f https://github.com/libsdl-org/SDL_image.git ext/sdl_image
# second add changes to staged area (we have to stage it)
#  
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()
#
#--------------------------------------------------------------------
#-------------- CHECK ALL THE SUBMODULES
# Check SDL2 Module
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/ext/sdl2/CMakeLists.txt")
    message(FATAL_ERROR "The sdl2 submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()
#
# Check SDL_Image Module
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/ext/sdl2_image/CMakeLists.txt")
    message(FATAL_ERROR "The sdl2_image submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()
#
#-------------- ADD SUBMODULES DIRECTORIES
add_subdirectory(ext/sdl2)
add_subdirectory(ext/sdl2_image)
#--------------------------------------------------------------------
#-------------- Shooter Game -------------------------------------------------------------
# add library source subdirectory
add_subdirectory(libs)
# so that libraries will get build
#
# add the executable
add_executable(${PROJECT_NAME} main.cpp)
#
target_link_libraries(${PROJECT_NAME} PUBLIC architect)
# # target_link_libraries(${PROJECT_NAME} PUBLIC cognition)
target_link_libraries(${PROJECT_NAME} PUBLIC inputHandler)
target_link_libraries(${PROJECT_NAME} PUBLIC renderer)


add_custom_command(TARGET ${PROJECT_NAME}  PRE_BUILD         
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${PROJECT_SOURCE_DIR}/gfx ${CMAKE_CURRENT_BINARY_DIR}/gfx)
#
#-----------------------------------------------------------------------------------------
#-------------- Extra Settings -------------------------------------------------------------             
# Configure the header file to pass the version number to the source code
configure_file(Config.h.in Config.h)
# since the configured file will be written into the binary tree
# we must add that directory to the list of paths to search for include files
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")


