#ifndef _ROS_neo_msgs_PowerState_h
#define _ROS_neo_msgs_PowerState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/duration.h"

namespace neo_msgs
{

  class PowerState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float power_consumption;
      ros::Duration time_remaining;
      const char* prediction_method;
      int8_t relative_capacity;
      int8_t AC_present;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->power_consumption);
      *(outbuffer + offset + 0) = (this->time_remaining.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_remaining.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_remaining.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_remaining.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_remaining.sec);
      *(outbuffer + offset + 0) = (this->time_remaining.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_remaining.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_remaining.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_remaining.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_remaining.nsec);
      uint32_t length_prediction_method = strlen(this->prediction_method);
      memcpy(outbuffer + offset, &length_prediction_method, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->prediction_method, length_prediction_method);
      offset += length_prediction_method;
      union {
        int8_t real;
        uint8_t base;
      } u_relative_capacity;
      u_relative_capacity.real = this->relative_capacity;
      *(outbuffer + offset + 0) = (u_relative_capacity.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->relative_capacity);
      union {
        int8_t real;
        uint8_t base;
      } u_AC_present;
      u_AC_present.real = this->AC_present;
      *(outbuffer + offset + 0) = (u_AC_present.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->AC_present);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->power_consumption));
      this->time_remaining.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_remaining.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_remaining.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_remaining.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_remaining.sec);
      this->time_remaining.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_remaining.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_remaining.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_remaining.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_remaining.nsec);
      uint32_t length_prediction_method;
      memcpy(&length_prediction_method, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_prediction_method; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_prediction_method-1]=0;
      this->prediction_method = (char *)(inbuffer + offset-1);
      offset += length_prediction_method;
      union {
        int8_t real;
        uint8_t base;
      } u_relative_capacity;
      u_relative_capacity.base = 0;
      u_relative_capacity.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->relative_capacity = u_relative_capacity.real;
      offset += sizeof(this->relative_capacity);
      union {
        int8_t real;
        uint8_t base;
      } u_AC_present;
      u_AC_present.base = 0;
      u_AC_present.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->AC_present = u_AC_present.real;
      offset += sizeof(this->AC_present);
     return offset;
    }

    const char * getType(){ return "neo_msgs/PowerState"; };
    const char * getMD5(){ return "e6fa46a387cad0b7a80959a21587a6c9"; };

  };

}
#endif