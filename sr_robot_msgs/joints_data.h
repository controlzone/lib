#ifndef _ROS_sr_robot_msgs_joints_data_h
#define _ROS_sr_robot_msgs_joints_data_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sr_robot_msgs/joint.h"

namespace sr_robot_msgs
{

  class joints_data : public ros::Msg
  {
    public:
      int8_t joints_list_length;
      uint8_t joints_list_length;
      sr_robot_msgs::joint st_joints_list;
      sr_robot_msgs::joint * joints_list;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_joints_list_length;
      u_joints_list_length.real = this->joints_list_length;
      *(outbuffer + offset + 0) = (u_joints_list_length.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->joints_list_length);
      *(outbuffer + offset++) = joints_list_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joints_list_length; i++){
      offset += this->joints_list[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_joints_list_length;
      u_joints_list_length.base = 0;
      u_joints_list_length.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->joints_list_length = u_joints_list_length.real;
      offset += sizeof(this->joints_list_length);
      uint8_t joints_list_lengthT = *(inbuffer + offset++);
      if(joints_list_lengthT > joints_list_length)
        this->joints_list = (sr_robot_msgs::joint*)realloc(this->joints_list, joints_list_lengthT * sizeof(sr_robot_msgs::joint));
      offset += 3;
      joints_list_length = joints_list_lengthT;
      for( uint8_t i = 0; i < joints_list_length; i++){
      offset += this->st_joints_list.deserialize(inbuffer + offset);
        memcpy( &(this->joints_list[i]), &(this->st_joints_list), sizeof(sr_robot_msgs::joint));
      }
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/joints_data"; };
    const char * getMD5(){ return "a7bd94657f253c468247048a545e88e5"; };

  };

}
#endif