#ifndef _ROS_SERVICE_dmx_command_h
#define _ROS_SERVICE_dmx_command_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "lighting_msgs/DmxCommand.h"

namespace lighting_msgs
{

static const char DMX_COMMAND[] = "lighting_msgs/dmx_command";

  class dmx_commandRequest : public ros::Msg
  {
    public:
      lighting_msgs::DmxCommand command;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->command.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->command.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return DMX_COMMAND; };
    const char * getMD5(){ return "85cbb01fbbfc8ce5f4da920af4f775a5"; };

  };

  class dmx_commandResponse : public ros::Msg
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

    const char * getType(){ return DMX_COMMAND; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class dmx_command {
    public:
    typedef dmx_commandRequest Request;
    typedef dmx_commandResponse Response;
  };

}
#endif
