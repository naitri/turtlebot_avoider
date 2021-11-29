/**
 * MIT License
 *
 * Copyright (c) 2021 Naitri Rajyaguru
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 * @file ObstacleAvoid.hpp
 * @author Naitri Rajyaguru
 * @version 0.1
 * @date 2021-11-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
#include <map>
#include<string>
#include <turtlebot_avoider/ObstacleAvoid.hpp>
ObstacleAvoid::ObstacleAvoid(ros::NodeHandle nh, const double dist) :
nh(nh), collision_dist(dist) {
    vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
    ros::Rate loop_rate(10);
    scan_pub = nh.subscribe("/scan", 10 , &ObstacleAvoid::callback, this);
    ros::spinOnce();
}

ObstacleAvoid::~ObstacleAvoid() {
}

void ObstacleAvoid::callback(const sensor_msgs::LaserScan::
    ConstPtr & laser_msg) {
    geometry_msgs::Twist vel_cmd;
    for ( int i = 0; i < laser_msg->ranges.size() ; i++ ) {
        if (laser_msg->ranges[i] < 0.5 || laser_msg->ranges[359-i] < 0.5) {
            vel_cmd.linear.x = 0;
            vel_cmd.linear.y = 0;
            vel_cmd.linear.z = 0;
            vel_cmd.angular.x = 0;
            vel_cmd.angular.y = 0;
            vel_cmd.angular.z = 0.5;
            ROS_INFO_STREAM("Obstacle detected...turning");
        } else {
            vel_cmd.linear.x = 0.5;
            vel_cmd.linear.y = 0;
            vel_cmd.linear.z = 0;
            vel_cmd.angular.x = 0;
            vel_cmd.angular.y = 0;
            vel_cmd.angular.z = 0;
            ROS_INFO_STREAM("No Obstacle detected...moving forward");
        }
        vel_pub.publish(vel_cmd);
    }
}

