cmake_minimum_required(VERSION 3.15)
project(Il2CppResolver VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_library(Il2CppResolver ${SOURCES})

target_include_directories(Il2CppResolver PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:include>
)

target_include_directories(Il2CppResolver PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Functions
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Unity
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Unity/API
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Unity/Structures
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Utils
)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/Il2CppResolver.hpp DESTINATION include)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/Functions DESTINATION lib/Il2CppResolver/private)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/Unity DESTINATION lib/Il2CppResolver/private)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/Utils DESTINATION lib/Il2CppResolver/private)

export(TARGETS Il2CppResolver FILE Il2CppResolverConfig.cmake)
