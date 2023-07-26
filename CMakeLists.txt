# CMakeList.txt : CMake project for Flux, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
project ("Flux")




# define library target, and includes headers
add_library(fluxlib STATIC	include/math/vec3.h
							include/math/matrix3.h


							src/math/vec3.cpp
							src/math/matrix3.cpp)

# include headers 
target_include_directories(fluxlib PUBLIC include)




add_executable (Flux "src/flux.cpp")
target_link_libraries(Flux PUBLIC fluxlib)


# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Flux PROPERTY CXX_STANDARD 20)
endif()