file(GLOB SOURCES ./*.c)
file(GLOB HEADERS ../include/*.h)
source_group("include" FILES ${HEADERS})
source_group("lib" FILES ${SOURCES})
add_library(rtls STATIC ${SOURCES} ${HEADERS})

install(TARGETS rtls ARCHIVE DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include)
