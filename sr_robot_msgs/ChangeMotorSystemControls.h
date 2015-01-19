#ifndef _ROS_SERVICE_ChangeMotorSystemControls_h
#define _ROS_SERVICE_ChangeMotorSystemControls_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sr_robot_msgs/MotorSystemControls.h"

namespace sr_robot_msgs
{

static const char CHANGEMOTORSYSTEMCONTROLS[] = "sr_robot_msgs/ChangeMotorSystemControls";

  class ChangeMotorSystemControlsRequest : public ros::Msg
  {
    public:
      uint8_t motor_system_controls_length;
      sr_robot_msgs::MotorSystemControls st_motor_system_controls;
      sr_robot_msgs::MotorSystemControls * motor_system_controls;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = motor_system_controls_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < motor_system_controls_length; i++){
      offset += this->motor_system_controls[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t motor_system_controls_lengthT = *(inbuffer + offset++);
      if(motor_system_controls_lengthT > motor_system_controls_length)
        this->motor_system_controls = (sr_robot_msgs::MotorSystemControls*)realloc(this->motor_system_controls, motor_system_controls_lengthT * sizeof(sr_robot_msgs::MotorSystemControls));
      offset += 3;
      motor_system_controls_length = motor_system_controls_lengthT;
      for( uint8_t i = 0; i < motor_system_controls_length; i++){
      offset += this->st_motor_system_controls.deserialize(inbuffer + offset);
        memcpy( &(this->motor_system_controls[i]), &(this->st_motor_system_controls), sizeof(sr_robot_msgs::MotorSystemControls));
      }
     return offset;
    }

    const char * getType(){ return CHANGEMOTORSYSTEMCONTROLS; };
    const char * getMD5(){ return "6458c2239125c960f4d1ef4d23696a1e"; };

  };

  class ChangeMotorSystemControlsResponse : public ros::Msg
  {
    public:
      int8_t result;
      enum { SUCCESS = 0 };
      enum { MOTOR_ID_OUT_OF_RANGE = -1 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return CHANGEMOTORSYSTEMCONTROLS; };
    const char * getMD5(){ return "5dade9e97a517a3f230ed76028e54c71"; };

  };

  class ChangeMotorSystemControls {
    public:
    typedef ChangeMotorSystemControlsRequest Request;
    typedef ChangeMotorSystemControlsResponse Response;
  };

}
#endif
