#ifndef _ROS_jsk_footstep_msgs_Footstep_h
#define _ROS_jsk_footstep_msgs_Footstep_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "ros/duration.h"
#include "geometry_msgs/Vector3.h"

namespace jsk_footstep_msgs
{

  class Footstep : public ros::Msg
  {
    public:
      uint8_t leg;
      geometry_msgs::Pose pose;
      ros::Duration duration;
      uint32_t footstep_group;
      geometry_msgs::Vector3 dimensions;
      enum { RIGHT = 2 };
      enum { LEFT = 1 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->leg >> (8 * 0)) & 0xFF;
      offset += sizeof(this->leg);
      offset += this->pose.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->duration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->duration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->duration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->duration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration.sec);
      *(outbuffer + offset + 0) = (this->duration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->duration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->duration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->duration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration.nsec);
      *(outbuffer + offset + 0) = (this->footstep_group >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->footstep_group >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->footstep_group >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->footstep_group >> (8 * 3)) & 0xFF;
      offset += sizeof(this->footstep_group);
      offset += this->dimensions.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->leg =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->leg);
      offset += this->pose.deserialize(inbuffer + offset);
      this->duration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->duration.sec);
      this->duration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->duration.nsec);
      this->footstep_group =  ((uint32_t) (*(inbuffer + offset)));
      this->footstep_group |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->footstep_group |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->footstep_group |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->footstep_group);
      offset += this->dimensions.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "jsk_footstep_msgs/Footstep"; };
    const char * getMD5(){ return "eaa8587f19d8934a6cd43884869af59e"; };

  };

}
#endif