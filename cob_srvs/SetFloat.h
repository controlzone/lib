#ifndef _ROS_SERVICE_SetFloat_h
#define _ROS_SERVICE_SetFloat_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace cob_srvs
{

static const char SETFLOAT[] = "cob_srvs/SetFloat";

  class SetFloatRequest : public ros::Msg
  {
    public:
      float data;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_data;
      u_data.real = this->data;
      *(outbuffer + offset + 0) = (u_data.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_data.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_data.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_data.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_data;
      u_data.base = 0;
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->data = u_data.real;
      offset += sizeof(this->data);
     return offset;
    }

    const char * getType(){ return SETFLOAT; };
    const char * getMD5(){ return "73fcbf46b49191e672908e50842a83d4"; };

  };

  class SetFloatResponse : public ros::Msg
  {
    public:
      bool success;
      std_msgs::String errorMessage;

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
      offset += this->errorMessage.serialize(outbuffer + offset);
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
      offset += this->errorMessage.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETFLOAT; };
    const char * getMD5(){ return "c3b62f691308002270bd6702fd7da94b"; };

  };

  class SetFloat {
    public:
    typedef SetFloatRequest Request;
    typedef SetFloatResponse Response;
  };

}
#endif
