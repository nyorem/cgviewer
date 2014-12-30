cmake_minimum_required(VERSION 2.8)

project(simple)

set (EXECUTABLE_NAME "cgviewer")
set (INCLUDE_DIR "inc")
set (SOURCE_DIR "src")

# Include directories
INCLUDE_DIRECTORIES (${INCLUDE_DIR})

# Sources
FILE(
  GLOB
  ${EXECUTABLE_NAME}_SOURCES
  ${SOURCE_DIR}/**.cpp
  )

# Headers
FILE(
  GLOB
  ${EXECUTABLE_NAME}_HEADERS
  ${SOURCE_DIR}/**.hpp
  )

# Qt5
set (CMAKE_PREFIX_PATH "/usr/local/Cellar/qt5/5.4.0/")
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Qt5 components
find_package(Qt5Widgets)

# CGAL
find_package(CGAL REQUIRED)
include( ${CGAL_USE_FILE} )

# moc
qt5_wrap_cpp(moc_sources ${INCLUDE_DIR}/MainWindow.hpp)
list(APPEND ${${EXECUTABLE_NAME}_SOURCES} ${moc_sources})

# Executable
ADD_EXECUTABLE(${EXECUTABLE_NAME}
  ${${EXECUTABLE_NAME}_SOURCES}
  ${${EXECUTABLE_NAME}_HEADERS}
  ${moc_sources}
  )

# Link
target_link_libraries(${EXECUTABLE_NAME} Qt5::Widgets)

