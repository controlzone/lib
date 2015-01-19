#ifndef _ROS_neo_msgs_GyroBoard_h
#define _ROS_neo_msgs_GyroBoard_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace neo_msgs
{

  class GyroBoard : public ros::Msg
  {
    public:
      float acceleration[3];
      float orientation;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->acceleration[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->orientation);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->acceleration[i]));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->orientation));
     return offset;
    }

    const char * getType(){ return "neo_msgs/GyroBoard"; };
    const char * getMD5(){ return "2b635625b22ccc397d44e4cb7dac6a32"; };

  };

}
#endif