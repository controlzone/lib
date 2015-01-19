#ifndef _ROS_SERVICE_SetPidGains_h
#define _ROS_SERVICE_SetPidGains_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_robot_msgs
{

static const char SETPIDGAINS[] = "sr_robot_msgs/SetPidGains";

  class SetPidGainsRequest : public ros::Msg
  {
    public:
      float p;
      float i;
      float d;
      float i_clamp;
      float max_force;
      float deadband;
      int32_t friction_deadband;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->p);
      offset += serializeAvrFloat64(outbuffer + offset, this->i);
      offset += serializeAvrFloat64(outbuffer + offset, this->d);
      offset += serializeAvrFloat64(outbuffer + offset, this->i_clamp);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_force);
      offset += serializeAvrFloat64(outbuffer + offset, this->deadband);
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->p));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->i));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->d));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->i_clamp));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_force));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->deadband));
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

    const char * getType(){ return SETPIDGAINS; };
    const char * getMD5(){ return "f9c5176e998bba30344c4892f975be3a"; };

  };

  class SetPidGainsResponse : public ros::Msg
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

    const char * getType(){ return SETPIDGAINS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetPidGains {
    public:
    typedef SetPidGainsRequest Request;
    typedef SetPidGainsResponse Response;
  };

}
#endif
