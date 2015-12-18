################
#### INITIAL####
################

#Make sure we have a minimum version
cmake_minimum_required(VERSION 2.6)

###############
#### SETUP ####
###############

#Set globally required variables
set(APPLICATION_NAME cragmoor)
set(APPLICATION_LINK_LIBRARIES)

#Set the project name and primary language
project(${APPLICATION_NAME} CXX)

#Set the version numbers
set(APPLICATION_VERSION_MAJOR 0)
set(APPLICATION_VERSION_MINOR 0)
set(APPLICATION_VERSION_BUILD 0)
set(APPLICATION_DEBUG_ENABLED true)

#Set the source files and directories we will use
set(APPLICATION_SOURCE_FILES)
set(APPLICATION_SOURCE_DIRS)

#Set CMake modules path
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules" ${CMAKE_MODULE_PATH})

#Tell the compiler to include -std=c++11
add_definitions("-std=c++11" "-Wall" "-Wextra" "-pedantic" "-g3" "-O3")

#######################
#### ADD LIBRARIES ####
#######################

find_package(PkgConfig REQUIRED)

#######
# SDL #
#######

#Find SDL
if (WIN32)
	set(APPLICATION_SOURCE_DIRS ${APPLICATION_SOURCE_DIRS} ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
	set(APPLICATION_LINK_LIBRARIES ${APPLICATION_LINK_LIBRARIES} SDL2 SDL2_image)
else ()
	PKG_SEARCH_MODULE(SDL2 REQUIRED)
	PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED)
endif ()

if (${SDL2_FOUND})
	message("Found SDL2")
	set(APPLICATION_SOURCE_DIRS ${APPLICATION_SOURCE_DIRS} ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
	set(APPLICATION_LINK_LIBRARIES ${APPLICATION_LINK_LIBRARIES} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
else ()
	message("SDL could not be found, and is required to build this library")
endif ()

###########
# NCURSES #
###########

#set(APPLICATION_LINK_LIBRARIES ${APPLICATION_LINK_LIBRARIES} ncursesw)

#Find NCURSES
#PKG_SEARCH_MODULE(NCURSES REQUIRED)

#if (${NCURSES_FOUND})
#	message("Found NCURSES")
#	set(APPLICATION_SOURCE_DIRS ${APPLICATION_SOURCE_DIRS} ${NCURSES_INCLUDE_DIRS})
#	set(APPLICATION_LINK_LIBRARIES ${APPLICATION_LINK_LIBRARIES} ${NCURSES_LIBRARIES})
#else ()
#	message("NCURSES could not be found, and is required to build this library")
#endif ()

#######
# GLM #
#######

#Find GLM
#PKG_SEARCH_MODULE(GLM REQUIRED)

#if (${GLM_FOUND})
#	message("Found GLM")
#	set(APPLICATION_SOURCE_DIRS ${APPLICATION_SOURCE_DIRS} ${GLM_INCLUDE_DIR})
#else ()
#	message("GLM could not be found, and is required to build this library")
#endif ()

##################
#### BUILDING ####
##################

#Include the src directory (all the project code)
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src")

#Add all directories that need to be added
include_directories(${APPLICATION_SOURCE_DIRS})

#Take the code and turn it into the executable
add_executable(${APPLICATION_NAME} ${APPLICATION_SOURCE_FILES})

#Link the final executable to the needed libraries
if (WIN32)
	target_link_libraries(${APPLICATION_NAME} mingw32)
endif ()

target_link_libraries(${APPLICATION_NAME} ${APPLICATION_LINK_LIBRARIES})

if (WIN32)
	target_link_libraries(${APPLICATION_NAME} SDLmain SDL)
endif ()
