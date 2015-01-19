#ifndef _ROS_sr_robot_msgs_joint_h
#define _ROS_sr_robot_msgs_joint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_robot_msgs
{

  class joint : public ros::Msg
  {
    public:
      const char* joint_name;
      float joint_position;
      float joint_target;
      float joint_torque;
      float joint_temperature;
      float joint_current;
      const char* error_flag;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_joint_name = strlen(this->joint_name);
      memcpy(outbuffer + offset, &length_joint_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->joint_name, length_joint_name);
      offset += length_joint_name;
      offset += serializeAvrFloat64(outbuffer + offset, this->joint_position);
      offset += serializeAvrFloat64(outbuffer + offset, this->joint_target);
      offset += serializeAvrFloat64(outbuffer + offset, this->joint_torque);
      offset += serializeAvrFloat64(outbuffer + offset, this->joint_temperature);
      offset += serializeAvrFloat64(outbuffer + offset, this->joint_current);
      uint32_t length_error_flag = strlen(this->error_flag);
      memcpy(outbuffer + offset, &length_error_flag, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->error_flag, length_error_flag);
      offset += length_error_flag;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_joint_name;
      memcpy(&length_joint_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_joint_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_joint_name-1]=0;
      this->joint_name = (char *)(inbuffer + offset-1);
      offset += length_joint_name;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->joint_position));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->joint_target));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->joint_torque));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->joint_temperature));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->joint_current));
      uint32_t length_error_flag;
      memcpy(&length_error_flag, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error_flag; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error_flag-1]=0;
      this->error_flag = (char *)(inbuffer + offset-1);
      offset += length_error_flag;
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/joint"; };
    const char * getMD5(){ return "4f0c5e71dfc214020935c3116ed47d6f"; };

  };

}
#endif