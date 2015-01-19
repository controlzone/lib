#ifndef _ROS_sr_robot_msgs_UBI0_h
#define _ROS_sr_robot_msgs_UBI0_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_robot_msgs
{

  class UBI0 : public ros::Msg
  {
    public:
      uint16_t distal[12];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 12; i++){
      *(outbuffer + offset + 0) = (this->distal[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->distal[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->distal[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 12; i++){
      this->distal[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->distal[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->distal[i]);
      }
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/UBI0"; };
    const char * getMD5(){ return "f8ba754182dd029f486767184963c485"; };

  };

}
#endif