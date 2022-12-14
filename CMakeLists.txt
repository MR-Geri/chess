cmake_minimum_required(VERSION 3.12)

project(chess VERSION 0.1 LANGUAGES CXX)

add_subdirectory(./tests)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

###############################################################################
include(CheckCXXSourceCompiles)
set(USE_SANITIZER "Leak")

function(append value)
  foreach(variable ${ARGN})
    set(${variable}
        "${${variable}} ${value}"
        PARENT_SCOPE)
  endforeach(variable)
endfunction()

function(append_quoteless value)
  foreach(variable ${ARGN})
    set(${variable}
        ${${variable}} ${value}
        PARENT_SCOPE)
  endforeach(variable)
endfunction()

function(test_san_flags return_var flags)
  set(QUIET_BACKUP ${CMAKE_REQUIRED_QUIET})
  set(CMAKE_REQUIRED_QUIET TRUE)
  unset(${return_var} CACHE)
  set(FLAGS_BACKUP ${CMAKE_REQUIRED_FLAGS})
  set(CMAKE_REQUIRED_FLAGS "${flags}")
  check_cxx_source_compiles("int main() { return 0; }" ${return_var})
  set(CMAKE_REQUIRED_FLAGS "${FLAGS_BACKUP}")
  set(CMAKE_REQUIRED_QUIET "${QUIET_BACKUP}")
endfunction()

if(USE_SANITIZER)
  append("-fno-omit-frame-pointer" CMAKE_C_FLAGS CMAKE_CXX_FLAGS)

  unset(SANITIZER_SELECTED_FLAGS)

  if(UNIX)
    if(uppercase_CMAKE_BUILD_TYPE STREQUAL "DEBUG")
      append("-O1" CMAKE_C_FLAGS CMAKE_CXX_FLAGS)
    endif()

    if(USE_SANITIZER MATCHES "([Aa]ddress)")
      # Optional: -fno-optimize-sibling-calls -fsanitize-address-use-after-scope
      message(STATUS "Testing with Address sanitizer")
      set(SANITIZER_ADDR_FLAG "-fsanitize=address")
      test_san_flags(SANITIZER_ADDR_AVAILABLE ${SANITIZER_ADDR_FLAG})
      if(SANITIZER_ADDR_AVAILABLE)
        message(STATUS "  Building with Address sanitizer")
        append("${SANITIZER_ADDR_FLAG}" SANITIZER_SELECTED_FLAGS)

        if(AFL)
          append_quoteless(AFL_USE_ASAN=1 CMAKE_C_COMPILER_LAUNCHER
                           CMAKE_CXX_COMPILER_LAUNCHER)
        endif()
      else()
        message(
          FATAL_ERROR
            "Address sanitizer not available for ${CMAKE_CXX_COMPILER}")
      endif()
    endif()

    if(USE_SANITIZER MATCHES "([Mm]emory([Ww]ith[Oo]rigins)?)")
      # Optional: -fno-optimize-sibling-calls -fsanitize-memory-track-origins=2
      set(SANITIZER_MEM_FLAG "-fsanitize=memory")
      if(USE_SANITIZER MATCHES "([Mm]emory[Ww]ith[Oo]rigins)")
        message(STATUS "Testing with MemoryWithOrigins sanitizer")
        append("-fsanitize-memory-track-origins" SANITIZER_MEM_FLAG)
      else()
        message(STATUS "Testing with Memory sanitizer")
      endif()
      test_san_flags(SANITIZER_MEM_AVAILABLE ${SANITIZER_MEM_FLAG})
      if(SANITIZER_MEM_AVAILABLE)
        if(USE_SANITIZER MATCHES "([Mm]emory[Ww]ith[Oo]rigins)")
          message(STATUS "  Building with MemoryWithOrigins sanitizer")
        else()
          message(STATUS "  Building with Memory sanitizer")
        endif()
        append("${SANITIZER_MEM_FLAG}" SANITIZER_SELECTED_FLAGS)

        if(AFL)
          append_quoteless(AFL_USE_MSAN=1 CMAKE_C_COMPILER_LAUNCHER
                           CMAKE_CXX_COMPILER_LAUNCHER)
        endif()
      else()
        message(
          FATAL_ERROR
            "Memory [With Origins] sanitizer not available for ${CMAKE_CXX_COMPILER}"
        )
      endif()
    endif()

    if(USE_SANITIZER MATCHES "([Uu]ndefined)")
      message(STATUS "Testing with Undefined Behaviour sanitizer")
      set(SANITIZER_UB_FLAG "-fsanitize=undefined")
      if(EXISTS "${BLACKLIST_FILE}")
        append("-fsanitize-blacklist=${BLACKLIST_FILE}" SANITIZER_UB_FLAG)
      endif()
      test_san_flags(SANITIZER_UB_AVAILABLE ${SANITIZER_UB_FLAG})
      if(SANITIZER_UB_AVAILABLE)
        message(STATUS "  Building with Undefined Behaviour sanitizer")
        append("${SANITIZER_UB_FLAG}" SANITIZER_SELECTED_FLAGS)

        if(AFL)
          append_quoteless(AFL_USE_UBSAN=1 CMAKE_C_COMPILER_LAUNCHER
                           CMAKE_CXX_COMPILER_LAUNCHER)
        endif()
      else()
        message(
          FATAL_ERROR
            "Undefined Behaviour sanitizer not available for ${CMAKE_CXX_COMPILER}"
        )
      endif()
    endif()

    if(USE_SANITIZER MATCHES "([Tt]hread)")
      message(STATUS "Testing with Thread sanitizer")
      set(SANITIZER_THREAD_FLAG "-fsanitize=thread")
      test_san_flags(SANITIZER_THREAD_AVAILABLE ${SANITIZER_THREAD_FLAG})
      if(SANITIZER_THREAD_AVAILABLE)
        message(STATUS "  Building with Thread sanitizer")
        append("${SANITIZER_THREAD_FLAG}" SANITIZER_SELECTED_FLAGS)

        if(AFL)
          append_quoteless(AFL_USE_TSAN=1 CMAKE_C_COMPILER_LAUNCHER
                           CMAKE_CXX_COMPILER_LAUNCHER)
        endif()
      else()
        message(
          FATAL_ERROR "Thread sanitizer not available for ${CMAKE_CXX_COMPILER}"
        )
      endif()
    endif()

    if(USE_SANITIZER MATCHES "([Ll]eak)")
      message(STATUS "Testing with Leak sanitizer")
      set(SANITIZER_LEAK_FLAG "-fsanitize=leak")
      test_san_flags(SANITIZER_LEAK_AVAILABLE ${SANITIZER_LEAK_FLAG})
      if(SANITIZER_LEAK_AVAILABLE)
        message(STATUS "  Building with Leak sanitizer")
        append("${SANITIZER_LEAK_FLAG}" SANITIZER_SELECTED_FLAGS)

        if(AFL)
          append_quoteless(AFL_USE_LSAN=1 CMAKE_C_COMPILER_LAUNCHER
                           CMAKE_CXX_COMPILER_LAUNCHER)
        endif()
      else()
        message(
          FATAL_ERROR "Thread sanitizer not available for ${CMAKE_CXX_COMPILER}"
        )
      endif()
    endif()

    if(USE_SANITIZER MATCHES "([Cc][Ff][Ii])")
      message(STATUS "Testing with Control Flow Integrity(CFI) sanitizer")
      set(SANITIZER_CFI_FLAG "-fsanitize=cfi")
      test_san_flags(SANITIZER_CFI_AVAILABLE ${SANITIZER_CFI_FLAG})
      if(SANITIZER_CFI_AVAILABLE)
        message(STATUS "  Building with Control Flow Integrity(CFI) sanitizer")
        append("${SANITIZER_LEAK_FLAG}" SANITIZER_SELECTED_FLAGS)

        if(AFL)
          append_quoteless(AFL_USE_CFISAN=1 CMAKE_C_COMPILER_LAUNCHER
                           CMAKE_CXX_COMPILER_LAUNCHER)
        endif()
      else()
        message(
          FATAL_ERROR
            "Control Flow Integrity(CFI) sanitizer not available for ${CMAKE_CXX_COMPILER}"
        )
      endif()
    endif()

    message(STATUS "Sanitizer flags: ${SANITIZER_SELECTED_FLAGS}")
    test_san_flags(SANITIZER_SELECTED_COMPATIBLE ${SANITIZER_SELECTED_FLAGS})
    if(SANITIZER_SELECTED_COMPATIBLE)
      message(STATUS " Building with ${SANITIZER_SELECTED_FLAGS}")
      append("${SANITIZER_SELECTED_FLAGS}" CMAKE_C_FLAGS CMAKE_CXX_FLAGS)
    else()
      message(
        FATAL_ERROR
          " Sanitizer flags ${SANITIZER_SELECTED_FLAGS} are not compatible.")
    endif()
  elseif(MSVC)
    if(USE_SANITIZER MATCHES "([Aa]ddress)")
      message(STATUS "Building with Address sanitizer")
      append("-fsanitize=address" CMAKE_C_FLAGS CMAKE_CXX_FLAGS)

      if(AFL)
        append_quoteless(AFL_USE_ASAN=1 CMAKE_C_COMPILER_LAUNCHER
                         CMAKE_CXX_COMPILER_LAUNCHER)
      endif()
    else()
      message(
        FATAL_ERROR
          "This sanitizer not yet supported in the MSVC environment: ${USE_SANITIZER}"
      )
    endif()
  else()
    message(FATAL_ERROR "USE_SANITIZER is not supported on this platform.")
  endif()

endif()
###############################################################################

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test Widgets Svg Core Multimedia)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test Widgets Svg Core Multimedia)

file(GLOB chess_src CONFIGURE_DEPENDS
  "resource.qrc"
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
    Qt${QT_VERSION_MAJOR}::Svg
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Multimedia
)

install(TARGETS chess
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(chess)
endif()
