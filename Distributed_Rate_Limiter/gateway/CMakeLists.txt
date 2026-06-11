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

# fetch redis plus plus client 
FetchContent_Declare(
    redispp
    GIT_REPOSITORY https://github.com/sewenew/redis-plus-plus.git
    GIT_TAG        1.3.12
)
set(REDIS_PLUS_PLUS_BUILD_STATIC ON CACHE INTERNAL "")
set(REDIS_PLUS_PLUS_BUILD_TEST OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(redispp)

# fetch json parser library
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG        v3.11.3
)
FetchContent_MakeAvailable(nlohmann_json)

add_executable(gateway_bin src/main.cpp)

find_library(HIREDIS_LIB hiredis REQUIRED)
find_library(ZOOKEEPER_LIB zookeeper_mt REQUIRED)

# Link both library to executable
target_link_libraries(gateway_bin PRIVATE 
    httplib::httplib
    redis++_static     # Changed from sw::redis-plus-plus to redis++_static
    nlohmann_json::nlohmann_json
    ${HIREDIS_LIB}     # Added core redis library to fix linker dependencies
    ${ZOOKEEPER_LIB}
)