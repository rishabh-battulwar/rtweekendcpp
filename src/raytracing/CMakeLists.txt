add_library(raytracing STATIC)
target_include_directories(raytracing PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_sources(raytracing PRIVATE
    include/raytracing/math/vec3.h
    src/math/vec3.cpp)
target_link_libraries(raytracing PRIVATE project_options project_warnings)

add_subdirectory(apps)