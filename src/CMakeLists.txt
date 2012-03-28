include(${QT_USE_FILE})

set(CMAKE_CXX_FLAGS -std=c++11)
set(AUTOMOC TRUE)

include_directories(BEFORE /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/c++/v1)

set(SRCS main.cc main_window.cc)

qt4_automoc(${SRCS})

add_executable(browser ${SRCS})

target_link_libraries(browser ${QT_LIBRARIES})
