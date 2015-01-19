#ifndef _ROS_sr_robot_msgs_ControlType_h
#define _ROS_sr_robot_msgs_ControlType_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_robot_msgs
{

  class ControlType : public ros::Msg
  {
    public:
      int16_t control_type;
      enum { PWM = 0 };
      enum { FORCE = 1 };
      enum { QUERY = -1 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_control_type;
      u_control_type.real = this->control_type;
      *(outbuffer + offset + 0) = (u_control_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_control_type.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->control_type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_control_type;
      u_control_type.base = 0;
      u_control_type.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_control_type.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->control_type = u_control_type.real;
      offset += sizeof(this->control_type);
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/ControlType"; };
    const char * getMD5(){ return "b998c8b3b8aa0f2f53f0eaa45ee462bd"; };

  };

}
#endif