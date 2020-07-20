add_library(raytracing INTERFACE)
# set_target_properties(raytracing PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(
  raytracing
  INTERFACE $<INSTALL_INTERFACE:include> $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_sources(raytracing INTERFACE include/raytracing/math/vec3.h 
                                  include/raytracing/math/color.h
                                  include/raytracing/math/ray.h)
target_link_libraries(raytracing INTERFACE project_options project_warnings)

add_subdirectory(apps)
