cmake_minimum_required(VERSION 3.15)
project(Il2CppResolver VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES *.hpp)

add_library(Il2CppResolver INTERFACE ${SOURCES})
set_target_properties(Il2CppResolver PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(Il2CppResolver INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

install(TARGETS Il2CppResolver EXPORT Il2CppResolverConfig)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/API DESTINATION include)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Unity DESTINATION include)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Structures DESTINATION include)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/Utils DESTINATION include)

export(TARGETS Il2CppResolver FILE Il2CppResolverConfig.cmake)
