cmake_minimum_required(VERSION 3.6)
project(PlaylistManagementSystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(PlaylistManagementSystem src/main.cpp
        src/Song.cpp
        src/Playlist.cpp
        src/PlaylistManager.cpp
        src/FileHandler.cpp)
include_directories(include)
