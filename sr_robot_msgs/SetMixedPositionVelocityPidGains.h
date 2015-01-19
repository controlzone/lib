#ifndef _ROS_SERVICE_SetMixedPositionVelocityPidGains_h
#define _ROS_SERVICE_SetMixedPositionVelocityPidGains_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_robot_msgs
{

static const char SETMIXEDPOSITIONVELOCITYPIDGAINS[] = "sr_robot_msgs/SetMixedPositionVelocityPidGains";

  class SetMixedPositionVelocityPidGainsRequest : public ros::Msg
  {
    public:
      float position_p;
      float position_i;
      float position_d;
      float position_i_clamp;
      float min_velocity;
      float max_velocity;
      float position_deadband;
      float velocity_p;
      float velocity_i;
      float velocity_d;
      float velocity_i_clamp;
      float max_force;
      int32_t friction_deadband;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->position_p);
      offset += serializeAvrFloat64(outbuffer + offset, this->position_i);
      offset += serializeAvrFloat64(outbuffer + offset, this->position_d);
      offset += serializeAvrFloat64(outbuffer + offset, this->position_i_clamp);
      offset += serializeAvrFloat64(outbuffer + offset, this->min_velocity);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_velocity);
      offset += serializeAvrFloat64(outbuffer + offset, this->position_deadband);
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity_p);
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity_i);
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity_d);
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity_i_clamp);
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position_p));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position_i));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position_d));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position_i_clamp));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min_velocity));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_velocity));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position_deadband));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velocity_p));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velocity_i));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velocity_d));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velocity_i_clamp));
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

    const char * getType(){ return SETMIXEDPOSITIONVELOCITYPIDGAINS; };
    const char * getMD5(){ return "ff95ce4d442c9454d3d943f0c999da89"; };

  };

  class SetMixedPositionVelocityPidGainsResponse : public ros::Msg
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

    const char * getType(){ return SETMIXEDPOSITIONVELOCITYPIDGAINS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetMixedPositionVelocityPidGains {
    public:
    typedef SetMixedPositionVelocityPidGainsRequest Request;
    typedef SetMixedPositionVelocityPidGainsResponse Response;
  };

}
#endif
