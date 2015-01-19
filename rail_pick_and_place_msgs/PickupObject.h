#ifndef _ROS_SERVICE_PickupObject_h
#define _ROS_SERVICE_PickupObject_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rail_pick_and_place_msgs
{

static const char PICKUPOBJECT[] = "rail_pick_and_place_msgs/PickupObject";

  class PickupObjectRequest : public ros::Msg
  {
    public:
      const char* objectName;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_objectName = strlen(this->objectName);
      memcpy(outbuffer + offset, &length_objectName, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->objectName, length_objectName);
      offset += length_objectName;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_objectName;
      memcpy(&length_objectName, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_objectName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_objectName-1]=0;
      this->objectName = (char *)(inbuffer + offset-1);
      offset += length_objectName;
     return offset;
    }

    const char * getType(){ return PICKUPOBJECT; };
    const char * getMD5(){ return "5d6700ec420d7f32e8dc7b117e3b8b51"; };

  };

  class PickupObjectResponse : public ros::Msg
  {
    public:
      bool success;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return PICKUPOBJECT; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class PickupObject {
    public:
    typedef PickupObjectRequest Request;
    typedef PickupObjectResponse Response;
  };

}
#endif
