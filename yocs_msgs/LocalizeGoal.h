#ifndef _ROS_yocs_msgs_LocalizeGoal_h
#define _ROS_yocs_msgs_LocalizeGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace yocs_msgs
{

  class LocalizeGoal : public ros::Msg
  {
    public:
      int8_t command;
      enum { STAND_AND_LOCALIZE = 10 };
      enum { SPIN_AND_LOCALIZE = 20 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_command;
      u_command.real = this->command;
      *(outbuffer + offset + 0) = (u_command.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_command;
      u_command.base = 0;
      u_command.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->command = u_command.real;
      offset += sizeof(this->command);
     return offset;
    }

    const char * getType(){ return "yocs_msgs/LocalizeGoal"; };
    const char * getMD5(){ return "110cc0391fcfddf08ebaf77f192108ec"; };

  };

}
#endif