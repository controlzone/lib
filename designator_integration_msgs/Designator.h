#ifndef _ROS_designator_integration_msgs_Designator_h
#define _ROS_designator_integration_msgs_Designator_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "designator_integration_msgs/KeyValuePair.h"

namespace designator_integration_msgs
{

  class Designator : public ros::Msg
  {
    public:
      int32_t type;
      uint8_t description_length;
      designator_integration_msgs::KeyValuePair st_description;
      designator_integration_msgs::KeyValuePair * description;
      enum { TYPE_OBJECT = 0 };
      enum { TYPE_ACTION = 1 };
      enum { TYPE_LOCATION = 2 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
      *(outbuffer + offset++) = description_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < description_length; i++){
      offset += this->description[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      uint8_t description_lengthT = *(inbuffer + offset++);
      if(description_lengthT > description_length)
        this->description = (designator_integration_msgs::KeyValuePair*)realloc(this->description, description_lengthT * sizeof(designator_integration_msgs::KeyValuePair));
      offset += 3;
      description_length = description_lengthT;
      for( uint8_t i = 0; i < description_length; i++){
      offset += this->st_description.deserialize(inbuffer + offset);
        memcpy( &(this->description[i]), &(this->st_description), sizeof(designator_integration_msgs::KeyValuePair));
      }
     return offset;
    }

    const char * getType(){ return "designator_integration_msgs/Designator"; };
    const char * getMD5(){ return "4ed6b086de705c4579958bd997fa1e95"; };

  };

}
#endif