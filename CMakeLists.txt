cmake_minimum_required (VERSION 2.8.12.2)
project (Atlas)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
add_executable(Atlas backend_init.c)
# Sqlite3
find_package (SQLite3 REQUIRED)
if (SQLITE3_FOUND)
    include_directories(${SQLITE3_INCLUDE_DIRS})
    target_link_libraries (Atlas ${SQLITE3_LIBRARIES})
endif (SQLITE3_FOUND)

#NCurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

target_link_libraries(Atlas ${CURSES_LIBRARIES})
