cmake_minimum_required(VERSION 3.0.2)
#set(project_name cloud_viewer_PointXYZ)
project(txt2pcd)
find_package(PCL 1.8.0 REQUIRED)



include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})




add_executable (txt2pcd src/txt2pcd.cpp) #注意这里不能替换



target_link_libraries(txt2pcd ${PCL_LIBRARIES})



