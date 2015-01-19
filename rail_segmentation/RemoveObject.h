#ifndef _ROS_SERVICE_RemoveObject_h
#define _ROS_SERVICE_RemoveObject_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rail_segmentation
{

static const char REMOVEOBJECT[] = "rail_segmentation/RemoveObject";

  class RemoveObjectRequest : public ros::Msg
  {
    public:
      int32_t index;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_index;
      u_index.real = this->index;
      *(outbuffer + offset + 0) = (u_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->index);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_index;
      u_index.base = 0;
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->index = u_index.real;
      offset += sizeof(this->index);
     return offset;
    }

    const char * getType(){ return REMOVEOBJECT; };
    const char * getMD5(){ return "483eea06cdc3e559421ee31116d0f3b9"; };

  };

  class RemoveObjectResponse : public ros::Msg
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

    const char * getType(){ return REMOVEOBJECT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class RemoveObject {
    public:
    typedef RemoveObjectRequest Request;
    typedef RemoveObjectResponse Response;
  };

}
#endif
