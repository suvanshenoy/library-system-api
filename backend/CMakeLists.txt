cmake_minimum_required(VERSION 3.29)
project(LibrarySystemBackend)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE CXX_SRCS main/*.cpp)

file(GLOB_RECURSE CXX_HEADERS main/*.hpp)

add_executable(lsa
    ${CXX_SRCS}
    ${CXX_HEADERS}
)
