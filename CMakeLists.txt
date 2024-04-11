cmake_minimum_required(VERSION 3.20)

project(cpp_project)

add_executable(test
    main.cpp
    image_outputer.hpp
    image_outputer.cpp)

set_target_properties(test PROPERTIES CXX_STANDARD 23)
