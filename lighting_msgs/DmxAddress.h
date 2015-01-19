#ifndef _ROS_lighting_msgs_DmxAddress_h
#define _ROS_lighting_msgs_DmxAddress_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace lighting_msgs
{

  class DmxAddress : public ros::Msg
  {
    public:
      uint32_t universe;
      uint32_t offset;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->universe >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->universe >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->universe >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->universe >> (8 * 3)) & 0xFF;
      offset += sizeof(this->universe);
      *(outbuffer + offset + 0) = (this->offset >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->offset >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->offset >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->offset >> (8 * 3)) & 0xFF;
      offset += sizeof(this->offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->universe =  ((uint32_t) (*(inbuffer + offset)));
      this->universe |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->universe |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->universe |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->universe);
      this->offset =  ((uint32_t) (*(inbuffer + offset)));
      this->offset |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->offset |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->offset |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->offset);
     return offset;
    }

    const char * getType(){ return "lighting_msgs/DmxAddress"; };
    const char * getMD5(){ return "5e2677ff7670801db6f7c33d69d3dc76"; };

  };

}
#endif