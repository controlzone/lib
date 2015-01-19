#ifndef _ROS_SERVICE_ChangeControlType_h
#define _ROS_SERVICE_ChangeControlType_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sr_robot_msgs/ControlType.h"

namespace sr_robot_msgs
{

static const char CHANGECONTROLTYPE[] = "sr_robot_msgs/ChangeControlType";

  class ChangeControlTypeRequest : public ros::Msg
  {
    public:
      sr_robot_msgs::ControlType control_type;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->control_type.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->control_type.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return CHANGECONTROLTYPE; };
    const char * getMD5(){ return "36741247c0d6032654e8e0ef56e7670f"; };

  };

  class ChangeControlTypeResponse : public ros::Msg
  {
    public:
      sr_robot_msgs::ControlType result;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return CHANGECONTROLTYPE; };
    const char * getMD5(){ return "2a6d00c524e195eb671dbbbb7783aee1"; };

  };

  class ChangeControlType {
    public:
    typedef ChangeControlTypeRequest Request;
    typedef ChangeControlTypeResponse Response;
  };

}
#endif
