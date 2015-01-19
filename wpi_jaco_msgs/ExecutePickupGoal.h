#ifndef _ROS_wpi_jaco_msgs_ExecutePickupGoal_h
#define _ROS_wpi_jaco_msgs_ExecutePickupGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "wpi_jaco_msgs/JacoFingerVel.h"

namespace wpi_jaco_msgs
{

  class ExecutePickupGoal : public ros::Msg
  {
    public:
      bool limitFingerVelocity;
      wpi_jaco_msgs::JacoFingerVel fingerVelocities;
      bool setLiftVelocity;
      float liftVelocity;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_limitFingerVelocity;
      u_limitFingerVelocity.real = this->limitFingerVelocity;
      *(outbuffer + offset + 0) = (u_limitFingerVelocity.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->limitFingerVelocity);
      offset += this->fingerVelocities.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_setLiftVelocity;
      u_setLiftVelocity.real = this->setLiftVelocity;
      *(outbuffer + offset + 0) = (u_setLiftVelocity.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->setLiftVelocity);
      union {
        float real;
        uint32_t base;
      } u_liftVelocity;
      u_liftVelocity.real = this->liftVelocity;
      *(outbuffer + offset + 0) = (u_liftVelocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_liftVelocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_liftVelocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_liftVelocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->liftVelocity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_limitFingerVelocity;
      u_limitFingerVelocity.base = 0;
      u_limitFingerVelocity.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->limitFingerVelocity = u_limitFingerVelocity.real;
      offset += sizeof(this->limitFingerVelocity);
      offset += this->fingerVelocities.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_setLiftVelocity;
      u_setLiftVelocity.base = 0;
      u_setLiftVelocity.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->setLiftVelocity = u_setLiftVelocity.real;
      offset += sizeof(this->setLiftVelocity);
      union {
        float real;
        uint32_t base;
      } u_liftVelocity;
      u_liftVelocity.base = 0;
      u_liftVelocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_liftVelocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_liftVelocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_liftVelocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->liftVelocity = u_liftVelocity.real;
      offset += sizeof(this->liftVelocity);
     return offset;
    }

    const char * getType(){ return "wpi_jaco_msgs/ExecutePickupGoal"; };
    const char * getMD5(){ return "e2acaa6a7ab37316a00dbd78901291d8"; };

  };

}
#endif