cmake_minimum_required(VERSION 3.7) # 2.8

project(sdl2-cpp-template)

# Project directory path variable: 
add_definitions(-DPROJECT_DIR=\"${CMAKE_SOURCE_DIR}\")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall -Wextra")

if(WIN32)
  # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows") # Comment for debugging.
endif()

if (APPLE) # TODO: Needs updated testing.
  link_directories(/opt/homebrew/opt/)
  # link_directories(/opt/homebrew/opt/sdl2/lib/)
  # link_directories(/opt/homebrew/opt/sdl2_image/lib/)
  # link_directories(/opt/homebrew/opt/sdl2_mixer/lib/)
  # link_directories(/opt/homebrew/opt/sdl2_ttf/lib/)
endif()

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_executable(${PROJECT_NAME}
  src/main.cpp
  src/utils.cpp
)

target_link_libraries(
  ${PROJECT_NAME} 
  ${SDL2_LIBRARIES}
  SDL2_image::SDL2_image
  SDL2_mixer::SDL2_mixer
  SDL2_ttf::SDL2_ttf
)