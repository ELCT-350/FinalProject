set(COMMON_INCLUDE include)
file(GLOB_RECURSE COMMON_SOURCE src/*.cpp)
file(GLOB_RECURSE COMMON_HEADERS ${COMMON_INCLUDE}/*.h)

add_library(Common STATIC ${COMMON_SOURCE} ${COMMON_HEADERS})
target_include_directories(Common PUBLIC ${COMMON_INCLUDE})
