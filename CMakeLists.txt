cmake_minimum_required(VERSION 3.15)


# give a name to the project
project(conic LANGUAGES C CXX)

# include Eigen
include(FindEigen3.cmake)
find_package(Eigen3 ${Eigen3_FIND_VERSION} NO_MODULE QUIET)
if(${EIGEN3_FOUND})
    message(STATUS "lib EIGEN3 found")
    message(STATUS "  version " ${EIGEN3_VERSION_STRING})
    message(STATUS "  include " ${EIGEN3_INCLUDE_DIR})
else()
    #message(FATAL_ERROR "lib EIGEN3 not found")
    set(EIGEN3_INCLUDE_DIR "C:/eigen/eigen-3.4.0/eigen")    # windows users: put the path to eigen lib
    message(STATUS "  include " ${EIGEN3_INCLUDE_DIR})
endif()


# Définissez les fichiers source
file(GLOB SOURCE_FILES "src/*")

# files to compile
add_executable (conic ${SOURCE_FILES})


# compilation options
target_compile_features(conic PRIVATE cxx_std_11) # use at least c++ 11
if (MSVC)
    target_compile_options(conic PRIVATE /W3)
else()
    target_compile_options(conic PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()

# lib include path
target_include_directories(conic PRIVATE "${EIGEN3_INCLUDE_DIR}")


