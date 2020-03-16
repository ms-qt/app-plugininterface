cmake_minimum_required(VERSION 3.5)
# 组织信息
set(IDENTIFIER "bdlbsc")
set(COPYRIGHT "Copyright © 2019-2020 bdlbsc")
# 项目名称 版本
project(bdlbsc-plugin-supper VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# LINUX 平台判断
# Windows 平台 为 WIN32
# MacOS 平台 为 APPLE
# UNIX 包含 linux 和 macos
if (UNIX AND NOT APPLE)
    set(LINUX 1)
endif (UNIX AND NOT APPLE)

# SHARED
# STATIC
set(LIB_TYPE STATIC)


if (UNIX)
    include_directories(/usr/local/dev/vcpkg/installed/x64-osx/include)
    link_directories(/usr/local/dev/vcpkg/installed/x64-osx/share/lib)

    include_directories(/usr/local/include)
    link_directories(/usr/local/lib)
endif (UNIX)

if (WIN32)

    include_directories(D:/Local/vcpkg/installed/x64-windows/include)
    link_directories(D:/Local/vcpkg/installed/x64-windows/lib)

    include_directories("D:/Local/libs/include")
    link_directories("D:/Local/libs/lib")

endif (WIN32)


if (UNIX)
    SET(CMAKE_INSTALL_PREFIX /usr/local)
endif (UNIX)

if (WIN32)
    SET(CMAKE_INSTALL_PREFIX D:/Local/libs)
endif (WIN32)

if (UNIX)
    SET(LIBRARY_OUTPUT_PATH /usr/local/lib)
endif (UNIX)

if (WIN32)
    SET(LIBRARY_OUTPUT_PATH D:/Local/libs/lib)
endif ()


find_package(Qt5
        COMPONENTS
        Core
        REQUIRED)


set(SRC
        bdlbsc/plugin/supper/IAppPluginInterface.h
        bdlbsc/plugin/supper/PluginMetaData.cpp
        bdlbsc/plugin/supper/PluginMetaData.h
        bdlbsc/plugin/supper/PLUGIN_INFO_KEY.h)

# SHARED
# STATIC
add_library(${PROJECT_NAME} ${LIB_TYPE}
        ${SRC}
        )

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core)
target_compile_definitions(${PROJECT_NAME} PRIVATE APPPLUGININTERFACE_LIBRARY)


# 如果没有指定安装路径，就安装到当前目录
if (NOT CMAKE_INSTALL_BINDIR)
    set(CMAKE_INSTALL_BINDIR ".")
endif ()


install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib)

install(DIRECTORY bdlbsc DESTINATION include FILES_MATCHING PATTERN "*.h")

configure_file(cmake/Config.cmake.in ${PROJECT_NAME}Config.cmake @ONLY)

if (WIN32)

    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
            DESTINATION D:/Local/libs/lib/cmake/bdlbsc/plugin/supper)


    install(EXPORT ${PROJECT_NAME}
            NAMESPACE bdlbsc
            DESTINATION D:/Local/libs/lib/cmake/bdlbsc/plugin/supper)

endif (WIN32)


if (UNIX)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
            DESTINATION /usr/local/lib/cmake/bdlbsc/plugin/supper)

    install(EXPORT ${PROJECT_NAME}
            NAMESPACE bdlbsc
            DESTINATION /usr/local/lib/cmake/bdlbsc/plugin/supper)
endif (UNIX)