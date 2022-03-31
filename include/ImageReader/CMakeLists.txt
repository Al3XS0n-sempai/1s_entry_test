add_library(
        image_reader
        image_reader.hpp
        array_2d.hpp
        image_reader.cpp
        array_2d.cpp
)

target_include_directories(image_reader PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")