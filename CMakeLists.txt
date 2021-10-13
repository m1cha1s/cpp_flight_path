cmake_minimum_required(VERSION 3.0.0)
project(cpp_flight_path VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(cpp_flight_path src/main.cpp src/flight_path.cpp)

find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)

target_include_directories(${PROJECT_NAME} PRIVATE inc)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
