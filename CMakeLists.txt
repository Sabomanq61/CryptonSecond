cmake_minimum_required(VERSION 3.19)
project(Converter_Image)

set(CMAKE_CXX_STANDARD 20)
cmake_minimum_required(VERSION 3.19)

find_package(Boost 1.74.0 COMPONENTS program_options filesystem REQUIRED)

include_directories(${Boost_INCLUDE_DIR} ${Boost_Library_Dirs})

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(${PROJECT_NAME} main.cpp Person.h)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio Boost::program_options Boost::filesystem)