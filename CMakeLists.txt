cmake_minimum_required(VERSION 3.16)
project(Source)

set(CMAKE_CXX_STANDARD 14)

include_directories(PRGame)

add_executable(Source
        PRGame/Avatar.cpp
        PRGame/Avatar.h
        PRGame/GameModePRGame.cpp
        PRGame/GameModePRGame.h
        PRGame/MyHUD.cpp
        PRGame/MyHUD.h
        PRGame/NPC.cpp
        PRGame/NPC.h
        PRGame/NPCC.cpp
        PRGame/NPCC.h
        PRGame/PRGame.cpp
        PRGame/PRGame.h
        PRGame/PRGameGameMode.cpp
        PRGame/PRGameGameMode.h)
