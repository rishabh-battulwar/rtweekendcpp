# 2.1 The PPM Image Format
add_executable(2.1 2.1.cpp)
target_link_libraries(
  2.1 PRIVATE
    project_options 
    project_warnings 
  )

# 2.2 Creating an Image File
# Is a bash script to write image file using 2.1

# 2.3 Adding a Progress Indicator
add_executable(2.3 2.3.cpp)
target_link_libraries(
2.3 PRIVATE
    project_options 
    project_warnings 
)
  