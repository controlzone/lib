#ifndef _ROS_sr_robot_msgs_JointMuscleValveControllerState_h
#define _ROS_sr_robot_msgs_JointMuscleValveControllerState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace sr_robot_msgs
{

  class JointMuscleValveControllerState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int8_t set_valve_muscle_0;
      int8_t set_valve_muscle_1;
      uint64_t set_duration_muscle_0;
      uint64_t set_duration_muscle_1;
      int8_t current_valve_muscle_0;
      int8_t current_valve_muscle_1;
      uint64_t current_duration_muscle_0;
      uint64_t current_duration_muscle_1;
      float packed_valve;
      uint16_t muscle_pressure_0;
      uint16_t muscle_pressure_1;
      float time_step;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_set_valve_muscle_0;
      u_set_valve_muscle_0.real = this->set_valve_muscle_0;
      *(outbuffer + offset + 0) = (u_set_valve_muscle_0.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_valve_muscle_0);
      union {
        int8_t real;
        uint8_t base;
      } u_set_valve_muscle_1;
      u_set_valve_muscle_1.real = this->set_valve_muscle_1;
      *(outbuffer + offset + 0) = (u_set_valve_muscle_1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_valve_muscle_1);
      union {
        uint64_t real;
        uint32_t base;
      } u_set_duration_muscle_0;
      u_set_duration_muscle_0.real = this->set_duration_muscle_0;
      *(outbuffer + offset + 0) = (u_set_duration_muscle_0.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_set_duration_muscle_0.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_set_duration_muscle_0.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_set_duration_muscle_0.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->set_duration_muscle_0);
      union {
        uint64_t real;
        uint32_t base;
      } u_set_duration_muscle_1;
      u_set_duration_muscle_1.real = this->set_duration_muscle_1;
      *(outbuffer + offset + 0) = (u_set_duration_muscle_1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_set_duration_muscle_1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_set_duration_muscle_1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_set_duration_muscle_1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->set_duration_muscle_1);
      union {
        int8_t real;
        uint8_t base;
      } u_current_valve_muscle_0;
      u_current_valve_muscle_0.real = this->current_valve_muscle_0;
      *(outbuffer + offset + 0) = (u_current_valve_muscle_0.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->current_valve_muscle_0);
      union {
        int8_t real;
        uint8_t base;
      } u_current_valve_muscle_1;
      u_current_valve_muscle_1.real = this->current_valve_muscle_1;
      *(outbuffer + offset + 0) = (u_current_valve_muscle_1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->current_valve_muscle_1);
      union {
        uint64_t real;
        uint32_t base;
      } u_current_duration_muscle_0;
      u_current_duration_muscle_0.real = this->current_duration_muscle_0;
      *(outbuffer + offset + 0) = (u_current_duration_muscle_0.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_duration_muscle_0.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_duration_muscle_0.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_duration_muscle_0.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_duration_muscle_0);
      union {
        uint64_t real;
        uint32_t base;
      } u_current_duration_muscle_1;
      u_current_duration_muscle_1.real = this->current_duration_muscle_1;
      *(outbuffer + offset + 0) = (u_current_duration_muscle_1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_duration_muscle_1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_duration_muscle_1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_duration_muscle_1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_duration_muscle_1);
      offset += serializeAvrFloat64(outbuffer + offset, this->packed_valve);
      *(outbuffer + offset + 0) = (this->muscle_pressure_0 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->muscle_pressure_0 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->muscle_pressure_0);
      *(outbuffer + offset + 0) = (this->muscle_pressure_1 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->muscle_pressure_1 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->muscle_pressure_1);
      offset += serializeAvrFloat64(outbuffer + offset, this->time_step);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_set_valve_muscle_0;
      u_set_valve_muscle_0.base = 0;
      u_set_valve_muscle_0.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->set_valve_muscle_0 = u_set_valve_muscle_0.real;
      offset += sizeof(this->set_valve_muscle_0);
      union {
        int8_t real;
        uint8_t base;
      } u_set_valve_muscle_1;
      u_set_valve_muscle_1.base = 0;
      u_set_valve_muscle_1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->set_valve_muscle_1 = u_set_valve_muscle_1.real;
      offset += sizeof(this->set_valve_muscle_1);
      union {
        uint64_t real;
        uint32_t base;
      } u_set_duration_muscle_0;
      u_set_duration_muscle_0.base = 0;
      u_set_duration_muscle_0.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_set_duration_muscle_0.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_set_duration_muscle_0.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_set_duration_muscle_0.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->set_duration_muscle_0 = u_set_duration_muscle_0.real;
      offset += sizeof(this->set_duration_muscle_0);
      union {
        uint64_t real;
        uint32_t base;
      } u_set_duration_muscle_1;
      u_set_duration_muscle_1.base = 0;
      u_set_duration_muscle_1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_set_duration_muscle_1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_set_duration_muscle_1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_set_duration_muscle_1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->set_duration_muscle_1 = u_set_duration_muscle_1.real;
      offset += sizeof(this->set_duration_muscle_1);
      union {
        int8_t real;
        uint8_t base;
      } u_current_valve_muscle_0;
      u_current_valve_muscle_0.base = 0;
      u_current_valve_muscle_0.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->current_valve_muscle_0 = u_current_valve_muscle_0.real;
      offset += sizeof(this->current_valve_muscle_0);
      union {
        int8_t real;
        uint8_t base;
      } u_current_valve_muscle_1;
      u_current_valve_muscle_1.base = 0;
      u_current_valve_muscle_1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->current_valve_muscle_1 = u_current_valve_muscle_1.real;
      offset += sizeof(this->current_valve_muscle_1);
      union {
        uint64_t real;
        uint32_t base;
      } u_current_duration_muscle_0;
      u_current_duration_muscle_0.base = 0;
      u_current_duration_muscle_0.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_duration_muscle_0.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_duration_muscle_0.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_duration_muscle_0.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_duration_muscle_0 = u_current_duration_muscle_0.real;
      offset += sizeof(this->current_duration_muscle_0);
      union {
        uint64_t real;
        uint32_t base;
      } u_current_duration_muscle_1;
      u_current_duration_muscle_1.base = 0;
      u_current_duration_muscle_1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_duration_muscle_1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_duration_muscle_1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_duration_muscle_1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_duration_muscle_1 = u_current_duration_muscle_1.real;
      offset += sizeof(this->current_duration_muscle_1);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->packed_valve));
      this->muscle_pressure_0 =  ((uint16_t) (*(inbuffer + offset)));
      this->muscle_pressure_0 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->muscle_pressure_0);
      this->muscle_pressure_1 =  ((uint16_t) (*(inbuffer + offset)));
      this->muscle_pressure_1 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->muscle_pressure_1);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->time_step));
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/JointMuscleValveControllerState"; };
    const char * getMD5(){ return "fc22942516cdb4d514558e60d7263d35"; };

  };

}
#endif