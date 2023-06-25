
cmake_minimum_required(VERSION 2.8)
add_compile_options(-std=c++11)


message("HELLO")
message("${DYNSOCCDIR}")
# link_directories(D:/work20/github/dynamicsoccer/build5/Debug)
link_directories(${DYNSOCCDIR_BIN})

# Use 
# cmake -DDYNSOCCDIR:PATH=/path/to/dynamicsoccer -DDYNSOCCDIR_BIN:PATH=/path/to/dynamicsoccer_build_lib_output
# Or uncomment and set correct Path to dynamicsoccer
# set(DYNSOCCDIR /path/src/dynamicsoccer)
# set(DYNSOCCDIR_BIN /path/dynamicsoccer_out)

include_directories(${DYNSOCCDIR}/src/DynamicSoccer)
find_library(${DYNSOCCDIR_BIN} -llibdynsocc)

project(vstock )
include_directories(./Vstock)
file(GLOB SOURCES "Vstock/main.cpp" 
					"Vstock/vstock/impl/*.cpp"
					"Vstock/vstock/impl/finance/*.cpp")

add_executable( main ${SOURCES} )

if (MSVC)
	target_link_libraries(main libdynsocc.lib)
else ()
	target_link_libraries(main -llibdynsocc)
endif ()


