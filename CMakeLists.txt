cmake_minimum_required(VERSION 3.15)
project(Il2CppResolver VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(Il2CppResolver INTERFACE)

target_include_directories(Il2CppResolver INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

target_include_directories(Il2CppResolver INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/API>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Unity>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Structures>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Utils>
)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/IL2CPP_Resolver.hpp DESTINATION include)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/API DESTINATION lib/Il2CppResolver/private)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Unity DESTINATION lib/Il2CppResolver/private)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Structures DESTINATION lib/Il2CppResolver/private)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Utils DESTINATION lib/Il2CppResolver/private)

export(TARGETS Il2CppResolver FILE Il2CppResolverConfig.cmake)