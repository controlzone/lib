#ifndef _ROS_saphari_msgs_Equipment_h
#define _ROS_saphari_msgs_Equipment_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace saphari_msgs
{

  class Equipment : public ros::Msg
  {
    public:
      int8_t ID;
      geometry_msgs::PoseStamped pose;
      enum { BOWL = 0 };
      enum { CLAMP_BIG = 1 };
      enum { CLAMP_SMALL = 2 };
      enum { SCALPEL = 3 };
      enum { SCISSORS = 4 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_ID;
      u_ID.real = this->ID;
      *(outbuffer + offset + 0) = (u_ID.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ID);
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_ID;
      u_ID.base = 0;
      u_ID.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ID = u_ID.real;
      offset += sizeof(this->ID);
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "saphari_msgs/Equipment"; };
    const char * getMD5(){ return "302c5bcc9b507a3d589f9d9bf8207816"; };

  };

}
#endif