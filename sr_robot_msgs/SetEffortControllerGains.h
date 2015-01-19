#ifndef _ROS_SERVICE_SetEffortControllerGains_h
#define _ROS_SERVICE_SetEffortControllerGains_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_robot_msgs
{

static const char SETEFFORTCONTROLLERGAINS[] = "sr_robot_msgs/SetEffortControllerGains";

  class SetEffortControllerGainsRequest : public ros::Msg
  {
    public:
      float max_force;
      int32_t friction_deadband;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->max_force);
      union {
        int32_t real;
        uint32_t base;
      } u_friction_deadband;
      u_friction_deadband.real = this->friction_deadband;
      *(outbuffer + offset + 0) = (u_friction_deadband.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_friction_deadband.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_friction_deadband.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_friction_deadband.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->friction_deadband);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_force));
      union {
        int32_t real;
        uint32_t base;
      } u_friction_deadband;
      u_friction_deadband.base = 0;
      u_friction_deadband.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_friction_deadband.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_friction_deadband.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_friction_deadband.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->friction_deadband = u_friction_deadband.real;
      offset += sizeof(this->friction_deadband);
     return offset;
    }

    const char * getType(){ return SETEFFORTCONTROLLERGAINS; };
    const char * getMD5(){ return "96397d148b84b1d0a8fe84ee1744fece"; };

  };

  class SetEffortControllerGainsResponse : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SETEFFORTCONTROLLERGAINS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetEffortControllerGains {
    public:
    typedef SetEffortControllerGainsRequest Request;
    typedef SetEffortControllerGainsResponse Response;
  };

}
#endif
