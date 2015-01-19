#ifndef _ROS_SERVICE_set_pixelmap_h
#define _ROS_SERVICE_set_pixelmap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace lighting_msgs
{

static const char SET_PIXELMAP[] = "lighting_msgs/set_pixelmap";

  class set_pixelmapRequest : public ros::Msg
  {
    public:
      const char* device_name;
      const char* mapping;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_device_name = strlen(this->device_name);
      memcpy(outbuffer + offset, &length_device_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->device_name, length_device_name);
      offset += length_device_name;
      uint32_t length_mapping = strlen(this->mapping);
      memcpy(outbuffer + offset, &length_mapping, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->mapping, length_mapping);
      offset += length_mapping;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_device_name;
      memcpy(&length_device_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_device_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_device_name-1]=0;
      this->device_name = (char *)(inbuffer + offset-1);
      offset += length_device_name;
      uint32_t length_mapping;
      memcpy(&length_mapping, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mapping; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mapping-1]=0;
      this->mapping = (char *)(inbuffer + offset-1);
      offset += length_mapping;
     return offset;
    }

    const char * getType(){ return SET_PIXELMAP; };
    const char * getMD5(){ return "a1cdc71242a71f038ec35f92dbcbe297"; };

  };

  class set_pixelmapResponse : public ros::Msg
  {
    public:
      const char* topic;
      const char* error;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_topic = strlen(this->topic);
      memcpy(outbuffer + offset, &length_topic, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->topic, length_topic);
      offset += length_topic;
      uint32_t length_error = strlen(this->error);
      memcpy(outbuffer + offset, &length_error, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->error, length_error);
      offset += length_error;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_topic;
      memcpy(&length_topic, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topic-1]=0;
      this->topic = (char *)(inbuffer + offset-1);
      offset += length_topic;
      uint32_t length_error;
      memcpy(&length_error, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error-1]=0;
      this->error = (char *)(inbuffer + offset-1);
      offset += length_error;
     return offset;
    }

    const char * getType(){ return SET_PIXELMAP; };
    const char * getMD5(){ return "4a553c2592911c81abc80f56f55f33c7"; };

  };

  class set_pixelmap {
    public:
    typedef set_pixelmapRequest Request;
    typedef set_pixelmapResponse Response;
  };

}
#endif
