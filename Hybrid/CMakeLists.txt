set(HYBRID_INCLUDE include)
file(GLOB_RECURSE HYBRID_SOURCE src/*.cpp)
file(GLOB_RECURSE HYBRID_HEADERS ${HYBRID_INCLUDE}/*.h)

add_library(Hybrid STATIC ${HYBRID_SOURCE} ${HYBRID_HEADERS})
target_include_directories(Hybrid PUBLIC ${HYBRID_INCLUDE})
target_link_libraries(Hybrid Signal Mna)
