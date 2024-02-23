cmake_minimum_required(VERSION 3.7)

set(PROJ_NAME CSnake)

project(${PROJ_NAME})

set(CMAKE_C_STANDARD 11)

if (MSVC)
  set(FLAGS /W4 /WX)
  set(CMAKE_C_FLAGS_DEBUG "/Zi")
  set(CMAKE_C_FLAGS_RELEASE "/O2")
else()
  set(FLAGS -Wall -Werror)
  set(CMAKE_C_FLAGS_DEBUG "-g")
  set(CMAKE_C_FLAGS_RELEASE "-O3")
endif()

add_compile_options(${FLAGS})

find_package(SDL2 REQUIRED)
include_directories(${PROJ_NAME} ${SDL2_INCLUDE_DIRS})

set(SOURCES 
  src/main.c 
  src/trace.c 
  src/app.c
  src/world.c
)

add_executable(${PROJ_NAME} ${SOURCES})
target_include_directories(${PROJ_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJ_NAME} ${SDL2_LIBRARIES})
