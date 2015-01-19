#ifndef _ROS_SERVICE_PerceiveEquipment_h
#define _ROS_SERVICE_PerceiveEquipment_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "saphari_msgs/PerceivedEquipment.h"

namespace saphari_msgs
{

static const char PERCEIVEEQUIPMENT[] = "saphari_msgs/PerceiveEquipment";

  class PerceiveEquipmentRequest : public ros::Msg
  {
    public:
      const char* request;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_request = strlen(this->request);
      memcpy(outbuffer + offset, &length_request, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->request, length_request);
      offset += length_request;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_request;
      memcpy(&length_request, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_request; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_request-1]=0;
      this->request = (char *)(inbuffer + offset-1);
      offset += length_request;
     return offset;
    }

    const char * getType(){ return PERCEIVEEQUIPMENT; };
    const char * getMD5(){ return "9b13f31f7a0a36901919f7ec0d9f40d4"; };

  };

  class PerceiveEquipmentResponse : public ros::Msg
  {
    public:
      saphari_msgs::PerceivedEquipment result;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return PERCEIVEEQUIPMENT; };
    const char * getMD5(){ return "3009b2394cb71843fdc471eb6990ed2f"; };

  };

  class PerceiveEquipment {
    public:
    typedef PerceiveEquipmentRequest Request;
    typedef PerceiveEquipmentResponse Response;
  };

}
#endif
