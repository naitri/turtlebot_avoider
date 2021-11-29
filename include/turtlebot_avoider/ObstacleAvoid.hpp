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
#ifndef INCLUDE_TURTLEBOT_AVOIDER_OBSTACLEAVOID_HPP_
#define INCLUDE_TURTLEBOT_AVOIDER_OBSTACLEAVOID_HPP_

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>

class ObstacleAvoid {
 public:
    /**
     * @brief ObstacleAvoid class constructor
     * 
     * @param ros node handle
     * @param const double dist
     */
    explicit ObstacleAvoid(ros::NodeHandle node_handle, const double dist = 1);

    /**
     * @brief ObstacleAvoid class destructor
     * 
     */
    ~ObstacleAvoid();


 private:
    /**
     * @brief laser scan callback method
     * 
     * @param scan_data 
     * 
     * @return Void
     * 
     */
    void callback(const sensor_msgs::LaserScan::ConstPtr& scan_msg);


 private:
    /**
     * @brief ros node handle for ObstacleAvoider class
     * 
     */

    ros::NodeHandle nh;

    /**
     * @brief distance to avoid collision
     * 
     */
    double collision_dist;  // meteres

    /**
     * @brief velocity Publisher
     * 
     */
    ros::Publisher vel_pub;

    /**
     * @brief laser scan Subscriber
     * 
     */
    ros::Subscriber scan_pub;
};

#endif  // INCLUDE_TURTLEBOT_AVOIDER_OBSTACLEAVOID_HPP_
