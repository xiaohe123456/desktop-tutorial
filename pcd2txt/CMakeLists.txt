cmake_minimum_required(VERSION 3.0.2)
#set(project_name cloud_viewer_PointXYZ)
project(pcd2txt)
find_package(PCL 1.8.0 REQUIRED)


include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})


add_executable (pcd2txt src/pcd2txt.cpp) #注意这里不能替换


target_link_libraries(pcd2txt ${PCL_LIBRARIES})









