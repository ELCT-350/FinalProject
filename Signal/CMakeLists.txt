set(SIGNAL_INCLUDE include)
file(GLOB_RECURSE SIGNAL_SOURCE src/*.cpp)
file(GLOB_RECURSE SIGNAL_HEADERS ${SIGNAL_INCLUDE}/*.h)

add_library(Signal STATIC ${SIGNAL_SOURCE} ${SIGNAL_HEADERS})
target_include_directories(Signal PUBLIC ${SIGNAL_INCLUDE})
target_link_libraries(Signal Common)
