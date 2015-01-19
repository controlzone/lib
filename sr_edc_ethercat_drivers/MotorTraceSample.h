#ifndef _ROS_sr_edc_ethercat_drivers_MotorTraceSample_h
#define _ROS_sr_edc_ethercat_drivers_MotorTraceSample_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_edc_ethercat_drivers
{

  class MotorTraceSample : public ros::Msg
  {
    public:
      float commanded_effort;
      float slow_effort_limit;
      float quick_effort_limit;
      float motor_current;
      float motor_supply_voltage;
      float hbridge_duty;
      float temperature;
      float force_sensor_1;
      float force_sensor_2;
      float force_sensor_3;
      float motor_velocity;
      float velocity;
      float position;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->commanded_effort);
      offset += serializeAvrFloat64(outbuffer + offset, this->slow_effort_limit);
      offset += serializeAvrFloat64(outbuffer + offset, this->quick_effort_limit);
      offset += serializeAvrFloat64(outbuffer + offset, this->motor_current);
      offset += serializeAvrFloat64(outbuffer + offset, this->motor_supply_voltage);
      offset += serializeAvrFloat64(outbuffer + offset, this->hbridge_duty);
      offset += serializeAvrFloat64(outbuffer + offset, this->temperature);
      offset += serializeAvrFloat64(outbuffer + offset, this->force_sensor_1);
      offset += serializeAvrFloat64(outbuffer + offset, this->force_sensor_2);
      offset += serializeAvrFloat64(outbuffer + offset, this->force_sensor_3);
      offset += serializeAvrFloat64(outbuffer + offset, this->motor_velocity);
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity);
      offset += serializeAvrFloat64(outbuffer + offset, this->position);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->commanded_effort));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->slow_effort_limit));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->quick_effort_limit));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->motor_current));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->motor_supply_voltage));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->hbridge_duty));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->temperature));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->force_sensor_1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->force_sensor_2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->force_sensor_3));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->motor_velocity));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velocity));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position));
     return offset;
    }

    const char * getType(){ return "sr_edc_ethercat_drivers/MotorTraceSample"; };
    const char * getMD5(){ return "f5faf420d7c29e68b1c6bfdff440ffb8"; };

  };

}
#endif