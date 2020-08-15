cmake_minimum_required(VERSION 3.0)

project(zad02)

add_executable(zad02 zad02.cpp Graph.cpp GUI.cpp Simple_window.cpp Window.cpp)

TARGET_LINK_LIBRARIES(zad02 -lfltk -lfltk_images)

install(TARGETS zad02 RUNTIME DESTINATION bin)
