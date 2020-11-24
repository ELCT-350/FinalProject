set(HYBRID_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB_RECURSE HYBRID_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HYBRID_HEADERS ${HYBRID_INCLUDE}/*.h)

add_library(Hybrid STATIC ${HYBRID_SOURCE} ${HYBRID_HEADERS})
target_link_libraries(Hybrid Signal mna)
target_include_directories(Hybrid PUBLIC ${HYBRID_INCLUDE})

