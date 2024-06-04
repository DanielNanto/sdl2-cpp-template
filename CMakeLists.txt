cmake_minimum_required(VERSION 3.5)
# cmake_minimum_required(VERSION 2.8)

add_definitions(-DPROJECT_DIR=\"${CMAKE_SOURCE_DIR}\") # To-Do: Test on Windows & Linux.

project(sdl2-cpp-template)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall -Wextra")
if(WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows") # Comment for debug console.
  if (MSVC)
    message(STATUS "Using Microsoft Visual C++ Compiler.")
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
  endif()
endif()

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image)
PKG_SEARCH_MODULE(SDL2MIXER REQUIRED SDL2_mixer)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf) # To-Do: Test on Linux.

if (APPLE)
  link_directories(/opt/homebrew/opt/sdl2/lib/)
  link_directories(/opt/homebrew/opt/sdl2_image/lib/)
  link_directories(/opt/homebrew/opt/sdl2_mixer/lib/)
  link_directories(/opt/homebrew/opt/sdl2_ttf/lib/) # To-Do: Test on Linux.
  find_package(SDL2 REQUIRED)
  find_package(SDL2_image REQUIRED)
  find_package(SDL2_mixer REQUIRED)
  find_package(SDL2_ttf REQUIRED) # To-Do: Test on Linux.
endif()

INCLUDE_DIRECTORIES(
  ${SDL2_INCLUDE_DIRS} 
  ${SDL2IMAGE_INCLUDE_DIRS} 
  ${SDL2MIXER_INCLUDE_DIRS}
  ${SDL2TTF_INCLUDE_DIRS}) # To-Do: Test on Linux.

add_executable(${PROJECT_NAME})
add_subdirectory(src)

TARGET_LINK_LIBRARIES(
  ${PROJECT_NAME} 
  ${SDL2_LIBRARIES}
  ${SDL2IMAGE_LIBRARIES} 
  ${SDL2MIXER_LIBRARIES}
  ${SDL2TTF_LIBRARIES}) # To-Do: Test on Linux.
