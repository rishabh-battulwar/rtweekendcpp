# Generic test that uses conan libs
add_executable(raytrace main.cpp)
target_link_libraries(
  raytrace PRIVATE
    raytracing
    project_options 
    project_warnings 
    CONAN_PKG::docopt.cpp
    CONAN_PKG::fmt 
    CONAN_PKG::spdlog 
    CONAN_PKG::stb)
