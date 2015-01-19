#ifndef _ROS_SERVICE_is_hand_occupied_h
#define _ROS_SERVICE_is_hand_occupied_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_robot_msgs
{

static const char IS_HAND_OCCUPIED[] = "sr_robot_msgs/is_hand_occupied";

  class is_hand_occupiedRequest : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return IS_HAND_OCCUPIED; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class is_hand_occupiedResponse : public ros::Msg
  {
    public:
      bool hand_occupied;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_hand_occupied;
      u_hand_occupied.real = this->hand_occupied;
      *(outbuffer + offset + 0) = (u_hand_occupied.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->hand_occupied);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_hand_occupied;
      u_hand_occupied.base = 0;
      u_hand_occupied.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->hand_occupied = u_hand_occupied.real;
      offset += sizeof(this->hand_occupied);
     return offset;
    }

    const char * getType(){ return IS_HAND_OCCUPIED; };
    const char * getMD5(){ return "62624a9d19535f7a135d1ce1fc0d0450"; };

  };

  class is_hand_occupied {
    public:
    typedef is_hand_occupiedRequest Request;
    typedef is_hand_occupiedResponse Response;
  };

}
#endif
