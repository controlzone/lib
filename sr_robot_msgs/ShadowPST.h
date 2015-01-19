#ifndef _ROS_sr_robot_msgs_ShadowPST_h
#define _ROS_sr_robot_msgs_ShadowPST_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace sr_robot_msgs
{

  class ShadowPST : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t pressure_length;
      int16_t st_pressure;
      int16_t * pressure;
      uint8_t temperature_length;
      int16_t st_temperature;
      int16_t * temperature;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = pressure_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pressure_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_pressurei;
      u_pressurei.real = this->pressure[i];
      *(outbuffer + offset + 0) = (u_pressurei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pressurei.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pressure[i]);
      }
      *(outbuffer + offset++) = temperature_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < temperature_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_temperaturei;
      u_temperaturei.real = this->temperature[i];
      *(outbuffer + offset + 0) = (u_temperaturei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperaturei.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->temperature[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t pressure_lengthT = *(inbuffer + offset++);
      if(pressure_lengthT > pressure_length)
        this->pressure = (int16_t*)realloc(this->pressure, pressure_lengthT * sizeof(int16_t));
      offset += 3;
      pressure_length = pressure_lengthT;
      for( uint8_t i = 0; i < pressure_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_pressure;
      u_st_pressure.base = 0;
      u_st_pressure.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pressure.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_pressure = u_st_pressure.real;
      offset += sizeof(this->st_pressure);
        memcpy( &(this->pressure[i]), &(this->st_pressure), sizeof(int16_t));
      }
      uint8_t temperature_lengthT = *(inbuffer + offset++);
      if(temperature_lengthT > temperature_length)
        this->temperature = (int16_t*)realloc(this->temperature, temperature_lengthT * sizeof(int16_t));
      offset += 3;
      temperature_length = temperature_lengthT;
      for( uint8_t i = 0; i < temperature_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_temperature;
      u_st_temperature.base = 0;
      u_st_temperature.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_temperature.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_temperature = u_st_temperature.real;
      offset += sizeof(this->st_temperature);
        memcpy( &(this->temperature[i]), &(this->st_temperature), sizeof(int16_t));
      }
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/ShadowPST"; };
    const char * getMD5(){ return "ab86b3368a7316c12291b90583e1910e"; };

  };

}
#endif