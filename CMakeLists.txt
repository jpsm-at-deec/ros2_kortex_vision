cmake_minimum_required(VERSION 3.12)

project(ros_kortex_vision)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

# System Dependencies
#find_package(PkgConfig)
find_package(PkgConfig REQUIRED)

#pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)
#lpkg_check_modules(GST_APP REQUIRED gstreamer-app-1.0)

pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)
pkg_check_modules(GST_APP REQUIRED gstreamer-app-1.0)

# \begin{wally}
#set(THIS_PACKAGE_INCLUDE_DEPENDS
#  image_transport
#  sensor_msgs
#  camera_calibration_parsers
#  camera_info_manager
#  tf
#)

#roscpp image_transport sensor_msgs nodelet
  #camera_calibration_parsers camera_info_manager tf
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

find_package(image_transport REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(camera_calibration_parsers REQUIRED)
find_package(camera_info_manager REQUIRED)



#set(node_plugins "")

#find_package(rclcpp REQUIRED)
#find_package(image_transport REQUIRED)
#find_package(sensor_msgs REQUIRED)
#find_package(camera_calibration_parsers REQUIRED)
#find_package(camera_info_manager REQUIRED)
#find_package(tf REQUIRED)
#foreach(Dependency IN ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS})
#  find_package(${Dependency} REQUIRED)
#endforeach()
# \end{wally}

# Use Catkin
#find_package(catkin REQUIRED
#  COMPONENTS roscpp image_transport sensor_msgs nodelet
#  camera_calibration_parsers camera_info_manager tf
#  )

#catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES KinovaVision
#  CATKIN_DEPENDS roscpp nodelet image_transport sensor_msgs
# camera_calibration_parsers camera_info_manager
#  DEPENDS GSTREAMER GST_APP
#  )

#include_directories(
#  include
#  ${catkin_INCLUDE_DIRS}
#  ${GLIB_INCLUDE_DIRS}
#  ${GST_APP_INCLUDE_DIRS})

#add_library(ros_kortex_vision src/vision.cpp)
#target_link_libraries(ros_kortex_vision
#  ${catkin_LIBRARIES}
#  ${GSTREAMER_LIBRARIES}
#  ${GST_APP_LIBRARIES})

#add_executable(ros_kortex_vision_node src/vision_node.cpp)
#target_link_libraries(ros_kortex_vision_node ros_kortex_vision
#  ${catkin_LIBRARIES}
#  ${GSTREAMER_LIBRARIES}
#  ${GST_APP_LIBRARIES})

#configure header files to pass the version number to the source code (must add target_include_directories to the end of CMakeLists.txt)
#configure_file(car.h modelX.h upgrade.h Usage.h)
#set target build
#target_include_directories(Car Public "${PROJECT_BINARY_DIR}") 

# A library to detect a realtime kernel and set thread priority, if one is found
add_library(ros_kortex_vision src/vision.cpp)
add_executable(ros_kortex_vision_node src/vision_node.cpp)
target_compile_features(ros_kortex_vision PUBLIC cxx_std_17)
target_include_directories(ros_kortex_vision PUBLIC
  ${PROJECT_SOURCE_DIR}/include
  include/ros_kortex_vision
  ${GSTREAMER_INCLUDE_DIRECTORIES}
  ${GST_APP_LIBRARIES}
)
target_link_libraries(ros_kortex_vision_node ros_kortex_vision
  ${GSTREAMER_LIBRARIES}
  ${GST_APP_LIBRARIES}
  #rclcpp::rclcpp
  #PkgConfig::GSTREAMER
  #PkgConfig::GST_APP
)

#set_target_properties(ros_kortex_vision_node PROPERTIES OUTPUT_NAME ros_kortex_vision)

#target_include_directories(ros_kortex_vision PUBLIC
# "${GSTREAMER_INCLUDE_DIRECTORIES}")


#ament_target_dependencies(ros_kortex_vision rclcpp)
#ament_target_dependencies(ros_kortex_vision PkgConfig::GSTREAMER)
#ament_target_dependencies(ros_kortex_vision PUBLIC ${THIS_PACKAGE_INCLUDE_DEPENDS})

#ament_export_include_directories(include/ros_kortex_vision)
ament_target_dependencies(ros_kortex_vision
  rclcpp
  std_msgs
  image_transport
  camera_info_manager
  sensor_msgs
  camera_calibration_parsers
  GSTREAMER
  GST_APP)
ament_package()

# Install
install(
  DIRECTORY include/
  DESTINATION include/ros_kortex_vision
)
#install(TARGETS ros_kortex_vision ros_kortex_vision_node
#wally   EXPORT export_ros_kortex_vision
#wally   ARCHIVE DESTINATION lib
#wally   LIBRARY DESTINATION lib
#wally   RUNTIME DESTINATION bin
#wally )
#wally install(
#wally   DIRECTORY launch/calibration
#wally   DESTINATION share/launch
#wally   FILES_MATCHING PATTERN "*.ini"
#wally )

# Install directives
#install(TARGETS ros_kortex_vision ros_kortex_vision_node
#  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
#)

#install(DIRECTORY include/
#  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#  PATTERN ".svn" EXCLUDE)

#install(DIRECTORY launch/calibration
#  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
#  FILES_MATCHING PATTERN "*.ini"
#  )

#set(CMAKE_CXX_FLAGS "-fpermissive")

#ament_export_targets(ros_kortex_vision HAS_LIBRARY_TARGET)
#ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
#ament_package()