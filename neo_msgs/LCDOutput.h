#ifndef _ROS_neo_msgs_LCDOutput_h
#define _ROS_neo_msgs_LCDOutput_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace neo_msgs
{

  class LCDOutput : public ros::Msg
  {
    public:
      const char* msg_line;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_msg_line = strlen(this->msg_line);
      memcpy(outbuffer + offset, &length_msg_line, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->msg_line, length_msg_line);
      offset += length_msg_line;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_msg_line;
      memcpy(&length_msg_line, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_msg_line; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_msg_line-1]=0;
      this->msg_line = (char *)(inbuffer + offset-1);
      offset += length_msg_line;
     return offset;
    }

    const char * getType(){ return "neo_msgs/LCDOutput"; };
    const char * getMD5(){ return "a223a10d4aa8b3dc5e74a6c05e5047f2"; };

  };

}
#endif