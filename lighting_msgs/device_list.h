#ifndef _ROS_SERVICE_device_list_h
#define _ROS_SERVICE_device_list_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "lighting_msgs/DmxDevice.h"

namespace lighting_msgs
{

static const char DEVICE_LIST[] = "lighting_msgs/device_list";

  class device_listRequest : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return DEVICE_LIST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class device_listResponse : public ros::Msg
  {
    public:
      uint8_t devices_length;
      lighting_msgs::DmxDevice st_devices;
      lighting_msgs::DmxDevice * devices;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = devices_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < devices_length; i++){
      offset += this->devices[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t devices_lengthT = *(inbuffer + offset++);
      if(devices_lengthT > devices_length)
        this->devices = (lighting_msgs::DmxDevice*)realloc(this->devices, devices_lengthT * sizeof(lighting_msgs::DmxDevice));
      offset += 3;
      devices_length = devices_lengthT;
      for( uint8_t i = 0; i < devices_length; i++){
      offset += this->st_devices.deserialize(inbuffer + offset);
        memcpy( &(this->devices[i]), &(this->st_devices), sizeof(lighting_msgs::DmxDevice));
      }
     return offset;
    }

    const char * getType(){ return DEVICE_LIST; };
    const char * getMD5(){ return "25138fc93d5c296af2bf7ff8186d0653"; };

  };

  class device_list {
    public:
    typedef device_listRequest Request;
    typedef device_listResponse Response;
  };

}
#endif
