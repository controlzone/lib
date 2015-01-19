#ifndef _ROS_sr_robot_msgs_JointMusclePositionControllerState_h
#define _ROS_sr_robot_msgs_JointMusclePositionControllerState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace sr_robot_msgs
{

  class JointMusclePositionControllerState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float set_point;
      float process_value;
      float process_value_dot;
      float error;
      float time_step;
      float pseudo_command;
      int8_t valve_muscle_0;
      int8_t valve_muscle_1;
      float packed_valve;
      uint16_t muscle_pressure_0;
      uint16_t muscle_pressure_1;
      float p;
      float i;
      float d;
      float i_clamp;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->set_point);
      offset += serializeAvrFloat64(outbuffer + offset, this->process_value);
      offset += serializeAvrFloat64(outbuffer + offset, this->process_value_dot);
      offset += serializeAvrFloat64(outbuffer + offset, this->error);
      offset += serializeAvrFloat64(outbuffer + offset, this->time_step);
      offset += serializeAvrFloat64(outbuffer + offset, this->pseudo_command);
      union {
        int8_t real;
        uint8_t base;
      } u_valve_muscle_0;
      u_valve_muscle_0.real = this->valve_muscle_0;
      *(outbuffer + offset + 0) = (u_valve_muscle_0.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->valve_muscle_0);
      union {
        int8_t real;
        uint8_t base;
      } u_valve_muscle_1;
      u_valve_muscle_1.real = this->valve_muscle_1;
      *(outbuffer + offset + 0) = (u_valve_muscle_1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->valve_muscle_1);
      offset += serializeAvrFloat64(outbuffer + offset, this->packed_valve);
      *(outbuffer + offset + 0) = (this->muscle_pressure_0 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->muscle_pressure_0 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->muscle_pressure_0);
      *(outbuffer + offset + 0) = (this->muscle_pressure_1 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->muscle_pressure_1 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->muscle_pressure_1);
      offset += serializeAvrFloat64(outbuffer + offset, this->p);
      offset += serializeAvrFloat64(outbuffer + offset, this->i);
      offset += serializeAvrFloat64(outbuffer + offset, this->d);
      offset += serializeAvrFloat64(outbuffer + offset, this->i_clamp);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->set_point));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->process_value));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->process_value_dot));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->error));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->time_step));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pseudo_command));
      union {
        int8_t real;
        uint8_t base;
      } u_valve_muscle_0;
      u_valve_muscle_0.base = 0;
      u_valve_muscle_0.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->valve_muscle_0 = u_valve_muscle_0.real;
      offset += sizeof(this->valve_muscle_0);
      union {
        int8_t real;
        uint8_t base;
      } u_valve_muscle_1;
      u_valve_muscle_1.base = 0;
      u_valve_muscle_1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->valve_muscle_1 = u_valve_muscle_1.real;
      offset += sizeof(this->valve_muscle_1);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->packed_valve));
      this->muscle_pressure_0 =  ((uint16_t) (*(inbuffer + offset)));
      this->muscle_pressure_0 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->muscle_pressure_0);
      this->muscle_pressure_1 =  ((uint16_t) (*(inbuffer + offset)));
      this->muscle_pressure_1 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->muscle_pressure_1);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->p));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->i));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->d));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->i_clamp));
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/JointMusclePositionControllerState"; };
    const char * getMD5(){ return "5a9f3e4da940842d5d2d35e00e1cd647"; };

  };

}
#endif