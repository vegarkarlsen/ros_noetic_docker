#ifndef VOXELGRID_H
#define VOXELGRID_H


#include <ros/ros.h>
// #include <pcl_ros/point_cloud.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl_conversions/pcl_conversions.h>

class VoxelGrid{
    public:
        VoxelGrid(const ros::NodeHandle &nh, const ros::NodeHandle &nh_private);
        void filter_pointcloud2_callback(const sensor_msgs::PointCloud2ConstPtr &msg);

    private:
        ros::NodeHandle nh_;
        ros::NodeHandle nh_private_;

        ros::Publisher pointCloud2_pub_;
        ros::Subscriber pointCloud2_sub_;
};


#endif // !VOXELGRID_H
