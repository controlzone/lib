#ifndef _ROS_sr_robot_msgs_JointControllerState_h
#define _ROS_sr_robot_msgs_JointControllerState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace sr_robot_msgs
{

  class JointControllerState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float set_point;
      float process_value;
      float process_value_dot;
      float commanded_velocity;
      float error;
      float time_step;
      float command;
      float measured_effort;
      float friction_compensation;
      float position_p;
      float position_i;
      float position_d;
      float position_i_clamp;
      float velocity_p;
      float velocity_i;
      float velocity_d;
      float velocity_i_clamp;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->set_point);
      offset += serializeAvrFloat64(outbuffer + offset, this->process_value);
      offset += serializeAvrFloat64(outbuffer + offset, this->process_value_dot);
      offset += serializeAvrFloat64(outbuffer + offset, this->commanded_velocity);
      offset += serializeAvrFloat64(outbuffer + offset, this->error);
      offset += serializeAvrFloat64(outbuffer + offset, this->time_step);
      offset += serializeAvrFloat64(outbuffer + offset, this->command);
      offset += serializeAvrFloat64(outbuffer + offset, this->measured_effort);
      offset += serializeAvrFloat64(outbuffer + offset, this->friction_compensation);
      offset += serializeAvrFloat64(outbuffer + offset, this->position_p);
      offset += serializeAvrFloat64(outbuffer + offset, this->position_i);
      offset += serializeAvrFloat64(outbuffer + offset, this->position_d);
      offset += serializeAvrFloat64(outbuffer + offset, this->position_i_clamp);
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity_p);
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity_i);
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity_d);
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity_i_clamp);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->set_point));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->process_value));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->process_value_dot));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->commanded_velocity));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->error));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->time_step));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->command));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->measured_effort));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->friction_compensation));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position_p));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position_i));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position_d));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position_i_clamp));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velocity_p));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velocity_i));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velocity_d));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velocity_i_clamp));
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/JointControllerState"; };
    const char * getMD5(){ return "6d5ccb5452fd11516b5e350fcf60090e"; };

  };

}
#endif