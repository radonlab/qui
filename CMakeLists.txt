cmake_minimum_required(VERSION 3.5)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds are not allowed.")
endif()

project(qui VERSION 0.0.1 LANGUAGES C)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_subdirectory(third_party)
add_subdirectory(src)

if(QUI_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()
