#ifndef _ROS_SERVICE_PickupSegmentedObject_h
#define _ROS_SERVICE_PickupSegmentedObject_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rail_pick_and_place_msgs
{

static const char PICKUPSEGMENTEDOBJECT[] = "rail_pick_and_place_msgs/PickupSegmentedObject";

  class PickupSegmentedObjectRequest : public ros::Msg
  {
    public:
      int32_t objectIndex;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_objectIndex;
      u_objectIndex.real = this->objectIndex;
      *(outbuffer + offset + 0) = (u_objectIndex.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_objectIndex.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_objectIndex.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_objectIndex.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->objectIndex);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_objectIndex;
      u_objectIndex.base = 0;
      u_objectIndex.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_objectIndex.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_objectIndex.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_objectIndex.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->objectIndex = u_objectIndex.real;
      offset += sizeof(this->objectIndex);
     return offset;
    }

    const char * getType(){ return PICKUPSEGMENTEDOBJECT; };
    const char * getMD5(){ return "c149f81455b67f790d5a6bc184a4cbaf"; };

  };

  class PickupSegmentedObjectResponse : public ros::Msg
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

    const char * getType(){ return PICKUPSEGMENTEDOBJECT; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class PickupSegmentedObject {
    public:
    typedef PickupSegmentedObjectRequest Request;
    typedef PickupSegmentedObjectResponse Response;
  };

}
#endif
