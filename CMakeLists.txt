cmake_minimum_required(VERSION 3.20)
#cmake_minimum_required(VERSION 3.21)
project(Sbomber_linux)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(include/enums)

add_executable(Sbomber_linux
        include/enums/ConsoleColors.h
        include/enums/CraterSize.h
        include/Bomb.h
        include/Crater.h
        include/DestroyableGroundObject.h
        include/DynamicObject.h
        include/GameObject.h
        include/Ground.h
        include/House.h
        include/LevelGUI.h
        include/MyTools.h
        include/Plane.h
        include/SBomber.h
        include/ScreenSingleton.h
        include/Tank.h
        src/Bomb.cpp
        src/Crater.cpp
        src/Ground.cpp
        src/House.cpp
        src/LevelGUI.cpp
        src/MyTools.cpp
        src/Plane.cpp
        src/SBomber.cpp
        src/ScreenSingleton.cpp
        src/Tank.cpp
        main.cpp )
