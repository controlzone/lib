#ifndef _ROS_SERVICE_SetSpeed_h
#define _ROS_SERVICE_SetSpeed_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dynamixel_controllers
{

static const char SETSPEED[] = "dynamixel_controllers/SetSpeed";

  class SetSpeedRequest : public ros::Msg
  {
    public:
      float speed;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->speed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->speed));
     return offset;
    }

    const char * getType(){ return SETSPEED; };
    const char * getMD5(){ return "4641bb0523a3557209606d9bd91ce33a"; };

  };

  class SetSpeedResponse : public ros::Msg
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

    const char * getType(){ return SETSPEED; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetSpeed {
    public:
    typedef SetSpeedRequest Request;
    typedef SetSpeedResponse Response;
  };

}
#endif
