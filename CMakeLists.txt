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

FetchContent_Declare(
  digestpp
  GIT_REPOSITORY https://github.com/kerukuro/digestpp.git
  GIT_TAGS master
)
FetchContent_MakeAvailable(digestpp)

FetchContent_Declare(
  bitsery
  GIT_REPOSITORY https://github.com/fraillt/bitsery.git
  GIT_TAGS v5.2.4
)
FetchContent_MakeAvailable(bitsery)

FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAGS v3.12.0
)
FetchContent_MakeAvailable(json)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${tabulate_SOURCE_DIR}/include)
include_directories(${digestpp_SOURCE_DIR}/algorithm)
include_directories(${bitsery_SOURCE_DIR}/include)
include_directories(${json_SOURCE_DIR}/include)

add_executable(DormMS src/main.cpp src/auth/login.cpp)
set_target_properties(DormMS PROPERTIES OUTPUT_NAME "${CMAKE_SOURCE_DIR}/build/DormMS")