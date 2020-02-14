cmake_minimum_required(VERSION 3.5)

project(app-plugininterface LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_HOST_WIN32)
    set(WIN32 1)
elseif (CMAKE_HOST_APPLE)
    set(APPLE 1)
elseif (CMAKE_HOST_UNIX)
    set(UNIX 1)
endif ()


find_package(Qt5 COMPONENTS Core REQUIRED)

if (APPLE)
	SET(LIBRARY_OUTPUT_PATH /usr/local/lib)
elseif (WIN32)
	SET(LIBRARY_OUTPUT_PATH D:/Local/libs/lib)
elseif(UNIX)
	SET(LIBRARY_OUTPUT_PATH /usr/local/ v lib)
endif ()


# SHARED
# STATIC
add_library(${PROJECT_NAME} STATIC
        apppluginterface/IAppPluginInterface.h
        apppluginterface/PluginMetaData.cpp
        apppluginterface/PluginMetaData.h)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core)

target_compile_definitions(${PROJECT_NAME} PRIVATE IAPPPLUGININTERFACE_LIBRARY)


install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)
install(DIRECTORY apppluginterface DESTINATION include FILES_MATCHING PATTERN "*.h")
install(EXPORT ${PROJECT_NAME} NAMESPACE ${PROJECT_NAME}:: DESTINATION lib/cmake/appplugininterface)
