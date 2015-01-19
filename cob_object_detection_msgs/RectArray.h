#ifndef _ROS_cob_object_detection_msgs_RectArray_h
#define _ROS_cob_object_detection_msgs_RectArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "cob_object_detection_msgs/Rect.h"

namespace cob_object_detection_msgs
{

  class RectArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t rects_length;
      cob_object_detection_msgs::Rect st_rects;
      cob_object_detection_msgs::Rect * rects;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = rects_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < rects_length; i++){
      offset += this->rects[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t rects_lengthT = *(inbuffer + offset++);
      if(rects_lengthT > rects_length)
        this->rects = (cob_object_detection_msgs::Rect*)realloc(this->rects, rects_lengthT * sizeof(cob_object_detection_msgs::Rect));
      offset += 3;
      rects_length = rects_lengthT;
      for( uint8_t i = 0; i < rects_length; i++){
      offset += this->st_rects.deserialize(inbuffer + offset);
        memcpy( &(this->rects[i]), &(this->st_rects), sizeof(cob_object_detection_msgs::Rect));
      }
     return offset;
    }

    const char * getType(){ return "cob_object_detection_msgs/RectArray"; };
    const char * getMD5(){ return "e83b38fbaea3a641fa77f009f9bf492e"; };

  };

}
#endif