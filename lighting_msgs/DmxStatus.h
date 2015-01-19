#ifndef _ROS_lighting_msgs_DmxStatus_h
#define _ROS_lighting_msgs_DmxStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace lighting_msgs
{

  class DmxStatus : public ros::Msg
  {
    public:
      int16_t frameRate;
      int16_t command_count;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_frameRate;
      u_frameRate.real = this->frameRate;
      *(outbuffer + offset + 0) = (u_frameRate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_frameRate.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->frameRate);
      union {
        int16_t real;
        uint16_t base;
      } u_command_count;
      u_command_count.real = this->command_count;
      *(outbuffer + offset + 0) = (u_command_count.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_command_count.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->command_count);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_frameRate;
      u_frameRate.base = 0;
      u_frameRate.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_frameRate.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->frameRate = u_frameRate.real;
      offset += sizeof(this->frameRate);
      union {
        int16_t real;
        uint16_t base;
      } u_command_count;
      u_command_count.base = 0;
      u_command_count.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_command_count.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->command_count = u_command_count.real;
      offset += sizeof(this->command_count);
     return offset;
    }

    const char * getType(){ return "lighting_msgs/DmxStatus"; };
    const char * getMD5(){ return "6b6b27ecb16c4c904006b90c891fdc8d"; };

  };

}
#endif