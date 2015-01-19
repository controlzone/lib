#ifndef _ROS_rocon_device_msgs_SetColor_h
#define _ROS_rocon_device_msgs_SetColor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rocon_device_msgs
{

  class SetColor : public ros::Msg
  {
    public:
      const char* id;
      const char* color;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      memcpy(outbuffer + offset, &length_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      uint32_t length_color = strlen(this->color);
      memcpy(outbuffer + offset, &length_color, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->color, length_color);
      offset += length_color;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_id;
      memcpy(&length_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      uint32_t length_color;
      memcpy(&length_color, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_color; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_color-1]=0;
      this->color = (char *)(inbuffer + offset-1);
      offset += length_color;
     return offset;
    }

    const char * getType(){ return "rocon_device_msgs/SetColor"; };
    const char * getMD5(){ return "9dcf2884a64483c66152c9157be75b10"; };

  };

}
#endif