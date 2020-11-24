set(MNA_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB_RECURSE MNA_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE MNA_HEADERS ${MNA_INCLUDE}/*.h)

add_library(mna STATIC ${MNA_SOURCE} ${MNA_HEADERS})
target_link_libraries(mna Common Math)
target_include_directories(mna PUBLIC ${MNA_INCLUDE})

