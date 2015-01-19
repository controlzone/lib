#ifndef _ROS_lighting_msgs_DmxDevice_h
#define _ROS_lighting_msgs_DmxDevice_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "lighting_msgs/DmxAddress.h"
#include "lighting_msgs/DmxValue.h"

namespace lighting_msgs
{

  class DmxDevice : public ros::Msg
  {
    public:
      const char* name;
      const char* desc_name;
      lighting_msgs::DmxAddress address;
      uint8_t fields_length;
      char* st_fields;
      char* * fields;
      uint8_t values_length;
      lighting_msgs::DmxValue st_values;
      lighting_msgs::DmxValue * values;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_desc_name = strlen(this->desc_name);
      memcpy(outbuffer + offset, &length_desc_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->desc_name, length_desc_name);
      offset += length_desc_name;
      offset += this->address.serialize(outbuffer + offset);
      *(outbuffer + offset++) = fields_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < fields_length; i++){
      uint32_t length_fieldsi = strlen(this->fields[i]);
      memcpy(outbuffer + offset, &length_fieldsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->fields[i], length_fieldsi);
      offset += length_fieldsi;
      }
      *(outbuffer + offset++) = values_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < values_length; i++){
      offset += this->values[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_desc_name;
      memcpy(&length_desc_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_desc_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_desc_name-1]=0;
      this->desc_name = (char *)(inbuffer + offset-1);
      offset += length_desc_name;
      offset += this->address.deserialize(inbuffer + offset);
      uint8_t fields_lengthT = *(inbuffer + offset++);
      if(fields_lengthT > fields_length)
        this->fields = (char**)realloc(this->fields, fields_lengthT * sizeof(char*));
      offset += 3;
      fields_length = fields_lengthT;
      for( uint8_t i = 0; i < fields_length; i++){
      uint32_t length_st_fields;
      memcpy(&length_st_fields, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_fields; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_fields-1]=0;
      this->st_fields = (char *)(inbuffer + offset-1);
      offset += length_st_fields;
        memcpy( &(this->fields[i]), &(this->st_fields), sizeof(char*));
      }
      uint8_t values_lengthT = *(inbuffer + offset++);
      if(values_lengthT > values_length)
        this->values = (lighting_msgs::DmxValue*)realloc(this->values, values_lengthT * sizeof(lighting_msgs::DmxValue));
      offset += 3;
      values_length = values_lengthT;
      for( uint8_t i = 0; i < values_length; i++){
      offset += this->st_values.deserialize(inbuffer + offset);
        memcpy( &(this->values[i]), &(this->st_values), sizeof(lighting_msgs::DmxValue));
      }
     return offset;
    }

    const char * getType(){ return "lighting_msgs/DmxDevice"; };
    const char * getMD5(){ return "5394b98708cfdff20b09784dce153b24"; };

  };

}
#endif