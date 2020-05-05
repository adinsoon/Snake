cmake_minimum_required(VERSION 3.1)
project(SnakeOld)
#
#
set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra)
#
#
if (UNIX)
    set ( CMAKE_MODULES_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
endif(UNIX)
#
#
if (WIN32)
    set( SFML_STATIC_LIBRARIES TRUE )
    set ( SFML_DIR "C:/SFML-2.5/SFML-2.5.1/lib/cmake/SFML/")
endif(WIN32)
#
#
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)
#
#
add_executable(SnakeOld main.cpp Board.cpp Board.h Tools.cpp Tools.h TextView.cpp TextView.h SFMLView.cpp SFMLView.h SFMLController.cpp SFMLController.h Stats.cpp Stats.h Logic.cpp Logic.h Controller.cpp Controller.h Menu.cpp Menu.h PostGame.cpp PostGame.h Manager.cpp Manager.h)
#
#
target_link_libraries(SnakeOld sfml-graphics sfml-audio)