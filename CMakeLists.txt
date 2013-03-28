project(killer)

add_executable(killer main.cpp cell.cpp addends.cpp)

install(TARGETS killer RUNTIME DESTINATION bin)
