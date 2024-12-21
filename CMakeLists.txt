cmake_minimum_required(VERSION 3.24.0)

project(c_cxx_unit_testing)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()

enable_testing()

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBGMOCK REQUIRED gmock)

add_subdirectory(cxx)
