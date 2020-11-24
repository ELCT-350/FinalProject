set(SIGNAL_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB_RECURSE SIGNAL_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE SIGNAL_HEADERS ${SIGNAL_INCLUDE}/*.h)

add_library(Signal STATIC ${SIGNAL_SOURCE} ${SIGNAL_HEADERS})
target_include_directories(Signal PUBLIC ${SIGNAL_INCLUDE})
target_link_libraries(Signal Common)

