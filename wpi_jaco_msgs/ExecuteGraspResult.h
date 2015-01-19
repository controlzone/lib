#ifndef _ROS_wpi_jaco_msgs_ExecuteGraspResult_h
#define _ROS_wpi_jaco_msgs_ExecuteGraspResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace wpi_jaco_msgs
{

  class ExecuteGraspResult : public ros::Msg
  {
    public:
      uint8_t fingerJoints_length;
      float st_fingerJoints;
      float * fingerJoints;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = fingerJoints_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < fingerJoints_length; i++){
      union {
        float real;
        uint32_t base;
      } u_fingerJointsi;
      u_fingerJointsi.real = this->fingerJoints[i];
      *(outbuffer + offset + 0) = (u_fingerJointsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fingerJointsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fingerJointsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fingerJointsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fingerJoints[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t fingerJoints_lengthT = *(inbuffer + offset++);
      if(fingerJoints_lengthT > fingerJoints_length)
        this->fingerJoints = (float*)realloc(this->fingerJoints, fingerJoints_lengthT * sizeof(float));
      offset += 3;
      fingerJoints_length = fingerJoints_lengthT;
      for( uint8_t i = 0; i < fingerJoints_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_fingerJoints;
      u_st_fingerJoints.base = 0;
      u_st_fingerJoints.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_fingerJoints.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_fingerJoints.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_fingerJoints.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_fingerJoints = u_st_fingerJoints.real;
      offset += sizeof(this->st_fingerJoints);
        memcpy( &(this->fingerJoints[i]), &(this->st_fingerJoints), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "wpi_jaco_msgs/ExecuteGraspResult"; };
    const char * getMD5(){ return "f99f967b7793b1298d9e1fdee7ac4a46"; };

  };

}
#endif