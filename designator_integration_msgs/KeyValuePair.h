#ifndef _ROS_designator_integration_msgs_KeyValuePair_h
#define _ROS_designator_integration_msgs_KeyValuePair_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Pose.h"

namespace designator_integration_msgs
{

  class KeyValuePair : public ros::Msg
  {
    public:
      int32_t id;
      int32_t parent;
      int32_t type;
      const char* key;
      const char* value_string;
      float value_float;
      uint8_t value_data_length;
      uint8_t st_value_data;
      uint8_t * value_data;
      geometry_msgs::PoseStamped value_posestamped;
      geometry_msgs::Pose value_pose;
      enum { TYPE_STRING = 0 };
      enum { TYPE_FLOAT = 1 };
      enum { TYPE_DATA = 2 };
      enum { TYPE_LIST = 3 };
      enum { TYPE_POSESTAMPED = 4 };
      enum { TYPE_POSE = 5 };
      enum { TYPE_DESIGNATOR_ACTION = 6 };
      enum { TYPE_DESIGNATOR_OBJECT = 7 };
      enum { TYPE_DESIGNATOR_LOCATION = 8 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      union {
        int32_t real;
        uint32_t base;
      } u_parent;
      u_parent.real = this->parent;
      *(outbuffer + offset + 0) = (u_parent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_parent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_parent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_parent.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->parent);
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type);
      uint32_t length_key = strlen(this->key);
      memcpy(outbuffer + offset, &length_key, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->key, length_key);
      offset += length_key;
      uint32_t length_value_string = strlen(this->value_string);
      memcpy(outbuffer + offset, &length_value_string, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->value_string, length_value_string);
      offset += length_value_string;
      offset += serializeAvrFloat64(outbuffer + offset, this->value_float);
      *(outbuffer + offset++) = value_data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < value_data_length; i++){
      *(outbuffer + offset + 0) = (this->value_data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->value_data[i]);
      }
      offset += this->value_posestamped.serialize(outbuffer + offset);
      offset += this->value_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
      union {
        int32_t real;
        uint32_t base;
      } u_parent;
      u_parent.base = 0;
      u_parent.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_parent.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_parent.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_parent.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->parent = u_parent.real;
      offset += sizeof(this->parent);
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->type = u_type.real;
      offset += sizeof(this->type);
      uint32_t length_key;
      memcpy(&length_key, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_key; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_key-1]=0;
      this->key = (char *)(inbuffer + offset-1);
      offset += length_key;
      uint32_t length_value_string;
      memcpy(&length_value_string, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_value_string; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_value_string-1]=0;
      this->value_string = (char *)(inbuffer + offset-1);
      offset += length_value_string;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->value_float));
      uint8_t value_data_lengthT = *(inbuffer + offset++);
      if(value_data_lengthT > value_data_length)
        this->value_data = (uint8_t*)realloc(this->value_data, value_data_lengthT * sizeof(uint8_t));
      offset += 3;
      value_data_length = value_data_lengthT;
      for( uint8_t i = 0; i < value_data_length; i++){
      this->st_value_data =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_value_data);
        memcpy( &(this->value_data[i]), &(this->st_value_data), sizeof(uint8_t));
      }
      offset += this->value_posestamped.deserialize(inbuffer + offset);
      offset += this->value_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "designator_integration_msgs/KeyValuePair"; };
    const char * getMD5(){ return "ab3803903da53ac6f593c342b4004f58"; };

  };

}
#endif