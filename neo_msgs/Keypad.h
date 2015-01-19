#ifndef _ROS_neo_msgs_Keypad_h
#define _ROS_neo_msgs_Keypad_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace neo_msgs
{

  class Keypad : public ros::Msg
  {
    public:
      bool button[4];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 4; i++){
      union {
        bool real;
        uint8_t base;
      } u_buttoni;
      u_buttoni.real = this->button[i];
      *(outbuffer + offset + 0) = (u_buttoni.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->button[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 4; i++){
      union {
        bool real;
        uint8_t base;
      } u_buttoni;
      u_buttoni.base = 0;
      u_buttoni.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->button[i] = u_buttoni.real;
      offset += sizeof(this->button[i]);
      }
     return offset;
    }

    const char * getType(){ return "neo_msgs/Keypad"; };
    const char * getMD5(){ return "2bee8fd416439863b55d471ebc6f3501"; };

  };

}
#endif