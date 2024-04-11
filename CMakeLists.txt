cmake_minimum_required(VERSION 3.20)

project(image_outputer)

add_library(image_outputer
    image_outputer.hpp
    image_outputer.cpp)
set_target_properties(image_outputer PROPERTIES CXX_STANDARD 23)
target_include_directories(image_outputer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(image_outputer_test
    main.cpp)

set_target_properties(image_outputer_test PROPERTIES CXX_STANDARD 23)
target_link_libraries(image_outputer_test PUBLIC image_outputer)
