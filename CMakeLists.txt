cmake_minimum_required(VERSION 3.0)
project(gk)

set(CMAKE_CXX_STANDARD 17)

include_directories(catch2)

file(GLOB_RECURSE main ./src/main.cpp)
file(GLOB_RECURSE tests ./src/test_driver.cpp)

IF (GENERATE_CODE_COVERAGE)
    message(STATUS "Compiling with code coverage")
    SET(GCC_COVERAGE_COMPILE_FLAGS "-g -O0 -coverage -fprofile-arcs -ftest-coverage")
    SET(GCC_COVERAGE_LINK_FLAGS    "-coverage -lgcov")
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
    SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
ENDIF()

add_executable(gk
        ${main})
add_executable(tests
        ${tests})

IF (GENERATE_CODE_COVERAGE)
    target_link_libraries(tests gcov)
ENDIF()
