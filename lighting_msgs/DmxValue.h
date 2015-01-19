#ifndef _ROS_lighting_msgs_DmxValue_h
#define _ROS_lighting_msgs_DmxValue_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace lighting_msgs
{

  class DmxValue : public ros::Msg
  {
    public:
      uint32_t universe;
      uint32_t offset;
      uint8_t data_length;
      uint8_t st_data;
      uint8_t * data;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->universe >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->universe >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->universe >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->universe >> (8 * 3)) & 0xFF;
      offset += sizeof(this->universe);
      *(outbuffer + offset + 0) = (this->offset >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->offset >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->offset >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->offset >> (8 * 3)) & 0xFF;
      offset += sizeof(this->offset);
      *(outbuffer + offset++) = data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < data_length; i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->universe =  ((uint32_t) (*(inbuffer + offset)));
      this->universe |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->universe |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->universe |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->universe);
      this->offset =  ((uint32_t) (*(inbuffer + offset)));
      this->offset |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->offset |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->offset |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->offset);
      uint8_t data_lengthT = *(inbuffer + offset++);
      if(data_lengthT > data_length)
        this->data = (uint8_t*)realloc(this->data, data_lengthT * sizeof(uint8_t));
      offset += 3;
      data_length = data_lengthT;
      for( uint8_t i = 0; i < data_length; i++){
      this->st_data =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_data);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return "lighting_msgs/DmxValue"; };
    const char * getMD5(){ return "f67f03e501ce186e735a019b5a65fd64"; };

  };

}
#endif