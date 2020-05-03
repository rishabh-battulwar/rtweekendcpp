# Generic test that uses conan libs
add_executable(raytracer main.cpp)
target_link_libraries(
  raytracer PRIVATE
    raytracing
    project_options 
    project_warnings 
    CONAN_PKG::docopt.cpp
    CONAN_PKG::fmt 
    CONAN_PKG::spdlog 
    CONAN_PKG::stb)
