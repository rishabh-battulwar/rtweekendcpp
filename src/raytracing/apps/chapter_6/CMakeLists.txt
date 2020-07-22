# 6.1 Shading with Surface Normals
add_executable(6.1 6.1.cpp)
target_link_libraries(6.1 PRIVATE raytracing project_options project_warnings)

# 6.1 Simplifying the Ray-Sphere Intersection Code
add_executable(6.2 6.2.cpp)
target_link_libraries(6.2 PRIVATE raytracing project_options project_warnings)

# 6.7 New main
add_executable(6.7 6.7.cpp)
target_link_libraries(6.7 PRIVATE raytracing project_options project_warnings)
