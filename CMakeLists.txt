cmake_minimum_required(VERSION 2.6)

project(killer)

add_executable(killer main.cpp cell.cpp addends.cpp constraint.cpp board.cpp)

install(TARGETS killer RUNTIME DESTINATION bin)
