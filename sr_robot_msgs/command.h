#ifndef _ROS_sr_robot_msgs_command_h
#define _ROS_sr_robot_msgs_command_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sr_robot_msgs/sendupdate.h"
#include "sr_robot_msgs/contrlr.h"

namespace sr_robot_msgs
{

  class command : public ros::Msg
  {
    public:
      int8_t command_type;
      sr_robot_msgs::sendupdate sendupdate_command;
      sr_robot_msgs::contrlr contrlr_command;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_command_type;
      u_command_type.real = this->command_type;
      *(outbuffer + offset + 0) = (u_command_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command_type);
      offset += this->sendupdate_command.serialize(outbuffer + offset);
      offset += this->contrlr_command.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_command_type;
      u_command_type.base = 0;
      u_command_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->command_type = u_command_type.real;
      offset += sizeof(this->command_type);
      offset += this->sendupdate_command.deserialize(inbuffer + offset);
      offset += this->contrlr_command.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/command"; };
    const char * getMD5(){ return "2c927cc3decc25060b43219a05beb823"; };

  };

}
#endif