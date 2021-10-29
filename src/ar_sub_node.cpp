#include <ros/ros.h>
#include "fiducial_msgs/FiducialTransformArray.h"
void aruco_transform(const fiducial_msgs::FiducialTransformArray &msg)
{
    // ROS_INFO("HEADER");
    // ROS_INFO("seq : %d", msg.header.seq);
    // ROS_INFO("stamp sec : %d", msg.header.stamp.sec);
    // ROS_INFO("stamp nsec : %d", msg.header.stamp.nsec);
    // ROS_INFO("frame_id : %s", msg.header.frame_id.c_str());

    // ROS_INFO("image_seq : %d", msg.image_seq);
    
    for(int i=0; i<msg.transforms.size(); i++){
        ROS_INFO("fiducial_id : %d", msg.transforms[i].fiducial_id);
        ROS_INFO("Tranlation");
        ROS_INFO("x : %f", msg.transforms[i].transform.translation.x);
        ROS_INFO("y : %f", msg.transforms[i].transform.translation.y);
        ROS_INFO("z : %f", msg.transforms[i].transform.translation.z);

        ROS_INFO("Rotation");
        ROS_INFO("x : %f", msg.transforms[i].transform.rotation.x);
        ROS_INFO("y : %f", msg.transforms[i].transform.rotation.y);
        ROS_INFO("z : %f", msg.transforms[i].transform.rotation.z);
        ROS_INFO("w : %f", msg.transforms[i].transform.rotation.w);
    }

}
int main(int argc, char** argv)
{
    ros::init(argc, argv, "ar_sub_node");
    ros::NodeHandle nh;
    
    ros::Subscriber sub_number = nh.subscribe("/fiducial_transforms", 10, aruco_transform);
    
    ros::spin();
}