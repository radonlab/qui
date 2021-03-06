find_package(Skia REQUIRED)

include_directories(${SKIA_INCLUDE_DIRS})

set(QUI_SOURCES
  application.cc
  context.cc
  window.cc
  process/launch_params.cc
  process/master_process.cc
  process/process_factory.cc
  process/process_type.cc
  process/renderer_process.cc
  process/zygote_process.cc
)

if(UNIX)
  list(APPEND QUI_SOURCES
    base/process_utils_unix.cc
  )
endif()

set(QUI_HEADERS
  application.h
  context.h
  process.h
  qui_types.h
  window.h
  base/debug.h
  base/process_utils.h
  process/launch_params.h
  process/master_process.h
  process/process_factory.h
  process/process_type.h
  process/renderer_process.h
  process/zygote_process.h
)

add_library(qui STATIC ${QUI_SOURCES} ${QUI_HEADERS})
set_property(TARGET qui PROPERTY CXX_STANDARD 14)
target_link_libraries(qui gflags::gflags glfw ${SKIA_LIBRARIES})
target_include_directories(qui PUBLIC "${CMAKE_SOURCE_DIR}/src")
