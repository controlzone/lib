#ifndef _ROS_lighting_msgs_DmxFrame_h
#define _ROS_lighting_msgs_DmxFrame_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "lighting_msgs/DmxValue.h"
#include "lighting_msgs/DmxEasing.h"

namespace lighting_msgs
{

  class DmxFrame : public ros::Msg
  {
    public:
      uint8_t values_length;
      lighting_msgs::DmxValue st_values;
      lighting_msgs::DmxValue * values;
      uint8_t easings_length;
      lighting_msgs::DmxEasing st_easings;
      lighting_msgs::DmxEasing * easings;
      uint32_t delayMs;
      uint32_t durationMs;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = values_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < values_length; i++){
      offset += this->values[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = easings_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < easings_length; i++){
      offset += this->easings[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->delayMs >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->delayMs >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->delayMs >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->delayMs >> (8 * 3)) & 0xFF;
      offset += sizeof(this->delayMs);
      *(outbuffer + offset + 0) = (this->durationMs >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->durationMs >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->durationMs >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->durationMs >> (8 * 3)) & 0xFF;
      offset += sizeof(this->durationMs);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t values_lengthT = *(inbuffer + offset++);
      if(values_lengthT > values_length)
        this->values = (lighting_msgs::DmxValue*)realloc(this->values, values_lengthT * sizeof(lighting_msgs::DmxValue));
      offset += 3;
      values_length = values_lengthT;
      for( uint8_t i = 0; i < values_length; i++){
      offset += this->st_values.deserialize(inbuffer + offset);
        memcpy( &(this->values[i]), &(this->st_values), sizeof(lighting_msgs::DmxValue));
      }
      uint8_t easings_lengthT = *(inbuffer + offset++);
      if(easings_lengthT > easings_length)
        this->easings = (lighting_msgs::DmxEasing*)realloc(this->easings, easings_lengthT * sizeof(lighting_msgs::DmxEasing));
      offset += 3;
      easings_length = easings_lengthT;
      for( uint8_t i = 0; i < easings_length; i++){
      offset += this->st_easings.deserialize(inbuffer + offset);
        memcpy( &(this->easings[i]), &(this->st_easings), sizeof(lighting_msgs::DmxEasing));
      }
      this->delayMs =  ((uint32_t) (*(inbuffer + offset)));
      this->delayMs |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->delayMs |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->delayMs |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->delayMs);
      this->durationMs =  ((uint32_t) (*(inbuffer + offset)));
      this->durationMs |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->durationMs |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->durationMs |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->durationMs);
     return offset;
    }

    const char * getType(){ return "lighting_msgs/DmxFrame"; };
    const char * getMD5(){ return "1b1b0cdf71b186b56f2cf813fbe9ad42"; };

  };

}
#endif