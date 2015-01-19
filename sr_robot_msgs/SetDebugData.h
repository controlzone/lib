#ifndef _ROS_SERVICE_SetDebugData_h
#define _ROS_SERVICE_SetDebugData_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_robot_msgs
{

static const char SETDEBUGDATA[] = "sr_robot_msgs/SetDebugData";

  class SetDebugDataRequest : public ros::Msg
  {
    public:
      int16_t motor_index;
      int16_t motor_data_type;
      int16_t publisher_index;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_motor_index;
      u_motor_index.real = this->motor_index;
      *(outbuffer + offset + 0) = (u_motor_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_index.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->motor_index);
      union {
        int16_t real;
        uint16_t base;
      } u_motor_data_type;
      u_motor_data_type.real = this->motor_data_type;
      *(outbuffer + offset + 0) = (u_motor_data_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_data_type.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->motor_data_type);
      union {
        int16_t real;
        uint16_t base;
      } u_publisher_index;
      u_publisher_index.real = this->publisher_index;
      *(outbuffer + offset + 0) = (u_publisher_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_publisher_index.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->publisher_index);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_motor_index;
      u_motor_index.base = 0;
      u_motor_index.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor_index.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->motor_index = u_motor_index.real;
      offset += sizeof(this->motor_index);
      union {
        int16_t real;
        uint16_t base;
      } u_motor_data_type;
      u_motor_data_type.base = 0;
      u_motor_data_type.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor_data_type.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->motor_data_type = u_motor_data_type.real;
      offset += sizeof(this->motor_data_type);
      union {
        int16_t real;
        uint16_t base;
      } u_publisher_index;
      u_publisher_index.base = 0;
      u_publisher_index.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_publisher_index.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->publisher_index = u_publisher_index.real;
      offset += sizeof(this->publisher_index);
     return offset;
    }

    const char * getType(){ return SETDEBUGDATA; };
    const char * getMD5(){ return "9f31db3c8e178b58a93d06e8bde6a17a"; };

  };

  class SetDebugDataResponse : public ros::Msg
  {
    public:
      bool success;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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

    const char * getType(){ return SETDEBUGDATA; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SetDebugData {
    public:
    typedef SetDebugDataRequest Request;
    typedef SetDebugDataResponse Response;
  };

}
#endif
