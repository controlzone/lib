#ifndef _ROS_sr_edc_ethercat_drivers_MotorTrace_h
#define _ROS_sr_edc_ethercat_drivers_MotorTrace_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sr_edc_ethercat_drivers/ActuatorInfo.h"
#include "sr_edc_ethercat_drivers/MotorTraceSample.h"

namespace sr_edc_ethercat_drivers
{

  class MotorTrace : public ros::Msg
  {
    public:
      std_msgs::Header header;
      const char* reason;
      sr_edc_ethercat_drivers::ActuatorInfo actuator_info;
      uint8_t samples_length;
      sr_edc_ethercat_drivers::MotorTraceSample st_samples;
      sr_edc_ethercat_drivers::MotorTraceSample * samples;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_reason = strlen(this->reason);
      memcpy(outbuffer + offset, &length_reason, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->reason, length_reason);
      offset += length_reason;
      offset += this->actuator_info.serialize(outbuffer + offset);
      *(outbuffer + offset++) = samples_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < samples_length; i++){
      offset += this->samples[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_reason;
      memcpy(&length_reason, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_reason; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_reason-1]=0;
      this->reason = (char *)(inbuffer + offset-1);
      offset += length_reason;
      offset += this->actuator_info.deserialize(inbuffer + offset);
      uint8_t samples_lengthT = *(inbuffer + offset++);
      if(samples_lengthT > samples_length)
        this->samples = (sr_edc_ethercat_drivers::MotorTraceSample*)realloc(this->samples, samples_lengthT * sizeof(sr_edc_ethercat_drivers::MotorTraceSample));
      offset += 3;
      samples_length = samples_lengthT;
      for( uint8_t i = 0; i < samples_length; i++){
      offset += this->st_samples.deserialize(inbuffer + offset);
        memcpy( &(this->samples[i]), &(this->st_samples), sizeof(sr_edc_ethercat_drivers::MotorTraceSample));
      }
     return offset;
    }

    const char * getType(){ return "sr_edc_ethercat_drivers/MotorTrace"; };
    const char * getMD5(){ return "d06300e55fe6989d2795bc4072205fe1"; };

  };

}
#endif