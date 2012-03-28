project(browser)

cmake_minimum_required(VERSION 2.8)

find_package(Qt4 REQUIRED QtCore QtGui QtNetwork QtWebKit)

add_subdirectory(src)
