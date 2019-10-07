cmake_minimum_required(VERSION 2.8.12)
project(DoodleJump)

if(WIN32)
    set(PROG_EXE_NAME ${PROJECT_NAME})
    set(PROG_LIB_NAME lib${PROJECT_NAME})
else(WIN32)
    set(PROG_EXE_NAME ${PROJECT_NAME}_exe)
    set(PROG_LIB_NAME ${PROJECT_NAME})
endif(WIN32)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

set(CMAKE_VERBOSE_MAKEFILE TRUE)
file(RELATIVE_PATH RESOURCE_PATH "${CMAKE_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/resource")
set(BUILD_DIR ${CMAKE_SOURCE_DIR}/build)
set(BIN_DIR ${CMAKE_SOURCE_DIR}/bin)
set(LIB_DIR ${CMAKE_SOURCE_DIR}/lib)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIB_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

set(MAIN_CPP_FILE ${SRC_DIR}/main.cpp)

aux_source_directory(${SRC_DIR} SRC_FILES)

list(REMOVE_ITEM SRC_FILES ${MAIN_CPP_FILE})

configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${INCLUDE_DIR}/config.h"
  )

include_directories(${PROJECT_BINARY_DIR} ${INCLUDE_DIR})

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB HEADER_FILES "${INCLUDE_DIR}/*.h")
add_library(${PROG_LIB_NAME} STATIC ${SRC_FILES} ${HEADER_FILES})

link_directories(${LIB_DIR})

add_executable(${PROG_EXE_NAME} ${MAIN_CPP_FILE})
target_link_libraries(${PROG_EXE_NAME} ${PROG_LIB_NAME} ${CONAN_LIBS})