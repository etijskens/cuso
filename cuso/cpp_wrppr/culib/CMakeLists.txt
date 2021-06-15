cmake_minimum_required(VERSION 3.4)

message("SUBDIRECTORY culib")

project(culib CXX CUDA)

add_library( culib SHARED
  culib.cu
)

# see https://stackoverflow.com/questions/50390730/why-do-i-need-separable-compilation
# so in this case we don't need it
# set_target_properties( culib
#                        PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

install(
    FILES       "${CMAKE_CURRENT_SOURCE_DIR}/../_cmake_build/culib/libculib.so"
    DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/../.."
)
                