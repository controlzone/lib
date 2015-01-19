#ifndef _ROS_wpi_jaco_msgs_HomeArmGoal_h
#define _ROS_wpi_jaco_msgs_HomeArmGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "wpi_jaco_msgs/AngularCommand.h"

namespace wpi_jaco_msgs
{

  class HomeArmGoal : public ros::Msg
  {
    public:
      bool retract;
      wpi_jaco_msgs::AngularCommand retractPosition;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_retract;
      u_retract.real = this->retract;
      *(outbuffer + offset + 0) = (u_retract.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->retract);
      offset += this->retractPosition.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_retract;
      u_retract.base = 0;
      u_retract.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->retract = u_retract.real;
      offset += sizeof(this->retract);
      offset += this->retractPosition.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "wpi_jaco_msgs/HomeArmGoal"; };
    const char * getMD5(){ return "c6792fbeac95a62c0b0c880a65305235"; };

  };

}
#endif