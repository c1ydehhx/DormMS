cmake_minimum_required(VERSION 3.26)
project(DormMS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-O3 -g")
set(LIBTINS_ENABLE_CXX11 1)

include(FetchContent)

FetchContent_Declare(
  tabulate
  GIT_REPOSITORY https://github.com/p-ranav/tabulate.git
  GIT_TAGS v1.5
)
FetchContent_MakeAvailable(tabulate)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${tabulate_SOURCE_DIR}/include)

add_executable(DormMS src/main.cpp)
set_target_properties(DormMS PROPERTIES OUTPUT_NAME "${CMAKE_SOURCE_DIR}/build/DormMS")