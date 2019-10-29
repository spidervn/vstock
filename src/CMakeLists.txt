
cmake_minimum_required(VERSION 2.8)
add_compile_options(-std=c++11)

project( main  )
include_directories(./Vstock)
file(GLOB SOURCES "Vstock/main.cpp" 
					"Vstock/vstock/impl/*.cpp"
					"Vstock/vstock/impl/finance/*.cpp")

add_executable( main ${SOURCES} )