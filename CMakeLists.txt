cmake_minimum_required(VERSION 3.5)

project(plugininterface LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (UNIX AND NOT APPLE)
    set(LINUX 1)
endif (UNIX AND NOT APPLE)

find_package(Qt5 COMPONENTS Core REQUIRED)

if (UNIX)
    SET(LIBRARY_OUTPUT_PATH /usr/local/lib)
endif (UNIX)

if (WIN32)
    SET(LIBRARY_OUTPUT_PATH D:/Local/libs/lib)
endif ()


set(SRC
        apppluginterface/IAppPluginInterface.h
        apppluginterface/PluginMetaData.cpp
        apppluginterface/PluginMetaData.h
        apppluginterface/PLUGIN_INFO_KEY.h)


# SHARED
# STATIC
add_library(${PROJECT_NAME} STATIC
        ${SRC}
        )

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core)

target_compile_definitions(${PROJECT_NAME} PRIVATE APPPLUGININTERFACE_LIBRARY)

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)
install(DIRECTORY apppluginterface DESTINATION include FILES_MATCHING PATTERN "*.h")
install(EXPORT ${PROJECT_NAME} NAMESPACE app DESTINATION lib/cmake/appplugininterface)
