<<<<<<< HEAD
# ros_obstacle_avoider
=======
# ros_obstacle_avoider
ros_obstacle_avoider is a turtlebot3 based robot capable of avoiding obstacles at a certain predefined distance using laser.
It does support level 1 and level2 unit testing.

# Dependencies
* Ubuntu 20.04
* ROS Noetic
* ROS TurtleBot3 Package
* Gazebo

## Installing TurtleBot3 package
```
cd ~/ros_avoider_ws/src
git clone https://github.com/ROBOTIS-GIT/turtlebot3_msgs.git -b noetic-devel
git clone https://github.com/ROBOTIS-GIT/turtlebot3.git -b noetic-devel
git clone https://github.com/ROBOTIS-GIT/turtlebot3_simulations.git -b noetic-devel
cd ~/roomba_ws
catkin_make
source devel/setup.bash
```

## Build Instructions
```
cd ~/ros_avoider_ws/src
git clone https://github.com/naitri/ros_obstacle_avoider.git
cd ~/roomba_ws
catkin_make
source devel/setup.bash
```

## Run Instructions with launch file
 Launch ros_obstacle_avoider with launch file without rosbag reocrding
```
roslaunch turtlebot_avoider turtlebot_avoider.launch
```
 Launch ros_obstacle_avoider with launch file with rosbag reocrding
```
roslaunch turtlebot_avoider turtlebot_avoider.launch bag:=true
```
## Run Instructions with rosrun
In terminal 1
```
cd ~/ros_avoider_ws
source devel/setup.bash
roslaunch turtleBot3_gazebo turtleBot3_house.launch
```
In terminal 2
```
cd ~/ros_avoider_ws
source devel/setup.bash
rosrun turtlebot_avoider ros_obstacle_avoider
```
## ROS Bag 
* To play rosbag without launching of gazebo
```
roslaunch turtlebot_avoider turtlebot_avoider.launch gazebo:=false
```
* Play the recorded ros bag
```
rosbag play record_rosbag_2021-11-29-12-52-46.bag
```
* Checking rosbag details
```rosbag info record_rosbag_2021-11-29-12-52-46.bag 
path:        record_rosbag_2021-11-29-12-52-46.bag
version:     2.0
duration:    15.0s
start:       Dec 31 1969 19:00:00.19 (0.19)
end:         Dec 31 1969 19:00:15.16 (15.16)
size:        77.0 MB
messages:    139653
compression: none [101/101 chunks]
types:       dynamic_reconfigure/Config            [958f16a05573709014982821e6822580]
             dynamic_reconfigure/ConfigDescription [757ce9d44ba8ddd801bb30bc456f946f]
             gazebo_msgs/LinkStates                [48c080191eb15c41858319b4d8a609c2]
             gazebo_msgs/ModelStates               [48c080191eb15c41858319b4d8a609c2]
             gazebo_msgs/PerformanceMetrics        [884f71fd5037b886ec5e126b83c4425a]
             geometry_msgs/Twist                   [9f195f881246fdfa2798d1d3eebca84a]
             nav_msgs/Odometry                     [cd5e73d190d741a2f92e81eda573aca7]
             rosgraph_msgs/Clock                   [a9c97c1d230cfc112e270351a944ee47]
             rosgraph_msgs/Log                     [acffd30cd6b6de30f120938c17c593fb]
             sensor_msgs/Imu                       [6a62c6daae103f4ff57a132d6f95cec2]
             sensor_msgs/JointState                [3066dcd76a6cfaef579bd0f34173e9fd]
             sensor_msgs/LaserScan                 [90c7ef2dc6895d81024acba2ac42f369]
             tf2_msgs/TFMessage                    [94810edda583a504dfda3829e70d7eec]
topics:      /clock                           14990 msgs    : rosgraph_msgs/Clock                  
             /cmd_vel                         26278 msgs    : geometry_msgs/Twist                  
             /gazebo/link_states              14936 msgs    : gazebo_msgs/LinkStates               
             /gazebo/model_states             14949 msgs    : gazebo_msgs/ModelStates              
             /gazebo/parameter_descriptions       1 msg     : dynamic_reconfigure/ConfigDescription
             /gazebo/parameter_updates            1 msg     : dynamic_reconfigure/Config           
             /gazebo/performance_metrics         76 msgs    : gazebo_msgs/PerformanceMetrics       
             /imu                             13822 msgs    : sensor_msgs/Imu                      
             /joint_states                      415 msgs    : sensor_msgs/JointState               
             /odom                              415 msgs    : nav_msgs/Odometry                    
             /rosout                          26634 msgs    : rosgraph_msgs/Log                     (3 connections)
             /rosout_agg                      26652 msgs    : rosgraph_msgs/Log                    
             /scan                               69 msgs    : sensor_msgs/LaserScan                
             /tf                                415 msgs    : tf2_msgs/TFMessage
```
>>>>>>> c6f30be0c1410c4988d96f519edd878e01334d0b
