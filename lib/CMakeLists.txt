file(GLOB SOURCES ./*.c)
file(GLOB HEADERS ../include/*.h)
source_group("include" FILES ${HEADERS})
source_group("lib" FILES ${SOURCES})
add_library(toolbox STATIC ${SOURCES} ${HEADERS})

install(TARGETS toolbox ARCHIVE DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include)
