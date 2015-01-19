#ifndef _ROS_SERVICE_TestService_h
#define _ROS_SERVICE_TestService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "std_msgs/Header.h"

namespace sherlock_sim_msgs
{

static const char TESTSERVICE[] = "sherlock_sim_msgs/TestService";

  class TestServiceRequest : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Pose pose;
      int32_t id;
      const char* modelName;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      uint32_t length_modelName = strlen(this->modelName);
      memcpy(outbuffer + offset, &length_modelName, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->modelName, length_modelName);
      offset += length_modelName;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
      uint32_t length_modelName;
      memcpy(&length_modelName, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_modelName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_modelName-1]=0;
      this->modelName = (char *)(inbuffer + offset-1);
      offset += length_modelName;
     return offset;
    }

    const char * getType(){ return TESTSERVICE; };
    const char * getMD5(){ return "8b0ae118f0c3e813da7c0093ca8ecadb"; };

  };

  class TestServiceResponse : public ros::Msg
  {
    public:
      bool flag;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_flag;
      u_flag.real = this->flag;
      *(outbuffer + offset + 0) = (u_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->flag);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_flag;
      u_flag.base = 0;
      u_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->flag = u_flag.real;
      offset += sizeof(this->flag);
     return offset;
    }

    const char * getType(){ return TESTSERVICE; };
    const char * getMD5(){ return "24842bc754e0f5cc982338eca1269251"; };

  };

  class TestService {
    public:
    typedef TestServiceRequest Request;
    typedef TestServiceResponse Response;
  };

}
#endif
