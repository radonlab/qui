find_package(Skia REQUIRED)

include_directories(${SKIA_INCLUDE_DIRS})

set(QUI_SOURCES
  application.cc
  context.cc
  window.cc
  process/main_process.cc
  process/render_process.cc
)

set(QUI_HEADERS
  application.h
  context.h
  process.h
  qui_types.h
  window.h
  process/main_process.h
  process/render_process.h
)

add_library(qui STATIC ${QUI_SOURCES} ${QUI_HEADERS})
set_property(TARGET qui PROPERTY CXX_STANDARD 14)
target_link_libraries(qui gflags::gflags glfw ${SKIA_LIBRARIES})
target_include_directories(qui PUBLIC "${CMAKE_SOURCE_DIR}/src")
