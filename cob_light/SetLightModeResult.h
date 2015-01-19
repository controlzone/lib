#ifndef _ROS_cob_light_SetLightModeResult_h
#define _ROS_cob_light_SetLightModeResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_light
{

  class SetLightModeResult : public ros::Msg
  {
    public:
      uint8_t active_mode;
      uint8_t active_priority;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->active_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->active_mode);
      *(outbuffer + offset + 0) = (this->active_priority >> (8 * 0)) & 0xFF;
      offset += sizeof(this->active_priority);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->active_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->active_mode);
      this->active_priority =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->active_priority);
     return offset;
    }

    const char * getType(){ return "cob_light/SetLightModeResult"; };
    const char * getMD5(){ return "18daff0db423efd323f68cd039226daa"; };

  };

}
#endif