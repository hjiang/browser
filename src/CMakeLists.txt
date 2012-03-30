include(${QT_USE_FILE})

set(AUTOMOC TRUE)

if(APPLE)
  include_directories(BEFORE
    /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/c++/v1)
  set(CMAKE_CXX_FLAGS -std=c++11)
else()
  set(CMAKE_CXX_FLAGS -std=c++0x)
endif()

set(SRCS
  browser_tab.cc
  browser_window.cc
  config.cc
  main.cc
)

qt4_automoc(${SRCS})

add_executable(browser ${SRCS})

target_link_libraries(browser ${QT_LIBRARIES})
