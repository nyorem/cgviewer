cmake_minimum_required(VERSION 2.8.11)

project(cgviewer)

set (EXECUTABLE_NAME "main")
set (SOURCE_DIR "src")

# Compilation flags
list(APPEND CMAKE_CXX_FLAGS "-Wall")

# Qt5
set (CMAKE_PREFIX_PATH "/usr/local/Cellar/qt5/5.4.2/")
# For automoc to work headers and source files must be in the same directory
set (CMAKE_AUTOMOC ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)

# Qt5 Components
find_package(Qt5Widgets REQUIRED)

# CGAL
find_package(CGAL REQUIRED)
include (${CGAL_USE_FILE})

# run
add_custom_target(run
    COMMAND ${EXECUTABLE_NAME}
    DEPENDS ${EXECUTABLE_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
)

# Source files
file(
  GLOB_RECURSE
  ${EXECUTABLE_NAME}_SOURCES
  ${SOURCE_DIR}/**.cpp
  )

# Executable
add_executable(${EXECUTABLE_NAME} ${${EXECUTABLE_NAME}_SOURCES})

# Libraries
target_link_libraries(${EXECUTABLE_NAME}
    Qt5::Widgets
)

