cmake_minimum_required(VERSION 3.0)
project(gk)

set(CMAKE_CXX_STANDARD 17)

include_directories(catch2)

IF (GENERATE_CODE_COVERAGE)
    message(STATUS "Compiling with code coverage")
    SET(GCC_COVERAGE_COMPILE_FLAGS "-g -O0 -coverage -fprofile-arcs -ftest-coverage")
    SET(GCC_COVERAGE_LINK_FLAGS    "-coverage -lgcov")
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
    SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
ENDIF()

add_executable(main
        ./src/main.cpp
        ./src/Campus.cpp
        ./src/CredentialFunctions.cpp
        ./src/Error_Checking.cpp
        ./src/Fountain.cpp
        ./src/Review.cpp
        ./src/User.cpp)
add_executable(test
        ./src/test_driver.cpp
        ./src/Campus.cpp
        ./src/CredentialFunctions.cpp
        ./src/Error_Checking.cpp
        ./src/Fountain.cpp
        ./src/Review.cpp
        ./src/User.cpp)

IF (GENERATE_CODE_COVERAGE)
    target_link_libraries(test gcov)
ENDIF()
