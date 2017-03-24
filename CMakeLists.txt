cmake_minimum_required(VERSION 3.2)
project(rtls)
set (RTLS_VERSION_MAJOR ${VERSION_MAJOR})
set (RTLS_VERSION_MINOR ${VERSION_MINOR})
set (RTLS_VERSION_PATCH ${VERSION_PATCH})
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
include_directories("${PROJECT_BINARY_DIR}")
set(CMAKE_BUILD_TYPE ${BUILD_TYPE})
include_directories(include)
add_subdirectory(include)
add_subdirectory(lib)
add_subdirectory(src)
#add_subdirectory(mex)

# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${RTLS_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${RTLS_VERSION_MINOR}")
set (CPACK_PACKAGE_VERSION_PATCH "${RTLS_VERSION_PATCH}")

set (CPACK_COMPONENTS_ALL applications libraries headers)
set (CPACK_COMPONENT_APPLICATIONS_DESCRIPTION “RTLS utilities”)
set (CPACK_COMPONENT_LIBRARIES_DESCRIPTION "Static libraries used to build programs with librtls”)
set (CPACK_COMPONENT_HEADERS_DESCRIPTION "C/C++ header files for use with librtls”)

include (CPack)
