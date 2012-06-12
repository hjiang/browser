include(${QT_USE_FILE})

#set(AUTOMOC TRUE)

set(SRCS
  browser_tab.cc
  browser_window.cc
  config.cc
  main.cc
)

set(PRINT_PAGE_SRCS
print_page.cc
page_printer.cc)

qt4_automoc(${SRCS})
qt4_automoc(${PRINT_PAGE_SRCS})

add_executable(browser ${SRCS})
add_executable(print_page ${PRINT_PAGE_SRCS})

target_link_libraries(browser ${QT_LIBRARIES})
target_link_libraries(print_page ${QT_LIBRARIES})
