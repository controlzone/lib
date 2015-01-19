#ifndef _ROS_wpi_jaco_msgs_CartesianCommand_h
#define _ROS_wpi_jaco_msgs_CartesianCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Twist.h"

namespace wpi_jaco_msgs
{

  class CartesianCommand : public ros::Msg
  {
    public:
      bool position;
      bool armCommand;
      bool fingerCommand;
      bool repeat;
      geometry_msgs::Twist arm;
      uint8_t fingers_length;
      float st_fingers;
      float * fingers;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_position;
      u_position.real = this->position;
      *(outbuffer + offset + 0) = (u_position.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->position);
      union {
        bool real;
        uint8_t base;
      } u_armCommand;
      u_armCommand.real = this->armCommand;
      *(outbuffer + offset + 0) = (u_armCommand.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->armCommand);
      union {
        bool real;
        uint8_t base;
      } u_fingerCommand;
      u_fingerCommand.real = this->fingerCommand;
      *(outbuffer + offset + 0) = (u_fingerCommand.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fingerCommand);
      union {
        bool real;
        uint8_t base;
      } u_repeat;
      u_repeat.real = this->repeat;
      *(outbuffer + offset + 0) = (u_repeat.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->repeat);
      offset += this->arm.serialize(outbuffer + offset);
      *(outbuffer + offset++) = fingers_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < fingers_length; i++){
      union {
        float real;
        uint32_t base;
      } u_fingersi;
      u_fingersi.real = this->fingers[i];
      *(outbuffer + offset + 0) = (u_fingersi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fingersi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fingersi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fingersi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fingers[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_position;
      u_position.base = 0;
      u_position.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->position = u_position.real;
      offset += sizeof(this->position);
      union {
        bool real;
        uint8_t base;
      } u_armCommand;
      u_armCommand.base = 0;
      u_armCommand.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->armCommand = u_armCommand.real;
      offset += sizeof(this->armCommand);
      union {
        bool real;
        uint8_t base;
      } u_fingerCommand;
      u_fingerCommand.base = 0;
      u_fingerCommand.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fingerCommand = u_fingerCommand.real;
      offset += sizeof(this->fingerCommand);
      union {
        bool real;
        uint8_t base;
      } u_repeat;
      u_repeat.base = 0;
      u_repeat.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->repeat = u_repeat.real;
      offset += sizeof(this->repeat);
      offset += this->arm.deserialize(inbuffer + offset);
      uint8_t fingers_lengthT = *(inbuffer + offset++);
      if(fingers_lengthT > fingers_length)
        this->fingers = (float*)realloc(this->fingers, fingers_lengthT * sizeof(float));
      offset += 3;
      fingers_length = fingers_lengthT;
      for( uint8_t i = 0; i < fingers_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_fingers;
      u_st_fingers.base = 0;
      u_st_fingers.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_fingers.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_fingers.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_fingers.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_fingers = u_st_fingers.real;
      offset += sizeof(this->st_fingers);
        memcpy( &(this->fingers[i]), &(this->st_fingers), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "wpi_jaco_msgs/CartesianCommand"; };
    const char * getMD5(){ return "be41abcf10fd0ff2a0ead4293f8dfdf1"; };

  };

}
#endif