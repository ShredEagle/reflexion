set(TARGET_NAME reflexion)

set(${TARGET_NAME}_HEADERS
    Concept.h
    NameValuePair.h
)

source_group(TREE ${CMAKE_CURRENT_LIST_DIR}
             FILES ${${TARGET_NAME}_HEADERS}
)

add_library(${TARGET_NAME} INTERFACE)

# Custom target to have the files show up in the IDE
add_custom_target(${TARGET_NAME}_IDE
    SOURCES
        ${${TARGET_NAME}_HEADERS}
)

add_library(ad::${TARGET_NAME} ALIAS ${TARGET_NAME})

if(MSVC)
    target_compile_options(${TARGET_NAME} INTERFACE "/Zc:__cplusplus")
endif()

install(TARGETS ${TARGET_NAME} EXPORT ${TARGET_NAME}Targets)

include(cmc-install)

# Install the header files
cmc_install_with_folders(DESTINATION include/${TARGET_NAME}/${TARGET_NAME}
                         FILES ${${TARGET_NAME}_HEADERS})
# Setup CMake package in both build and install trees
cmc_install_packageconfig(${TARGET_NAME} ${TARGET_NAME}Targets ${PROJECT_NAME}
                          NAMESPACE ad::)
