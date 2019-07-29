cmake_minimum_required(VERSION 3.14)
set(PROJECT_NAME "SmartReco")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/includes)

if (APPLE)
    link_directories("/usr/local/opt/llvm/lib")
endif ()

add_executable(${PROJECT_NAME} example/main.cpp includes/graphics/Image.inl includes/graphics/Image.hpp includes/maths/Matrix.inl includes/maths/Matrix.hpp)

target_link_libraries(${PROJECT_NAME} $<$<PLATFORM_ID:Darwin>:c++fs>)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")