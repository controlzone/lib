#ifndef _ROS_sr_robot_msgs_FromMotorDataType_h
#define _ROS_sr_robot_msgs_FromMotorDataType_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_robot_msgs
{

  class FromMotorDataType : public ros::Msg
  {
    public:
      int16_t data;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_data;
      u_data.real = this->data;
      *(outbuffer + offset + 0) = (u_data.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_data.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_data;
      u_data.base = 0;
      u_data.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_data.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->data = u_data.real;
      offset += sizeof(this->data);
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/FromMotorDataType"; };
    const char * getMD5(){ return "8524586e34fbd7cb1c08c5f5f1ca0e57"; };

  };

}
#endif