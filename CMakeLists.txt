cmake_minimum_required(VERSION 3.16)
project(TaskManager)

include_directories("src/include")

file(GLOB SOURCES "src/core/*.cpp" "src/core/model/*.cpp" "src/core/view/*.cpp" "src/core/service/*.cpp" "src/core/repository/*.cpp")
add_executable(TaskManager ${SOURCES})

file(GLOB TESTES "src/core/database.cpp" "src/core/model/*.cpp" "src/core/view/*.cpp" "src/core/service/*.cpp" "src/core/repository/*.cpp" "src/tests/*.cpp" "src/tests/*.h")
add_executable(Tests ${TESTES})

find_package(SQLite3 REQUIRED)
target_link_libraries (TaskManager PRIVATE SQLite::SQLite3)
target_link_libraries (Tests PRIVATE SQLite::SQLite3)