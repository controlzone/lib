#ifndef _ROS_saphari_msgs_Human_h
#define _ROS_saphari_msgs_Human_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "saphari_msgs/BodyPart.h"

namespace saphari_msgs
{

  class Human : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t bodyParts_length;
      saphari_msgs::BodyPart st_bodyParts;
      saphari_msgs::BodyPart * bodyParts;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = bodyParts_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < bodyParts_length; i++){
      offset += this->bodyParts[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t bodyParts_lengthT = *(inbuffer + offset++);
      if(bodyParts_lengthT > bodyParts_length)
        this->bodyParts = (saphari_msgs::BodyPart*)realloc(this->bodyParts, bodyParts_lengthT * sizeof(saphari_msgs::BodyPart));
      offset += 3;
      bodyParts_length = bodyParts_lengthT;
      for( uint8_t i = 0; i < bodyParts_length; i++){
      offset += this->st_bodyParts.deserialize(inbuffer + offset);
        memcpy( &(this->bodyParts[i]), &(this->st_bodyParts), sizeof(saphari_msgs::BodyPart));
      }
     return offset;
    }

    const char * getType(){ return "saphari_msgs/Human"; };
    const char * getMD5(){ return "39c60352eebd97c018b297e5f47dd556"; };

  };

}
#endif