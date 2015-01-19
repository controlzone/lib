#ifndef _ROS_sr_robot_msgs_Biotac_h
#define _ROS_sr_robot_msgs_Biotac_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_robot_msgs
{

  class Biotac : public ros::Msg
  {
    public:
      int16_t pac0;
      int16_t pac1;
      int16_t pdc;
      int16_t tac;
      int16_t tdc;
      int16_t electrodes[19];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_pac0;
      u_pac0.real = this->pac0;
      *(outbuffer + offset + 0) = (u_pac0.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pac0.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pac0);
      union {
        int16_t real;
        uint16_t base;
      } u_pac1;
      u_pac1.real = this->pac1;
      *(outbuffer + offset + 0) = (u_pac1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pac1.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pac1);
      union {
        int16_t real;
        uint16_t base;
      } u_pdc;
      u_pdc.real = this->pdc;
      *(outbuffer + offset + 0) = (u_pdc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pdc.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pdc);
      union {
        int16_t real;
        uint16_t base;
      } u_tac;
      u_tac.real = this->tac;
      *(outbuffer + offset + 0) = (u_tac.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tac.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->tac);
      union {
        int16_t real;
        uint16_t base;
      } u_tdc;
      u_tdc.real = this->tdc;
      *(outbuffer + offset + 0) = (u_tdc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tdc.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->tdc);
      for( uint8_t i = 0; i < 19; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_electrodesi;
      u_electrodesi.real = this->electrodes[i];
      *(outbuffer + offset + 0) = (u_electrodesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_electrodesi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->electrodes[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_pac0;
      u_pac0.base = 0;
      u_pac0.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pac0.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pac0 = u_pac0.real;
      offset += sizeof(this->pac0);
      union {
        int16_t real;
        uint16_t base;
      } u_pac1;
      u_pac1.base = 0;
      u_pac1.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pac1.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pac1 = u_pac1.real;
      offset += sizeof(this->pac1);
      union {
        int16_t real;
        uint16_t base;
      } u_pdc;
      u_pdc.base = 0;
      u_pdc.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pdc.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pdc = u_pdc.real;
      offset += sizeof(this->pdc);
      union {
        int16_t real;
        uint16_t base;
      } u_tac;
      u_tac.base = 0;
      u_tac.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tac.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tac = u_tac.real;
      offset += sizeof(this->tac);
      union {
        int16_t real;
        uint16_t base;
      } u_tdc;
      u_tdc.base = 0;
      u_tdc.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tdc.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tdc = u_tdc.real;
      offset += sizeof(this->tdc);
      for( uint8_t i = 0; i < 19; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_electrodesi;
      u_electrodesi.base = 0;
      u_electrodesi.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_electrodesi.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->electrodes[i] = u_electrodesi.real;
      offset += sizeof(this->electrodes[i]);
      }
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/Biotac"; };
    const char * getMD5(){ return "45887a982dc5cee83be90c94c9db9f12"; };

  };

}
#endif