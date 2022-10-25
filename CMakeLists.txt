cmake_minimum_required(VERSION 3.12)

project(chess VERSION 0.1 LANGUAGES CXX)

add_subdirectory(./tests)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test Widgets)

    # src/main.cpp
    # src/constants.h
    # src/gui/main_window/main_window.cpp
    # src/gui/main_window/main_window.h
    # src/gui/main_window/main_window.ui
    # src/gui/scene_game/scene_game.cpp
    # src/gui/scene_game/scene_game.h
    # src/gui/scene_game/scene_game.ui
    # src/gui/screen_game/screen_game.cpp
    # src/gui/screen_game/screen_game.h
    # src/gui/screen_game/screen_game.ui
    # src/gui/screen_liderboard/screen_liderboard.cpp
    # src/gui/screen_liderboard/screen_liderboard.h
    # src/gui/screen_liderboard/screen_liderboard.ui
    # src/gui/screen_menu/screen_menu.cpp
    # src/gui/screen_menu/screen_menu.h
    # src/gui/screen_menu/screen_menu.ui
    # src/gui/screen_settings/screen_settings.cpp
    # src/gui/screen_settings/screen_settings.h
    # src/gui/screen_settings/screen_settings.ui
    # src/logic/board/board.cpp
    # src/logic/board/board.h
    # src/logic/board/board.ui
    # src/logic/figures/figures.cpp
    # src/logic/figures/figures.h
    # src/logic/figures/figures.ui
    # src/logic/liderboard/liderboard.cpp
    # src/logic/liderboard/liderboard.h
    # src/logic/liderboard/liderboard.ui
    # src/storage/settings/settings.cpp
    # src/storage/settings/settings.h

file(GLOB chess_src CONFIGURE_DEPENDS 
  "src/*.cpp" "src/*.h" "src/*.ui"
  "src/*/*.cpp" "src/*/*.h" "src/*/*.ui"
  "src/*/*/*.cpp" "src/*/*/*.h" "src/*/*/*.ui"
  "src/*/*/*/*.cpp" "src/*/*/*/*.h" "src/*/*/*/*.ui"
  "src/*/*/*/*/*.cpp" "src/*/*/*/*/*.h" "src/*/*/*/*/*.ui"
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(chess
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET chess APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(chess SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(chess
            ${chess_src}
        )
    endif()
endif()


target_link_libraries(chess PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Test
)

set_target_properties(chess PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS chess
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(chess)
endif()
