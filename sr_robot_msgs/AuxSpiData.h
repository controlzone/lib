#ifndef _ROS_sr_robot_msgs_AuxSpiData_h
#define _ROS_sr_robot_msgs_AuxSpiData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace sr_robot_msgs
{

  class AuxSpiData : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint16_t sensors[16];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 16; i++){
      *(outbuffer + offset + 0) = (this->sensors[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sensors[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sensors[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 16; i++){
      this->sensors[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->sensors[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->sensors[i]);
      }
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/AuxSpiData"; };
    const char * getMD5(){ return "0be98a0e10e956b06a48167fcb32ca84"; };

  };

}
#endif