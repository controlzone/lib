#ifndef _ROS_SERVICE_GetAngularPosition_h
#define _ROS_SERVICE_GetAngularPosition_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace wpi_jaco_msgs
{

static const char GETANGULARPOSITION[] = "wpi_jaco_msgs/GetAngularPosition";

  class GetAngularPositionRequest : public ros::Msg
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

    const char * getType(){ return GETANGULARPOSITION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetAngularPositionResponse : public ros::Msg
  {
    public:
      uint8_t pos_length;
      float st_pos;
      float * pos;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = pos_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pos_length; i++){
      union {
        float real;
        uint32_t base;
      } u_posi;
      u_posi.real = this->pos[i];
      *(outbuffer + offset + 0) = (u_posi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_posi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_posi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_posi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t pos_lengthT = *(inbuffer + offset++);
      if(pos_lengthT > pos_length)
        this->pos = (float*)realloc(this->pos, pos_lengthT * sizeof(float));
      offset += 3;
      pos_length = pos_lengthT;
      for( uint8_t i = 0; i < pos_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pos;
      u_st_pos.base = 0;
      u_st_pos.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pos.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pos.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pos.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pos = u_st_pos.real;
      offset += sizeof(this->st_pos);
        memcpy( &(this->pos[i]), &(this->st_pos), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return GETANGULARPOSITION; };
    const char * getMD5(){ return "2ddbdf76cbefd59cd9a914780fdf2963"; };

  };

  class GetAngularPosition {
    public:
    typedef GetAngularPositionRequest Request;
    typedef GetAngularPositionResponse Response;
  };

}
#endif
