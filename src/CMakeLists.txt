file(GLOB LIB_SRC_FILES lib/*.c)
add_library(espace SHARED ${LIB_SRC_FILES})

file(GLOB ELIB_SRC_FILES elib/*.c)
add_library(elib SHARED ${ELIB_SRC_FILES})
target_link_libraries(elib espace)

file(GLOB EXE_SRC_FILES imp/*.c)
foreach(EXE_SRC_FILE ${EXE_SRC_FILES})
    get_filename_component(EXE_DEST_FILE ${EXE_SRC_FILE} NAME_WE)
    add_executable(${EXE_DEST_FILE} ${EXE_SRC_FILE})
    target_link_libraries(${EXE_DEST_FILE} elib)
endforeach()

install(TARGETS espace DESTINATION /usr/lib)
