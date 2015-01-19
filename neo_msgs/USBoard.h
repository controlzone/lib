#ifndef _ROS_neo_msgs_USBoard_h
#define _ROS_neo_msgs_USBoard_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace neo_msgs
{

  class USBoard : public ros::Msg
  {
    public:
      uint8_t sensor[16];
      int16_t analog[4];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 16; i++){
      *(outbuffer + offset + 0) = (this->sensor[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor[i]);
      }
      for( uint8_t i = 0; i < 4; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_analogi;
      u_analogi.real = this->analog[i];
      *(outbuffer + offset + 0) = (u_analogi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_analogi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->analog[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 16; i++){
      this->sensor[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sensor[i]);
      }
      for( uint8_t i = 0; i < 4; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_analogi;
      u_analogi.base = 0;
      u_analogi.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_analogi.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->analog[i] = u_analogi.real;
      offset += sizeof(this->analog[i]);
      }
     return offset;
    }

    const char * getType(){ return "neo_msgs/USBoard"; };
    const char * getMD5(){ return "089d96eea3a0e01a364455ac3fa3cb33"; };

  };

}
#endif