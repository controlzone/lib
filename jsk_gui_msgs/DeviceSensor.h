#ifndef _ROS_jsk_gui_msgs_DeviceSensor_h
#define _ROS_jsk_gui_msgs_DeviceSensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_gui_msgs
{

  class DeviceSensor : public ros::Msg
  {
    public:
      float temperature;
      float relative_humidity;
      float light;
      float pressure;
      float proximity;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->temperature);
      offset += serializeAvrFloat64(outbuffer + offset, this->relative_humidity);
      offset += serializeAvrFloat64(outbuffer + offset, this->light);
      offset += serializeAvrFloat64(outbuffer + offset, this->pressure);
      offset += serializeAvrFloat64(outbuffer + offset, this->proximity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->temperature));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->relative_humidity));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->light));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pressure));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->proximity));
     return offset;
    }

    const char * getType(){ return "jsk_gui_msgs/DeviceSensor"; };
    const char * getMD5(){ return "d3861ba768b988b4c249337d4dc6552d"; };

  };

}
#endif