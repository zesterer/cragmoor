#######################
#### CONFIGURATION ####
#######################

#settings.h header file
#configure_file(
#"settings.h.in"
#"settings.h"
#)

########################
#### Subdirectories ####
########################

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/generic")

#################
#### SOURCES ####
#################

#Add the appropriate source directories
set(APPLICATION_SOURCE_DIRS
${APPLICATION_SOURCE_DIRS}
"${CMAKE_CURRENT_SOURCE_DIR}"
PARENT_SCOPE
)

#Add the appropriate source files
set(APPLICATION_SOURCE_FILES
${APPLICATION_SOURCE_FILES}
"${CMAKE_CURRENT_SOURCE_DIR}/colour.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/renderer.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/graphicalwindow.cpp"
PARENT_SCOPE
)
