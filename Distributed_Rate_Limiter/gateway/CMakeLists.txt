cmake_minimum_required(VERSION 3.15)
project(DistributedGateway LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# fetch cpp-httplib library 
include(FetchContent)
FetchContent_Declare(
    httplib
    GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git 
    GIT_TAG        v0.16.0
)
FetchContent_MakeAvailable(httplib)

add_executable(gateway_bin src/main.cpp)
target_link_libraries(gateway_bin PRIVATE httplib::httplib)