#ifndef _ROS_sr_robot_msgs_MidProxData_h
#define _ROS_sr_robot_msgs_MidProxData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_robot_msgs
{

  class MidProxData : public ros::Msg
  {
    public:
      uint16_t middle[4];
      uint16_t proximal[4];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 4; i++){
      *(outbuffer + offset + 0) = (this->middle[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->middle[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->middle[i]);
      }
      for( uint8_t i = 0; i < 4; i++){
      *(outbuffer + offset + 0) = (this->proximal[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->proximal[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->proximal[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 4; i++){
      this->middle[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->middle[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->middle[i]);
      }
      for( uint8_t i = 0; i < 4; i++){
      this->proximal[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->proximal[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->proximal[i]);
      }
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/MidProxData"; };
    const char * getMD5(){ return "8ae5331748e57fcbdb20b7e2f086fcbf"; };

  };

}
#endif