#include "voxelGrid/voxelGrid.h"
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>

VoxelGrid::VoxelGrid(const ros::NodeHandle &nh, const ros::NodeHandle &nh_private){
    nh_ = nh;
    nh_private_ = nh_private;

    pointCloud2_pub_ = nh_private_.advertise<sensor_msgs::PointCloud2>("PointCloud2", 1);
    pointCloud2_sub_ = nh_private_.subscribe("/ouster/points", 1, &VoxelGrid::filter_pointcloud2_callback, this);

}

void VoxelGrid::filter_pointcloud2_callback(const sensor_msgs::PointCloud2ConstPtr &msg){
    
    // Convert std pointcloud2 to pcl pointcloud
    pcl::PCLPointCloud2::Ptr raw_cloud(new pcl::PCLPointCloud2());
    pcl_conversions::toPCL(*msg, *raw_cloud);
    
    // Make container for the filtered data
    pcl::PCLPointCloud2::Ptr filtered_cloud(new pcl::PCLPointCloud2());

    // Execute filtering
    pcl::VoxelGrid<pcl::PCLPointCloud2> voxel_filter;
    voxel_filter.setInputCloud(raw_cloud);
    voxel_filter.setLeafSize(0.2f, 0.2f, 0.2f);
    voxel_filter.filter(*filtered_cloud);


    sensor_msgs::PointCloud2 filtered_cloud_msg;
    pcl_conversions::moveFromPCL(*filtered_cloud, filtered_cloud_msg);
    pointCloud2_pub_.publish(filtered_cloud_msg);

}
