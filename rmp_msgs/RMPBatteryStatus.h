#ifndef _ROS_rmp_msgs_RMPBatteryStatus_h
#define _ROS_rmp_msgs_RMPBatteryStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rmp_msgs
{

  class RMPBatteryStatus : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t soc_items_length;
      char* st_soc_items;
      char* * soc_items;
      uint8_t soc_values_length;
      float st_soc_values;
      float * soc_values;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = soc_items_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < soc_items_length; i++){
      uint32_t length_soc_itemsi = strlen(this->soc_items[i]);
      memcpy(outbuffer + offset, &length_soc_itemsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->soc_items[i], length_soc_itemsi);
      offset += length_soc_itemsi;
      }
      *(outbuffer + offset++) = soc_values_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < soc_values_length; i++){
      union {
        float real;
        uint32_t base;
      } u_soc_valuesi;
      u_soc_valuesi.real = this->soc_values[i];
      *(outbuffer + offset + 0) = (u_soc_valuesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_soc_valuesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_soc_valuesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_soc_valuesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->soc_values[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t soc_items_lengthT = *(inbuffer + offset++);
      if(soc_items_lengthT > soc_items_length)
        this->soc_items = (char**)realloc(this->soc_items, soc_items_lengthT * sizeof(char*));
      offset += 3;
      soc_items_length = soc_items_lengthT;
      for( uint8_t i = 0; i < soc_items_length; i++){
      uint32_t length_st_soc_items;
      memcpy(&length_st_soc_items, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_soc_items; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_soc_items-1]=0;
      this->st_soc_items = (char *)(inbuffer + offset-1);
      offset += length_st_soc_items;
        memcpy( &(this->soc_items[i]), &(this->st_soc_items), sizeof(char*));
      }
      uint8_t soc_values_lengthT = *(inbuffer + offset++);
      if(soc_values_lengthT > soc_values_length)
        this->soc_values = (float*)realloc(this->soc_values, soc_values_lengthT * sizeof(float));
      offset += 3;
      soc_values_length = soc_values_lengthT;
      for( uint8_t i = 0; i < soc_values_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_soc_values;
      u_st_soc_values.base = 0;
      u_st_soc_values.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_soc_values.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_soc_values.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_soc_values.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_soc_values = u_st_soc_values.real;
      offset += sizeof(this->st_soc_values);
        memcpy( &(this->soc_values[i]), &(this->st_soc_values), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "rmp_msgs/RMPBatteryStatus"; };
    const char * getMD5(){ return "74c210c462f2339426b30d67c39a4c4a"; };

  };

}
#endif