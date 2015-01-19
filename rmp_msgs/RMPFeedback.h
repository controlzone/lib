#ifndef _ROS_rmp_msgs_RMPFeedback_h
#define _ROS_rmp_msgs_RMPFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rmp_msgs
{

  class RMPFeedback : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t sensor_items_length;
      char* st_sensor_items;
      char* * sensor_items;
      uint8_t sensor_values_length;
      float st_sensor_values;
      float * sensor_values;
      uint8_t fault_status_items_length;
      char* st_fault_status_items;
      char* * fault_status_items;
      uint8_t fault_status_values_length;
      uint32_t st_fault_status_values;
      uint32_t * fault_status_values;
      uint8_t ip_info_length;
      char* st_ip_info;
      char* * ip_info;
      uint8_t ip_values_length;
      char* st_ip_values;
      char* * ip_values;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = sensor_items_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < sensor_items_length; i++){
      uint32_t length_sensor_itemsi = strlen(this->sensor_items[i]);
      memcpy(outbuffer + offset, &length_sensor_itemsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->sensor_items[i], length_sensor_itemsi);
      offset += length_sensor_itemsi;
      }
      *(outbuffer + offset++) = sensor_values_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < sensor_values_length; i++){
      union {
        float real;
        uint32_t base;
      } u_sensor_valuesi;
      u_sensor_valuesi.real = this->sensor_values[i];
      *(outbuffer + offset + 0) = (u_sensor_valuesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sensor_valuesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sensor_valuesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sensor_valuesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sensor_values[i]);
      }
      *(outbuffer + offset++) = fault_status_items_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < fault_status_items_length; i++){
      uint32_t length_fault_status_itemsi = strlen(this->fault_status_items[i]);
      memcpy(outbuffer + offset, &length_fault_status_itemsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->fault_status_items[i], length_fault_status_itemsi);
      offset += length_fault_status_itemsi;
      }
      *(outbuffer + offset++) = fault_status_values_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < fault_status_values_length; i++){
      *(outbuffer + offset + 0) = (this->fault_status_values[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fault_status_values[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fault_status_values[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fault_status_values[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fault_status_values[i]);
      }
      *(outbuffer + offset++) = ip_info_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < ip_info_length; i++){
      uint32_t length_ip_infoi = strlen(this->ip_info[i]);
      memcpy(outbuffer + offset, &length_ip_infoi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->ip_info[i], length_ip_infoi);
      offset += length_ip_infoi;
      }
      *(outbuffer + offset++) = ip_values_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < ip_values_length; i++){
      uint32_t length_ip_valuesi = strlen(this->ip_values[i]);
      memcpy(outbuffer + offset, &length_ip_valuesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->ip_values[i], length_ip_valuesi);
      offset += length_ip_valuesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t sensor_items_lengthT = *(inbuffer + offset++);
      if(sensor_items_lengthT > sensor_items_length)
        this->sensor_items = (char**)realloc(this->sensor_items, sensor_items_lengthT * sizeof(char*));
      offset += 3;
      sensor_items_length = sensor_items_lengthT;
      for( uint8_t i = 0; i < sensor_items_length; i++){
      uint32_t length_st_sensor_items;
      memcpy(&length_st_sensor_items, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_sensor_items; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_sensor_items-1]=0;
      this->st_sensor_items = (char *)(inbuffer + offset-1);
      offset += length_st_sensor_items;
        memcpy( &(this->sensor_items[i]), &(this->st_sensor_items), sizeof(char*));
      }
      uint8_t sensor_values_lengthT = *(inbuffer + offset++);
      if(sensor_values_lengthT > sensor_values_length)
        this->sensor_values = (float*)realloc(this->sensor_values, sensor_values_lengthT * sizeof(float));
      offset += 3;
      sensor_values_length = sensor_values_lengthT;
      for( uint8_t i = 0; i < sensor_values_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_sensor_values;
      u_st_sensor_values.base = 0;
      u_st_sensor_values.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_sensor_values.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_sensor_values.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_sensor_values.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_sensor_values = u_st_sensor_values.real;
      offset += sizeof(this->st_sensor_values);
        memcpy( &(this->sensor_values[i]), &(this->st_sensor_values), sizeof(float));
      }
      uint8_t fault_status_items_lengthT = *(inbuffer + offset++);
      if(fault_status_items_lengthT > fault_status_items_length)
        this->fault_status_items = (char**)realloc(this->fault_status_items, fault_status_items_lengthT * sizeof(char*));
      offset += 3;
      fault_status_items_length = fault_status_items_lengthT;
      for( uint8_t i = 0; i < fault_status_items_length; i++){
      uint32_t length_st_fault_status_items;
      memcpy(&length_st_fault_status_items, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_fault_status_items; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_fault_status_items-1]=0;
      this->st_fault_status_items = (char *)(inbuffer + offset-1);
      offset += length_st_fault_status_items;
        memcpy( &(this->fault_status_items[i]), &(this->st_fault_status_items), sizeof(char*));
      }
      uint8_t fault_status_values_lengthT = *(inbuffer + offset++);
      if(fault_status_values_lengthT > fault_status_values_length)
        this->fault_status_values = (uint32_t*)realloc(this->fault_status_values, fault_status_values_lengthT * sizeof(uint32_t));
      offset += 3;
      fault_status_values_length = fault_status_values_lengthT;
      for( uint8_t i = 0; i < fault_status_values_length; i++){
      this->st_fault_status_values =  ((uint32_t) (*(inbuffer + offset)));
      this->st_fault_status_values |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_fault_status_values |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_fault_status_values |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_fault_status_values);
        memcpy( &(this->fault_status_values[i]), &(this->st_fault_status_values), sizeof(uint32_t));
      }
      uint8_t ip_info_lengthT = *(inbuffer + offset++);
      if(ip_info_lengthT > ip_info_length)
        this->ip_info = (char**)realloc(this->ip_info, ip_info_lengthT * sizeof(char*));
      offset += 3;
      ip_info_length = ip_info_lengthT;
      for( uint8_t i = 0; i < ip_info_length; i++){
      uint32_t length_st_ip_info;
      memcpy(&length_st_ip_info, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_ip_info; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_ip_info-1]=0;
      this->st_ip_info = (char *)(inbuffer + offset-1);
      offset += length_st_ip_info;
        memcpy( &(this->ip_info[i]), &(this->st_ip_info), sizeof(char*));
      }
      uint8_t ip_values_lengthT = *(inbuffer + offset++);
      if(ip_values_lengthT > ip_values_length)
        this->ip_values = (char**)realloc(this->ip_values, ip_values_lengthT * sizeof(char*));
      offset += 3;
      ip_values_length = ip_values_lengthT;
      for( uint8_t i = 0; i < ip_values_length; i++){
      uint32_t length_st_ip_values;
      memcpy(&length_st_ip_values, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_ip_values; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_ip_values-1]=0;
      this->st_ip_values = (char *)(inbuffer + offset-1);
      offset += length_st_ip_values;
        memcpy( &(this->ip_values[i]), &(this->st_ip_values), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "rmp_msgs/RMPFeedback"; };
    const char * getMD5(){ return "8688d7b0a2904002e7cc9d6c90a32697"; };

  };

}
#endif