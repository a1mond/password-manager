cmake_minimum_required(VERSION 3.16)
project(Password_Manager_v2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Password_Manager_v2 main.cpp ReadWriteManager/rwmanager.cpp User/User.cpp User/User.h ReadWriteManager/rwmanager.h GUI/console_interface.cpp GUI/console_interface.h Consts/Consts.h Debug/debug.h)