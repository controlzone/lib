#ifndef _ROS_lighting_msgs_DmxEasing_h
#define _ROS_lighting_msgs_DmxEasing_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "lighting_msgs/DmxValue.h"

namespace lighting_msgs
{

  class DmxEasing : public ros::Msg
  {
    public:
      uint8_t start_length;
      lighting_msgs::DmxValue st_start;
      lighting_msgs::DmxValue * start;
      uint8_t end_length;
      lighting_msgs::DmxValue st_end;
      lighting_msgs::DmxValue * end;
      uint32_t delayMs;
      uint32_t durationMs;
      uint8_t curve;
      enum { Linear =  0 };
      enum { InQuad =  1 };
      enum { OutQuad =  2 };
      enum { InOutQuad =  3 };
      enum { OutInQuad =  4 };
      enum { InCubic =  5 };
      enum { OutCubic =  6 };
      enum { InOutCubic =  7 };
      enum { OutInCubic =  8 };
      enum { InQuart =  9 };
      enum { OutQuart =  10 };
      enum { InOutQuart =  11 };
      enum { OutInQuart =  12 };
      enum { InQuint =  13 };
      enum { OutQuint =  14 };
      enum { InOutQuint =  15 };
      enum { OutInQuint =  16 };
      enum { InSine =  17 };
      enum { OutSine =  18 };
      enum { InOutSine =  19 };
      enum { OutInSine =  20 };
      enum { InExpo =  21 };
      enum { OutExpo =  22 };
      enum { InOutExpo =  23 };
      enum { OutInExpo =  24 };
      enum { InCirc =  25 };
      enum { OutCirc =  26 };
      enum { InOutCirc =  27 };
      enum { OutInCirc =  28 };
      enum { InElastic =  29 };
      enum { OutElastic =  30 };
      enum { InOutElastic =  31 };
      enum { OutInElastic =  32 };
      enum { InBack =  33 };
      enum { OutBack =  34 };
      enum { InOutBack =  35 };
      enum { OutInBack =  36 };
      enum { InBounce =  37 };
      enum { OutBounce =  38 };
      enum { InOutBounce =  39 };
      enum { OutInBounce =  40 };
      enum { Custom =  45 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = start_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < start_length; i++){
      offset += this->start[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = end_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < end_length; i++){
      offset += this->end[i].serialize(outbuffer + offset);
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
      *(outbuffer + offset + 0) = (this->curve >> (8 * 0)) & 0xFF;
      offset += sizeof(this->curve);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t start_lengthT = *(inbuffer + offset++);
      if(start_lengthT > start_length)
        this->start = (lighting_msgs::DmxValue*)realloc(this->start, start_lengthT * sizeof(lighting_msgs::DmxValue));
      offset += 3;
      start_length = start_lengthT;
      for( uint8_t i = 0; i < start_length; i++){
      offset += this->st_start.deserialize(inbuffer + offset);
        memcpy( &(this->start[i]), &(this->st_start), sizeof(lighting_msgs::DmxValue));
      }
      uint8_t end_lengthT = *(inbuffer + offset++);
      if(end_lengthT > end_length)
        this->end = (lighting_msgs::DmxValue*)realloc(this->end, end_lengthT * sizeof(lighting_msgs::DmxValue));
      offset += 3;
      end_length = end_lengthT;
      for( uint8_t i = 0; i < end_length; i++){
      offset += this->st_end.deserialize(inbuffer + offset);
        memcpy( &(this->end[i]), &(this->st_end), sizeof(lighting_msgs::DmxValue));
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
      this->curve =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->curve);
     return offset;
    }

    const char * getType(){ return "lighting_msgs/DmxEasing"; };
    const char * getMD5(){ return "0351a1f3949e734f0b3ec5a5fb5831ab"; };

  };

}
#endif