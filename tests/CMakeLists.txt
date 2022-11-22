cmake_minimum_required(VERSION 3.5)

project(tests LANGUAGES CXX)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test Widgets)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tests
    tst_board.cpp
    tst_figures.cpp
    tst_engine.cpp
    tst_all.cpp
    ../src/logic/figures/figures.h
    ../src/logic/figures/figures.cpp
    ../src/logic/engine/engine.h
    ../src/logic/engine/engine.cpp
    ../src/logic/board/board.h
    ../src/logic/board/board.cpp
)

target_link_libraries(tests
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Test
)
