#ifndef _ROS_neo_msgs_RadarBoard_h
#define _ROS_neo_msgs_RadarBoard_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace neo_msgs
{

  class RadarBoard : public ros::Msg
  {
    public:
      float velocity[3];
      int32_t state;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_state;
      u_state.real = this->state;
      *(outbuffer + offset + 0) = (u_state.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_state.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_state.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_state.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velocity[i]));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_state;
      u_state.base = 0;
      u_state.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_state.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_state.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_state.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->state = u_state.real;
      offset += sizeof(this->state);
     return offset;
    }

    const char * getType(){ return "neo_msgs/RadarBoard"; };
    const char * getMD5(){ return "2a5dbee0d40bb12d02b78bf551ec141d"; };

  };

}
#endif