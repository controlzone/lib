#ifndef _ROS_SERVICE_content_msg_h
#define _ROS_SERVICE_content_msg_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"

namespace iai_content_msgs
{

static const char CONTENT_MSG[] = "iai_content_msgs/content_msg";

  class content_msgRequest : public ros::Msg
  {
    public:
      sensor_msgs::Image depth;
      sensor_msgs::Image depth_grasped;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->depth.serialize(outbuffer + offset);
      offset += this->depth_grasped.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->depth.deserialize(inbuffer + offset);
      offset += this->depth_grasped.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return CONTENT_MSG; };
    const char * getMD5(){ return "d454ceb7dbd72bbd7263e50d386a9436"; };

  };

  class content_msgResponse : public ros::Msg
  {
    public:
      const char* content;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_content = strlen(this->content);
      memcpy(outbuffer + offset, &length_content, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->content, length_content);
      offset += length_content;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_content;
      memcpy(&length_content, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_content; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_content-1]=0;
      this->content = (char *)(inbuffer + offset-1);
      offset += length_content;
     return offset;
    }

    const char * getType(){ return CONTENT_MSG; };
    const char * getMD5(){ return "c2e84951ee6d0addf437bfddd5b19734"; };

  };

  class content_msg {
    public:
    typedef content_msgRequest Request;
    typedef content_msgResponse Response;
  };

}
#endif
