cmake_minimum_required(VERSION 3.10)

set(CFLAGS
    -Wall -Wextra -Wfloat-equal
    -Wstrict-overflow=5 -Wunreachable-code
    -Wundef -Wcast-qual -Wconversion 
    -Wswitch-default -Wmissing-include-dirs
    -Wshadow -Wstrict-aliasing -Winit-self
    -Wcast-align -Wpointer-arith
    -Wno-unused-parameter -Wuninitialized
    -D_GNU_SOURCE
)

list(APPEND
    SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/print.c
    ${CMAKE_CURRENT_SOURCE_DIR}/print.h
    ${CMAKE_CURRENT_SOURCE_DIR}/shim.c
    ${CMAKE_CURRENT_SOURCE_DIR}/wrap.c
    ${CMAKE_CURRENT_SOURCE_DIR}/wrap.h
)

project(shim)
add_library(shim_objects OBJECT ${SOURCES})
set_property(TARGET shim_objects PROPERTY POSITION_INDEPENDENT_CODE ON)
set_property(TARGET shim_objects PROPERTY C_VISIBILITY_PRESET hidden)
set_property(TARGET shim_objects PROPERTY VISIBILITY_INLINES_HIDDEN ON)
target_compile_options(shim_objects PUBLIC ${CFLAGS})

add_library(shim SHARED $<TARGET_OBJECTS:shim_objects>)
target_link_libraries(shim LINK_PUBLIC ${CMAKE_DL_LIBS})

add_library(shim_static STATIC $<TARGET_OBJECTS:shim_objects>)


