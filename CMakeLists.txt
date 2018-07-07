cmake_minimum_required (VERSION 2.6)
project (Voicy)
set (CMAKE_CXX_STANDARD 11)

find_package(PkgConfig)
pkg_check_modules(POCKETSPHINX REQUIRED pocketsphinx)
pkg_check_modules(SPHINXBASE REQUIRED sphinxbase)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")
set(ESD_LIBRARY "/usr/lib/x86_64-linux-gnu/ao/plugins-4/libesd.so")
set(EST_DIR "${CMAKE_CURRENT_LIST_DIR}")
find_package(EST REQUIRED est)

set(Festival_DIR "${CMAKE_CURRENT_LIST_DIR}/")
find_package(Festival REQUIRED festival)

message(STATUS "SPHINXBASE_LIBRARIES => " "${SPHINXBASE_LIBRARIES}")
message(STATUS "POCKETSPHINX_LIBRARIES => " "${POCKETSPHINX_LIBRARIES}")
message(STATUS "POCKETSPHINX_INCLUDE_DIRS => " "${POCKETSPHINX_INCLUDE_DIRS}")
message(STATUS "SPHINXBASE_INCLUDE_DIRS => " "${SPHINXBASE_INCLUDE_DIRS}")
message(STATUS "FESTIVAL_INCLUDE_DIRS => " "${FESTIVAL_INCLUDE_DIRS}")

INCLUDE_DIRECTORIES(include ${CMAKE_SOURCE_DIR}
                            ${EST_INCLUDE_DIR}
                            ${Festival_INCLUDE_DIR})

message("DUPA-1")
include_directories("../pocketsphinx/include")
include_directories("../sphinxbase/include")

message("DUPA0")
set(CMAKE_PREFIX_PATH /home/slawek/workspace/SpeechRecognition/pocketsphinx/include)
find_library(POCKETSPHINX_LIBRARY NAMES pocketsphinx HINTS "$POCKETSPHINX_INCLUDE_DIRS")
find_library(SPHINXBASE_LIBRARY NAMES sphinxbase HINTS "$SPHINXBASE_INCLUDE_DIRS")
MESSAGE( STATUS "POCKETSPHINX_LIBRARY: " ${POCKETSPHINX_LIBRARY} )


include_directories (${PROJECT_SOURCE_DIR}, FSMs/Include, Resources/)
message("${PROJECT_SOURCE_DIR}/FSMs/Include")

file(GLOB SOURCES "FSMs/Source/*.cpp")

project (Voicy)
add_executable(Voicy Voicy.cpp RecFromMic.cpp ${SOURCES})
target_include_directories(Voicy PRIVATE FSMs/Include)
message("DUPA5")

set(LIBNCURSES_LIBRARY "/usr/lib/x86_64-linux-gnu/ao/plugins-4/libesd.so")
message("DUPA6")
MESSAGE( STATUS "DUPA_Festival_LIBRARY: " ${Festival_LIBRARIES} )
target_link_libraries(Voicy ${POCKETSPHINX_LIBRARIES} ${SPHINXBASE_LIBRARIES} ${EST_LIBRARIES} ${Festival_LIBRARIES} ${LIBNCURSES_LIBRARY})
