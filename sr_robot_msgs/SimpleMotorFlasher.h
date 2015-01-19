#ifndef _ROS_SERVICE_SimpleMotorFlasher_h
#define _ROS_SERVICE_SimpleMotorFlasher_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_robot_msgs
{

static const char SIMPLEMOTORFLASHER[] = "sr_robot_msgs/SimpleMotorFlasher";

  class SimpleMotorFlasherRequest : public ros::Msg
  {
    public:
      const char* firmware;
      int8_t motor_id;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_firmware = strlen(this->firmware);
      memcpy(outbuffer + offset, &length_firmware, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->firmware, length_firmware);
      offset += length_firmware;
      union {
        int8_t real;
        uint8_t base;
      } u_motor_id;
      u_motor_id.real = this->motor_id;
      *(outbuffer + offset + 0) = (u_motor_id.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_firmware;
      memcpy(&length_firmware, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_firmware; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_firmware-1]=0;
      this->firmware = (char *)(inbuffer + offset-1);
      offset += length_firmware;
      union {
        int8_t real;
        uint8_t base;
      } u_motor_id;
      u_motor_id.base = 0;
      u_motor_id.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->motor_id = u_motor_id.real;
      offset += sizeof(this->motor_id);
     return offset;
    }

    const char * getType(){ return SIMPLEMOTORFLASHER; };
    const char * getMD5(){ return "95979d9c30a49ed16e3ab17fe0edb157"; };

  };

  class SimpleMotorFlasherResponse : public ros::Msg
  {
    public:
      int32_t value;
      enum { SUCCESS =  0 };
      enum { FAIL =  1 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->value = u_value.real;
      offset += sizeof(this->value);
     return offset;
    }

    const char * getType(){ return SIMPLEMOTORFLASHER; };
    const char * getMD5(){ return "57a3be4812415ba24758cca00aebf53f"; };

  };

  class SimpleMotorFlasher {
    public:
    typedef SimpleMotorFlasherRequest Request;
    typedef SimpleMotorFlasherResponse Response;
  };

}
#endif
