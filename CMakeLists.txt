cmake_minimum_required(VERSION 3.20)
project(1)

set(CMAKE_CXX_STANDARD 14)

link_directories("${PROJECT_SOURCE_DIR}/SFML-2.5.1/lib")

add_executable( ${PROJECT_NAME} main.cpp Menu.cpp Option.cpp Window.cpp Window.h Game.cpp Game.h Snakes.cpp Snakes.h PauseGame.cpp PauseGame.h OptionWindow.cpp OptionWindow.h GameWindow.cpp GameWindow.h GameOverWindow.cpp GameOverWindow.h GameOver.cpp GameOver.h)


target_include_directories( ${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/SFML-2.5.1/include")
target_link_libraries( ${PROJECT_NAME} opengl32 winmm gdi32 sfml-system sfml-window sfml-graphics sfml-audio)


