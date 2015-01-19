#ifndef _ROS_neo_msgs_IOOut_h
#define _ROS_neo_msgs_IOOut_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace neo_msgs
{

  class IOOut : public ros::Msg
  {
    public:
      int16_t channel;
      bool active;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_channel;
      u_channel.real = this->channel;
      *(outbuffer + offset + 0) = (u_channel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_channel.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->channel);
      union {
        bool real;
        uint8_t base;
      } u_active;
      u_active.real = this->active;
      *(outbuffer + offset + 0) = (u_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->active);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_channel;
      u_channel.base = 0;
      u_channel.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_channel.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->channel = u_channel.real;
      offset += sizeof(this->channel);
      union {
        bool real;
        uint8_t base;
      } u_active;
      u_active.base = 0;
      u_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->active = u_active.real;
      offset += sizeof(this->active);
     return offset;
    }

    const char * getType(){ return "neo_msgs/IOOut"; };
    const char * getMD5(){ return "894ccc9cba8043db3f885fa5ca0edd62"; };

  };

}
#endif