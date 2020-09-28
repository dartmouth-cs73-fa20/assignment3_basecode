cmake_minimum_required(VERSION 3.1)
project(a3)

add_subdirectory(src/ext)

# include directories
include_directories(${PROJECT_SOURCE_DIR}/src
                    ${PROJECT_SOURCE_DIR}/src/ext
                    ${PROJECT_SOURCE_DIR}/src/ext/stb
)

set(ext_stb_srcs
    src/ext/stb/stb_image_write.h
    src/ext/stb/stb_image.h
)

add_definitions(-DDATA_DIR=R\"\(${PROJECT_SOURCE_DIR}/data\)\")

set(common_srcs
    src/array3D.h
    src/exceptions.h
    src/floatimage.cpp
    src/floatimage.h
    src/utils.h
)

# Compile common library
add_library(common_lib STATIC
    ${common_srcs}
    ${ext_stb_srcs}
)
SOURCE_GROUP("src\\ext\\stb" FILES ${ext_stb_srcs})

set(a3_srcs   src/a3_main.cpp src/align.cpp src/demosaic.cpp)               # a3
add_executable(a3 ${a3_srcs})                                               # a3
target_link_libraries(a3 common_lib)                                        # a3
SOURCE_GROUP("src" FILES ${a3_srcs})                                        # a3
                                                                            # a3

# Create the output data directory
add_custom_command(TARGET a3 POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory "${PROJECT_SOURCE_DIR}/data/output") # a3