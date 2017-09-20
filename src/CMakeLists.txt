file(GLOB LIB_SRC_FILES lib/*.c)
add_library(espace SHARED ${LIB_SRC_FILES})

file(GLOB EXAMLIB_SRC_FILES examlib/*.c)
add_library(examlib SHARED ${EXAMLIB_SRC_FILES})
target_link_libraries(examlib espace)

file(GLOB EXAMPLE_SRC_FILES example/*.c)
foreach(EXAMPLE_SRC_FILE ${EXAMPLE_SRC_FILES})
    get_filename_component(EXAMPLE_DEST_FILE ${EXAMPLE_SRC_FILE} NAME_WE)
    add_executable(${EXAMPLE_DEST_FILE} ${EXAMPLE_SRC_FILE})
    target_link_libraries(${EXAMPLE_DEST_FILE} examlib)
endforeach()

install(TARGETS espace DESTINATION /usr/lib)
