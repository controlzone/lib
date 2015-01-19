#ifndef _ROS_SERVICE_CallIK_h
#define _ROS_SERVICE_CallIK_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace carl_moveit
{

static const char CALLIK[] = "carl_moveit/CallIK";

  class CallIKRequest : public ros::Msg
  {
    public:
      geometry_msgs::Pose pose;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return CALLIK; };
    const char * getMD5(){ return "f192399f711a48924df9a394d37edd67"; };

  };

  class CallIKResponse : public ros::Msg
  {
    public:
      uint8_t jointPositions_length;
      float st_jointPositions;
      float * jointPositions;
      bool success;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = jointPositions_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < jointPositions_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->jointPositions[i]);
      }
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
      uint8_t jointPositions_lengthT = *(inbuffer + offset++);
      if(jointPositions_lengthT > jointPositions_length)
        this->jointPositions = (float*)realloc(this->jointPositions, jointPositions_lengthT * sizeof(float));
      offset += 3;
      jointPositions_length = jointPositions_lengthT;
      for( uint8_t i = 0; i < jointPositions_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_jointPositions));
        memcpy( &(this->jointPositions[i]), &(this->st_jointPositions), sizeof(float));
      }
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

    const char * getType(){ return CALLIK; };
    const char * getMD5(){ return "2ce36d247dfbec462f247fb79bee8da9"; };

  };

  class CallIK {
    public:
    typedef CallIKRequest Request;
    typedef CallIKResponse Response;
  };

}
#endif
