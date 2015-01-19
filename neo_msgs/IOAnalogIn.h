#ifndef _ROS_neo_msgs_IOAnalogIn_h
#define _ROS_neo_msgs_IOAnalogIn_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace neo_msgs
{

  class IOAnalogIn : public ros::Msg
  {
    public:
      int16_t input[8];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 8; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_inputi;
      u_inputi.real = this->input[i];
      *(outbuffer + offset + 0) = (u_inputi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_inputi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->input[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 8; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_inputi;
      u_inputi.base = 0;
      u_inputi.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_inputi.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->input[i] = u_inputi.real;
      offset += sizeof(this->input[i]);
      }
     return offset;
    }

    const char * getType(){ return "neo_msgs/IOAnalogIn"; };
    const char * getMD5(){ return "4b0e4815c9bd4f4b74f05fb5691e16a6"; };

  };

}
#endif