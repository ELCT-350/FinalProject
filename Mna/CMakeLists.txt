set(MNA_INCLUDE include)
file(GLOB_RECURSE MNA_SOURCE src/*.cpp)
file(GLOB_RECURSE MNA_HEADERS ${MNA_INCLUDE}/*.h)

add_library(Mna STATIC ${MNA_SOURCE} ${MNA_HEADERS})
target_include_directories(Mna PUBLIC ${MNA_INCLUDE})
target_link_libraries(Mna Common Math)
