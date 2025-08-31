cmake_minimum_required(VERSION 3.16)

project(eko_dash2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(Qt6_DIR home/igor/Qt/6.9.2/gcc_64/lib/cmake)
set(CMAKE_PREFIX_PATH /home/igor/Qt/6.9.2/gcc_64)
find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

set(CMAKE_AUTORCC ON)
qt_add_executable(appeko_dashboard
    resources.qrc
    src/main.cpp
    src/blinker.cpp
    src/clock.cpp
    src/valueinfo.cpp
    src/can.cpp
    src/system.cpp
    inc/blinker.h
    inc/clock.h
    inc/valueinfo.h
    inc/can.h
    inc/system.h
    inc/includes.h
    inc/dbc.h

)

target_include_directories(appeko_dashboard
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appeko_dashboard PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appeko_dashboard
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appeko_dashboard
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appeko_dashboard
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
