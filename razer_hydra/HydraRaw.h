#ifndef _ROS_razer_hydra_HydraRaw_h
#define _ROS_razer_hydra_HydraRaw_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace razer_hydra
{

  class HydraRaw : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int16_t pos[6];
      int16_t quat[8];
      uint8_t buttons[2];
      int16_t analog[6];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_posi;
      u_posi.real = this->pos[i];
      *(outbuffer + offset + 0) = (u_posi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_posi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pos[i]);
      }
      for( uint8_t i = 0; i < 8; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_quati;
      u_quati.real = this->quat[i];
      *(outbuffer + offset + 0) = (u_quati.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_quati.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->quat[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      *(outbuffer + offset + 0) = (this->buttons[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->buttons[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_analogi;
      u_analogi.real = this->analog[i];
      *(outbuffer + offset + 0) = (u_analogi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_analogi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->analog[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_posi;
      u_posi.base = 0;
      u_posi.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_posi.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pos[i] = u_posi.real;
      offset += sizeof(this->pos[i]);
      }
      for( uint8_t i = 0; i < 8; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_quati;
      u_quati.base = 0;
      u_quati.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_quati.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->quat[i] = u_quati.real;
      offset += sizeof(this->quat[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      this->buttons[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->buttons[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_analogi;
      u_analogi.base = 0;
      u_analogi.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_analogi.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->analog[i] = u_analogi.real;
      offset += sizeof(this->analog[i]);
      }
     return offset;
    }

    const char * getType(){ return "razer_hydra/HydraRaw"; };
    const char * getMD5(){ return "abda63674ce89e542bda766f5d8939f7"; };

  };

}
#endif