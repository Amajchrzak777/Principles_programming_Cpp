cmake_minimum_required(VERSION 3.0)

project(zad01)

add_executable(zad01 zad01.cpp Graph.cpp GUI.cpp Simple_window.cpp Window.cpp)

TARGET_LINK_LIBRARIES(zad01 -lfltk -lfltk_images)

install(TARGETS zad01 RUNTIME DESTINATION bin)
