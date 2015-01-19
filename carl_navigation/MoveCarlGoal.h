#ifndef _ROS_carl_navigation_MoveCarlGoal_h
#define _ROS_carl_navigation_MoveCarlGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace carl_navigation
{

  class MoveCarlGoal : public ros::Msg
  {
    public:
      int32_t location;
      enum { KITCHEN_TABLE = 1 };
      enum { KITCHEN_DRAWERS = 2 };
      enum { FRIDGE = 3 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_location;
      u_location.real = this->location;
      *(outbuffer + offset + 0) = (u_location.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_location.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_location.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_location.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->location);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_location;
      u_location.base = 0;
      u_location.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_location.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_location.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_location.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->location = u_location.real;
      offset += sizeof(this->location);
     return offset;
    }

    const char * getType(){ return "carl_navigation/MoveCarlGoal"; };
    const char * getMD5(){ return "6b233defba987efc9d0710c6cd025393"; };

  };

}
#endif