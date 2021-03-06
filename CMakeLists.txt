cmake_minimum_required(VERSION 3.2)
project(mytoolbox)
set (TOOLBOX_VERSION_MAJOR ${VERSION_MAJOR})
set (TOOLBOX_VERSION_MINOR ${VERSION_MINOR})
set (TOOLBOX_VERSION_PATCH ${VERSION_PATCH})
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
set (CPACK_PACKAGE_VERSION_MAJOR "${TOOLBOX_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${TOOLBOX_VERSION_MINOR}")
set (CPACK_PACKAGE_VERSION_PATCH "${TOOLBOX_VERSION_PATCH}")

set (CPACK_COMPONENTS_ALL applications libraries headers)
set (CPACK_COMPONENT_APPLICATIONS_DESCRIPTION "Matlab Toolbox for template-cmake example")
set (CPACK_COMPONENT_LIBRARIES_DESCRIPTION "Static libraries used to build programs with template-cmake example")
set (CPACK_COMPONENT_HEADERS_DESCRIPTION "C/C++ header files for use with template")

include (CPack)
