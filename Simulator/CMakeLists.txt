set(SIMULATOR_INCLUDE include)
file(GLOB_RECURSE SIMULATOR_SOURCE src/*.cpp)
file(GLOB_RECURSE SIMULATOR_HEADERS ${SIMULATOR_INCLUDE}/*.h)

add_executable(Simulator ${SIMULATOR_SOURCE} ${SIMULATOR_HEADERS})
target_include_directories(Simulator PRIVATE ${SIMULATOR_INCLUDE})
target_link_libraries(Simulator Signal Math)
