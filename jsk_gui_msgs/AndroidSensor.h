#ifndef _ROS_jsk_gui_msgs_AndroidSensor_h
#define _ROS_jsk_gui_msgs_AndroidSensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_gui_msgs
{

  class AndroidSensor : public ros::Msg
  {
    public:
      float accel_x;
      float accel_y;
      float accel_z;
      float orientation_x;
      float orientation_y;
      float orientation_z;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->accel_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->accel_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->accel_z);
      offset += serializeAvrFloat64(outbuffer + offset, this->orientation_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->orientation_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->orientation_z);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->accel_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->accel_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->accel_z));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->orientation_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->orientation_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->orientation_z));
     return offset;
    }

    const char * getType(){ return "jsk_gui_msgs/AndroidSensor"; };
    const char * getMD5(){ return "d832dbe3be7e7f061d963f2188f1a407"; };

  };

}
#endif