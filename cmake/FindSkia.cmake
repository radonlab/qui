# - Find Skia library
# This module defines
# SKIA_FOUND        - True if headers and requested libraries were found
# SKIA_INCLUDE_DIRS - Skia include dirs
# SKIA_LIBRARIES    - Skia libraries

set(SKIA_SEARCH_PATH ${SKIA_SEARCH_PATH} "${CMAKE_SOURCE_DIR}/third_party/skia")

find_path(SKIA_INCLUDE_DIR
  NAMES core/SkCanvas.h
  PATHS ${SKIA_SEARCH_PATH}
  PATH_SUFFIXES include
)
find_library(SKIA_LIBRARY
  NAMES skia
  PATHS ${SKIA_SEARCH_PATH}/out
  PATH_SUFFIXES Static Shared
)

if(SKIA_INCLUDE_DIR AND SKIA_LIBRARY)
  set(SKIA_FOUND TRUE)
  set(SKIA_INCLUDE_DIRS
    "${SKIA_INCLUDE_DIR}/android"
    "${SKIA_INCLUDE_DIR}/c"
    "${SKIA_INCLUDE_DIR}/codec"
    "${SKIA_INCLUDE_DIR}/config"
    "${SKIA_INCLUDE_DIR}/core"
    "${SKIA_INCLUDE_DIR}/docs"
    "${SKIA_INCLUDE_DIR}/effects"
    "${SKIA_INCLUDE_DIR}/encode"
    "${SKIA_INCLUDE_DIR}/gpu"
    "${SKIA_INCLUDE_DIR}/atlastext"
    "${SKIA_INCLUDE_DIR}/pathops"
    "${SKIA_INCLUDE_DIR}/ports"
    "${SKIA_INCLUDE_DIR}/svg"
    "${SKIA_INCLUDE_DIR}/utils"
    "${SKIA_INCLUDE_DIR}/utils/mac"
  )
  set(SKIA_LIBRARIES ${SKIA_LIBRARY})
else()
  set(SKIA_FOUND FALSE)
endif()

mark_as_advanced(SKIA_INCLUDE_DIRS SKIA_LIBRARIES)
