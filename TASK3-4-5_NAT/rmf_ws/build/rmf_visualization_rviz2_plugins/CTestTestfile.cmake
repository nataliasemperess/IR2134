# CMake generated Testfile for 
# Source directory: /home/usuario/rmf_ws/src/rmf_visualization_rviz2_plugins
# Build directory: /home/usuario/rmf_ws/build/rmf_visualization_rviz2_plugins
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(uncrustify "/usr/bin/python3" "-u" "/opt/ros/jazzy/share/ament_cmake_test/cmake/run_test.py" "/home/usuario/rmf_ws/build/rmf_visualization_rviz2_plugins/test_results/rmf_visualization_rviz2_plugins/uncrustify.xunit.xml" "--package-name" "rmf_visualization_rviz2_plugins" "--output-file" "/home/usuario/rmf_ws/build/rmf_visualization_rviz2_plugins/ament_uncrustify/uncrustify.txt" "--command" "/opt/ros/jazzy/bin/ament_uncrustify" "--xunit-file" "/home/usuario/rmf_ws/build/rmf_visualization_rviz2_plugins/test_results/rmf_visualization_rviz2_plugins/uncrustify.xunit.xml" "--linelength" "80" "-c" "/rmf_demos_ws/install/rmf_utils/share/rmf_utils/rmf_code_style.cfg" "ARGN" "src")
set_tests_properties(uncrustify PROPERTIES  LABELS "uncrustify;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/usuario/rmf_ws/src/rmf_visualization_rviz2_plugins" _BACKTRACE_TRIPLES "/opt/ros/jazzy/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/jazzy/share/ament_cmake_uncrustify/cmake/ament_uncrustify.cmake;85;ament_add_test;/home/usuario/rmf_ws/src/rmf_visualization_rviz2_plugins/CMakeLists.txt;43;ament_uncrustify;/home/usuario/rmf_ws/src/rmf_visualization_rviz2_plugins/CMakeLists.txt;0;")
