find_package(Skia REQUIRED)

include_directories(${SKIA_INCLUDE_DIRS})

set(QUI_SOURCES
  context.c
)

set(QUI_HEADERS
  context.h
  qui_types.h
)

add_library(qui STATIC ${QUI_SOURCES} ${QUI_HEADERS})
target_include_directories(qui PUBLIC "${CMAKE_SOURCE_DIR}/src")
