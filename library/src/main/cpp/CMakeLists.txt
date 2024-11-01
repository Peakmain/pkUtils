
cmake_minimum_required(VERSION 3.4.1)

project("pkUtils")
include_directories(./include)


set(source_dir ./src)
set(source_dir ./src/utils)
aux_source_directory(${source_dir} src_list)
#aux_source_directory(${source_dir}/crash src_list)
#aux_source_directory(${source_dir}/mmkv src_list)
add_library( # Sets the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED


        # Provides a relative path to your source file(s).
        native-lib.cpp
        ${src_list})

include_directories(./include/utils)
set(utils_dir ./src/utils)
aux_source_directory(${utils_dir} utils_list)

add_library( # Sets the name of the library.
        pkUtils

        # Sets the library as a shared library.
        SHARED

        utils/StringUtils.cpp
        utils/Base64Encoder.cpp
        utils/Base64Decoder.cpp

        # Provides a relative path to your source file(s).
        utils.cpp
        ${utils_list})

find_library(
        log-lib

        log)
find_library(jnigraphics-lib
        jnigraphics)

target_link_libraries( # Specifies the target library.
        native-lib
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib}
        ${jnigraphics-lib})

target_link_libraries(pkUtils ${log-lib} ${jnigraphics-lib})