#ifndef _ROS_SERVICE_JacoFK_h
#define _ROS_SERVICE_JacoFK_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace wpi_jaco_msgs
{

static const char JACOFK[] = "wpi_jaco_msgs/JacoFK";

  class JacoFKRequest : public ros::Msg
  {
    public:
      uint8_t joints_length;
      float st_joints;
      float * joints;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = joints_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joints_length; i++){
      union {
        float real;
        uint32_t base;
      } u_jointsi;
      u_jointsi.real = this->joints[i];
      *(outbuffer + offset + 0) = (u_jointsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_jointsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_jointsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_jointsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->joints[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t joints_lengthT = *(inbuffer + offset++);
      if(joints_lengthT > joints_length)
        this->joints = (float*)realloc(this->joints, joints_lengthT * sizeof(float));
      offset += 3;
      joints_length = joints_lengthT;
      for( uint8_t i = 0; i < joints_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_joints;
      u_st_joints.base = 0;
      u_st_joints.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_joints.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_joints.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_joints.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_joints = u_st_joints.real;
      offset += sizeof(this->st_joints);
        memcpy( &(this->joints[i]), &(this->st_joints), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return JACOFK; };
    const char * getMD5(){ return "e2a0e438b445b98def0f0ba6a2a85f58"; };

  };

  class JacoFKResponse : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped handPose;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->handPose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->handPose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return JACOFK; };
    const char * getMD5(){ return "61d04f48613e36ee5ea5469d2bfc4c7f"; };

  };

  class JacoFK {
    public:
    typedef JacoFKRequest Request;
    typedef JacoFKResponse Response;
  };

}
#endif
