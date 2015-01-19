#ifndef _ROS_m4atx_battery_monitor_PowerReading_h
#define _ROS_m4atx_battery_monitor_PowerReading_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace m4atx_battery_monitor
{

  class PowerReading : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t volts_read_value_length;
      float st_volts_read_value;
      float * volts_read_value;
      uint8_t volts_read_item_length;
      char* st_volts_read_item;
      char* * volts_read_item;
      uint8_t volts_full_value_length;
      float st_volts_full_value;
      float * volts_full_value;
      uint8_t volts_full_item_length;
      char* st_volts_full_item;
      char* * volts_full_item;
      float input_soc;
      uint8_t current_length;
      float st_current;
      float * current;
      uint8_t temperature_length;
      float st_temperature;
      float * temperature;
      bool ac_on;
      bool is_charging;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = volts_read_value_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < volts_read_value_length; i++){
      union {
        float real;
        uint32_t base;
      } u_volts_read_valuei;
      u_volts_read_valuei.real = this->volts_read_value[i];
      *(outbuffer + offset + 0) = (u_volts_read_valuei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_volts_read_valuei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_volts_read_valuei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_volts_read_valuei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->volts_read_value[i]);
      }
      *(outbuffer + offset++) = volts_read_item_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < volts_read_item_length; i++){
      uint32_t length_volts_read_itemi = strlen(this->volts_read_item[i]);
      memcpy(outbuffer + offset, &length_volts_read_itemi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->volts_read_item[i], length_volts_read_itemi);
      offset += length_volts_read_itemi;
      }
      *(outbuffer + offset++) = volts_full_value_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < volts_full_value_length; i++){
      union {
        float real;
        uint32_t base;
      } u_volts_full_valuei;
      u_volts_full_valuei.real = this->volts_full_value[i];
      *(outbuffer + offset + 0) = (u_volts_full_valuei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_volts_full_valuei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_volts_full_valuei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_volts_full_valuei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->volts_full_value[i]);
      }
      *(outbuffer + offset++) = volts_full_item_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < volts_full_item_length; i++){
      uint32_t length_volts_full_itemi = strlen(this->volts_full_item[i]);
      memcpy(outbuffer + offset, &length_volts_full_itemi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->volts_full_item[i], length_volts_full_itemi);
      offset += length_volts_full_itemi;
      }
      union {
        float real;
        uint32_t base;
      } u_input_soc;
      u_input_soc.real = this->input_soc;
      *(outbuffer + offset + 0) = (u_input_soc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_input_soc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_input_soc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_input_soc.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->input_soc);
      *(outbuffer + offset++) = current_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < current_length; i++){
      union {
        float real;
        uint32_t base;
      } u_currenti;
      u_currenti.real = this->current[i];
      *(outbuffer + offset + 0) = (u_currenti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_currenti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_currenti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_currenti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current[i]);
      }
      *(outbuffer + offset++) = temperature_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < temperature_length; i++){
      union {
        float real;
        uint32_t base;
      } u_temperaturei;
      u_temperaturei.real = this->temperature[i];
      *(outbuffer + offset + 0) = (u_temperaturei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperaturei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperaturei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperaturei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperature[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_ac_on;
      u_ac_on.real = this->ac_on;
      *(outbuffer + offset + 0) = (u_ac_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ac_on);
      union {
        bool real;
        uint8_t base;
      } u_is_charging;
      u_is_charging.real = this->is_charging;
      *(outbuffer + offset + 0) = (u_is_charging.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_charging);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t volts_read_value_lengthT = *(inbuffer + offset++);
      if(volts_read_value_lengthT > volts_read_value_length)
        this->volts_read_value = (float*)realloc(this->volts_read_value, volts_read_value_lengthT * sizeof(float));
      offset += 3;
      volts_read_value_length = volts_read_value_lengthT;
      for( uint8_t i = 0; i < volts_read_value_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_volts_read_value;
      u_st_volts_read_value.base = 0;
      u_st_volts_read_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_volts_read_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_volts_read_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_volts_read_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_volts_read_value = u_st_volts_read_value.real;
      offset += sizeof(this->st_volts_read_value);
        memcpy( &(this->volts_read_value[i]), &(this->st_volts_read_value), sizeof(float));
      }
      uint8_t volts_read_item_lengthT = *(inbuffer + offset++);
      if(volts_read_item_lengthT > volts_read_item_length)
        this->volts_read_item = (char**)realloc(this->volts_read_item, volts_read_item_lengthT * sizeof(char*));
      offset += 3;
      volts_read_item_length = volts_read_item_lengthT;
      for( uint8_t i = 0; i < volts_read_item_length; i++){
      uint32_t length_st_volts_read_item;
      memcpy(&length_st_volts_read_item, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_volts_read_item; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_volts_read_item-1]=0;
      this->st_volts_read_item = (char *)(inbuffer + offset-1);
      offset += length_st_volts_read_item;
        memcpy( &(this->volts_read_item[i]), &(this->st_volts_read_item), sizeof(char*));
      }
      uint8_t volts_full_value_lengthT = *(inbuffer + offset++);
      if(volts_full_value_lengthT > volts_full_value_length)
        this->volts_full_value = (float*)realloc(this->volts_full_value, volts_full_value_lengthT * sizeof(float));
      offset += 3;
      volts_full_value_length = volts_full_value_lengthT;
      for( uint8_t i = 0; i < volts_full_value_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_volts_full_value;
      u_st_volts_full_value.base = 0;
      u_st_volts_full_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_volts_full_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_volts_full_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_volts_full_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_volts_full_value = u_st_volts_full_value.real;
      offset += sizeof(this->st_volts_full_value);
        memcpy( &(this->volts_full_value[i]), &(this->st_volts_full_value), sizeof(float));
      }
      uint8_t volts_full_item_lengthT = *(inbuffer + offset++);
      if(volts_full_item_lengthT > volts_full_item_length)
        this->volts_full_item = (char**)realloc(this->volts_full_item, volts_full_item_lengthT * sizeof(char*));
      offset += 3;
      volts_full_item_length = volts_full_item_lengthT;
      for( uint8_t i = 0; i < volts_full_item_length; i++){
      uint32_t length_st_volts_full_item;
      memcpy(&length_st_volts_full_item, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_volts_full_item; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_volts_full_item-1]=0;
      this->st_volts_full_item = (char *)(inbuffer + offset-1);
      offset += length_st_volts_full_item;
        memcpy( &(this->volts_full_item[i]), &(this->st_volts_full_item), sizeof(char*));
      }
      union {
        float real;
        uint32_t base;
      } u_input_soc;
      u_input_soc.base = 0;
      u_input_soc.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_input_soc.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_input_soc.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_input_soc.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->input_soc = u_input_soc.real;
      offset += sizeof(this->input_soc);
      uint8_t current_lengthT = *(inbuffer + offset++);
      if(current_lengthT > current_length)
        this->current = (float*)realloc(this->current, current_lengthT * sizeof(float));
      offset += 3;
      current_length = current_lengthT;
      for( uint8_t i = 0; i < current_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_current;
      u_st_current.base = 0;
      u_st_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_current = u_st_current.real;
      offset += sizeof(this->st_current);
        memcpy( &(this->current[i]), &(this->st_current), sizeof(float));
      }
      uint8_t temperature_lengthT = *(inbuffer + offset++);
      if(temperature_lengthT > temperature_length)
        this->temperature = (float*)realloc(this->temperature, temperature_lengthT * sizeof(float));
      offset += 3;
      temperature_length = temperature_lengthT;
      for( uint8_t i = 0; i < temperature_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_temperature;
      u_st_temperature.base = 0;
      u_st_temperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_temperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_temperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_temperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_temperature = u_st_temperature.real;
      offset += sizeof(this->st_temperature);
        memcpy( &(this->temperature[i]), &(this->st_temperature), sizeof(float));
      }
      union {
        bool real;
        uint8_t base;
      } u_ac_on;
      u_ac_on.base = 0;
      u_ac_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ac_on = u_ac_on.real;
      offset += sizeof(this->ac_on);
      union {
        bool real;
        uint8_t base;
      } u_is_charging;
      u_is_charging.base = 0;
      u_is_charging.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_charging = u_is_charging.real;
      offset += sizeof(this->is_charging);
     return offset;
    }

    const char * getType(){ return "m4atx_battery_monitor/PowerReading"; };
    const char * getMD5(){ return "56e298b3bc9c488ee94bd86afcbbf0e7"; };

  };

}
#endif