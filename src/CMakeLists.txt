cmake_minimum_required(VERSION 3.10)

project(Curves)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CURVES_LIB_SOURCES
    source/circle.cc
    source/ellipse.cc
    source/helix.cc
)

add_library(curves_lib STATIC ${CURVES_LIB_SOURCES})

target_include_directories(curves_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(curves main.cc)

target_link_libraries(curves PRIVATE curves_lib)