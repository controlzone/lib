#ifndef _ROS_sr_edc_ethercat_drivers_ActuatorInfo_h
#define _ROS_sr_edc_ethercat_drivers_ActuatorInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_edc_ethercat_drivers
{

  class ActuatorInfo : public ros::Msg
  {
    public:
      const char* name;
      float slow_motor_current_limit;
      float quick_motor_current_limit;
      float duty_limit;
      float max_duty;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      offset += serializeAvrFloat64(outbuffer + offset, this->slow_motor_current_limit);
      offset += serializeAvrFloat64(outbuffer + offset, this->quick_motor_current_limit);
      offset += serializeAvrFloat64(outbuffer + offset, this->duty_limit);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_duty);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->slow_motor_current_limit));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->quick_motor_current_limit));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->duty_limit));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_duty));
     return offset;
    }

    const char * getType(){ return "sr_edc_ethercat_drivers/ActuatorInfo"; };
    const char * getMD5(){ return "b69309b2980b8b35e7e2b52bad59330a"; };

  };

}
#endif