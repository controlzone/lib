#ifndef _ROS_SERVICE_create_dmx_device_h
#define _ROS_SERVICE_create_dmx_device_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "lighting_msgs/DmxDevice.h"

namespace lighting_msgs
{

static const char CREATE_DMX_DEVICE[] = "lighting_msgs/create_dmx_device";

  class create_dmx_deviceRequest : public ros::Msg
  {
    public:
      lighting_msgs::DmxDevice device;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->device.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->device.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return CREATE_DMX_DEVICE; };
    const char * getMD5(){ return "6c8f7ef26cdc4ce406b0816b63c28df4"; };

  };

  class create_dmx_deviceResponse : public ros::Msg
  {
    public:
      const char* error;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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

    const char * getType(){ return CREATE_DMX_DEVICE; };
    const char * getMD5(){ return "eca8b96616c32aacf1be8bbf14c70eba"; };

  };

  class create_dmx_device {
    public:
    typedef create_dmx_deviceRequest Request;
    typedef create_dmx_deviceResponse Response;
  };

}
#endif
