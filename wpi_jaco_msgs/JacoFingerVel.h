#ifndef _ROS_wpi_jaco_msgs_JacoFingerVel_h
#define _ROS_wpi_jaco_msgs_JacoFingerVel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace wpi_jaco_msgs
{

  class JacoFingerVel : public ros::Msg
  {
    public:
      float finger1Vel;
      float finger2Vel;
      float finger3Vel;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_finger1Vel;
      u_finger1Vel.real = this->finger1Vel;
      *(outbuffer + offset + 0) = (u_finger1Vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_finger1Vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_finger1Vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_finger1Vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->finger1Vel);
      union {
        float real;
        uint32_t base;
      } u_finger2Vel;
      u_finger2Vel.real = this->finger2Vel;
      *(outbuffer + offset + 0) = (u_finger2Vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_finger2Vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_finger2Vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_finger2Vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->finger2Vel);
      union {
        float real;
        uint32_t base;
      } u_finger3Vel;
      u_finger3Vel.real = this->finger3Vel;
      *(outbuffer + offset + 0) = (u_finger3Vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_finger3Vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_finger3Vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_finger3Vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->finger3Vel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_finger1Vel;
      u_finger1Vel.base = 0;
      u_finger1Vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_finger1Vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_finger1Vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_finger1Vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->finger1Vel = u_finger1Vel.real;
      offset += sizeof(this->finger1Vel);
      union {
        float real;
        uint32_t base;
      } u_finger2Vel;
      u_finger2Vel.base = 0;
      u_finger2Vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_finger2Vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_finger2Vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_finger2Vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->finger2Vel = u_finger2Vel.real;
      offset += sizeof(this->finger2Vel);
      union {
        float real;
        uint32_t base;
      } u_finger3Vel;
      u_finger3Vel.base = 0;
      u_finger3Vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_finger3Vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_finger3Vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_finger3Vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->finger3Vel = u_finger3Vel.real;
      offset += sizeof(this->finger3Vel);
     return offset;
    }

    const char * getType(){ return "wpi_jaco_msgs/JacoFingerVel"; };
    const char * getMD5(){ return "a931e1014161865b6137e2ee19991131"; };

  };

}
#endif