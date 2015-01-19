#ifndef _ROS_wpi_jaco_msgs_ExecuteGraspGoal_h
#define _ROS_wpi_jaco_msgs_ExecuteGraspGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "wpi_jaco_msgs/JacoFingerVel.h"

namespace wpi_jaco_msgs
{

  class ExecuteGraspGoal : public ros::Msg
  {
    public:
      bool closeGripper;
      bool limitFingerVelocity;
      wpi_jaco_msgs::JacoFingerVel fingerVelocities;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_closeGripper;
      u_closeGripper.real = this->closeGripper;
      *(outbuffer + offset + 0) = (u_closeGripper.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->closeGripper);
      union {
        bool real;
        uint8_t base;
      } u_limitFingerVelocity;
      u_limitFingerVelocity.real = this->limitFingerVelocity;
      *(outbuffer + offset + 0) = (u_limitFingerVelocity.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->limitFingerVelocity);
      offset += this->fingerVelocities.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_closeGripper;
      u_closeGripper.base = 0;
      u_closeGripper.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->closeGripper = u_closeGripper.real;
      offset += sizeof(this->closeGripper);
      union {
        bool real;
        uint8_t base;
      } u_limitFingerVelocity;
      u_limitFingerVelocity.base = 0;
      u_limitFingerVelocity.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->limitFingerVelocity = u_limitFingerVelocity.real;
      offset += sizeof(this->limitFingerVelocity);
      offset += this->fingerVelocities.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "wpi_jaco_msgs/ExecuteGraspGoal"; };
    const char * getMD5(){ return "bb631f166a53295e0fc70edf97f55abf"; };

  };

}
#endif