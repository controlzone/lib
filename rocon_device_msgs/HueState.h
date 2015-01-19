#ifndef _ROS_rocon_device_msgs_HueState_h
#define _ROS_rocon_device_msgs_HueState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rocon_device_msgs
{

  class HueState : public ros::Msg
  {
    public:
      bool on;
      uint8_t xy_length;
      float st_xy;
      float * xy;
      uint16_t hue;
      uint8_t sat;
      uint8_t bri;
      uint16_t ct;
      const char* mode;
      int32_t transitiontime;
      const char* color_mode;
      bool reachable;
      enum { NONE =  none };
      enum { COLOR_LOOP =   colorloop };
      enum { SELECT =  select };
      enum { LSELECT =  lselect };
      enum { HS =  hs  };
      enum { XY =  xy  };
      enum { CT =  ct  };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_on;
      u_on.real = this->on;
      *(outbuffer + offset + 0) = (u_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->on);
      *(outbuffer + offset++) = xy_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < xy_length; i++){
      union {
        float real;
        uint32_t base;
      } u_xyi;
      u_xyi.real = this->xy[i];
      *(outbuffer + offset + 0) = (u_xyi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xyi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xyi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xyi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xy[i]);
      }
      *(outbuffer + offset + 0) = (this->hue >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hue >> (8 * 1)) & 0xFF;
      offset += sizeof(this->hue);
      *(outbuffer + offset + 0) = (this->sat >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sat);
      *(outbuffer + offset + 0) = (this->bri >> (8 * 0)) & 0xFF;
      offset += sizeof(this->bri);
      *(outbuffer + offset + 0) = (this->ct >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ct >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ct);
      uint32_t length_mode = strlen(this->mode);
      memcpy(outbuffer + offset, &length_mode, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->mode, length_mode);
      offset += length_mode;
      union {
        int32_t real;
        uint32_t base;
      } u_transitiontime;
      u_transitiontime.real = this->transitiontime;
      *(outbuffer + offset + 0) = (u_transitiontime.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_transitiontime.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_transitiontime.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_transitiontime.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->transitiontime);
      uint32_t length_color_mode = strlen(this->color_mode);
      memcpy(outbuffer + offset, &length_color_mode, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->color_mode, length_color_mode);
      offset += length_color_mode;
      union {
        bool real;
        uint8_t base;
      } u_reachable;
      u_reachable.real = this->reachable;
      *(outbuffer + offset + 0) = (u_reachable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reachable);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_on;
      u_on.base = 0;
      u_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->on = u_on.real;
      offset += sizeof(this->on);
      uint8_t xy_lengthT = *(inbuffer + offset++);
      if(xy_lengthT > xy_length)
        this->xy = (float*)realloc(this->xy, xy_lengthT * sizeof(float));
      offset += 3;
      xy_length = xy_lengthT;
      for( uint8_t i = 0; i < xy_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_xy;
      u_st_xy.base = 0;
      u_st_xy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_xy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_xy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_xy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_xy = u_st_xy.real;
      offset += sizeof(this->st_xy);
        memcpy( &(this->xy[i]), &(this->st_xy), sizeof(float));
      }
      this->hue =  ((uint16_t) (*(inbuffer + offset)));
      this->hue |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->hue);
      this->sat =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sat);
      this->bri =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->bri);
      this->ct =  ((uint16_t) (*(inbuffer + offset)));
      this->ct |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->ct);
      uint32_t length_mode;
      memcpy(&length_mode, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mode; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mode-1]=0;
      this->mode = (char *)(inbuffer + offset-1);
      offset += length_mode;
      union {
        int32_t real;
        uint32_t base;
      } u_transitiontime;
      u_transitiontime.base = 0;
      u_transitiontime.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_transitiontime.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_transitiontime.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_transitiontime.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->transitiontime = u_transitiontime.real;
      offset += sizeof(this->transitiontime);
      uint32_t length_color_mode;
      memcpy(&length_color_mode, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_color_mode; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_color_mode-1]=0;
      this->color_mode = (char *)(inbuffer + offset-1);
      offset += length_color_mode;
      union {
        bool real;
        uint8_t base;
      } u_reachable;
      u_reachable.base = 0;
      u_reachable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reachable = u_reachable.real;
      offset += sizeof(this->reachable);
     return offset;
    }

    const char * getType(){ return "rocon_device_msgs/HueState"; };
    const char * getMD5(){ return "7e4ad09b859196f23a5883df58e12e77"; };

  };

}
#endif