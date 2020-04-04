find_package(Skia REQUIRED)

include_directories(${SKIA_INCLUDE_DIRS})

set(QUI_SOURCES
  context.cc
)

set(QUI_HEADERS
  context.h
  qui_types.h
)

add_library(qui STATIC ${QUI_SOURCES} ${QUI_HEADERS})
set_property(TARGET qui PROPERTY CXX_STANDARD 98)
target_include_directories(qui PUBLIC "${CMAKE_SOURCE_DIR}/src")
