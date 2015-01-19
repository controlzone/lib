#ifndef _ROS_mavros_extras_OpticalFlow_h
#define _ROS_mavros_extras_OpticalFlow_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace mavros_extras
{

  class OpticalFlow : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int16_t flow_x;
      int16_t flow_y;
      float flow_comp_m_x;
      float flow_comp_m_y;
      uint8_t quality;
      float ground_distance;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_flow_x;
      u_flow_x.real = this->flow_x;
      *(outbuffer + offset + 0) = (u_flow_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_flow_x.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->flow_x);
      union {
        int16_t real;
        uint16_t base;
      } u_flow_y;
      u_flow_y.real = this->flow_y;
      *(outbuffer + offset + 0) = (u_flow_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_flow_y.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->flow_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->flow_comp_m_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->flow_comp_m_y);
      *(outbuffer + offset + 0) = (this->quality >> (8 * 0)) & 0xFF;
      offset += sizeof(this->quality);
      offset += serializeAvrFloat64(outbuffer + offset, this->ground_distance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_flow_x;
      u_flow_x.base = 0;
      u_flow_x.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_flow_x.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->flow_x = u_flow_x.real;
      offset += sizeof(this->flow_x);
      union {
        int16_t real;
        uint16_t base;
      } u_flow_y;
      u_flow_y.base = 0;
      u_flow_y.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_flow_y.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->flow_y = u_flow_y.real;
      offset += sizeof(this->flow_y);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->flow_comp_m_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->flow_comp_m_y));
      this->quality =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->quality);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->ground_distance));
     return offset;
    }

    const char * getType(){ return "mavros_extras/OpticalFlow"; };
    const char * getMD5(){ return "cd3dfea8b7fb19a9c34383166b854736"; };

  };

}
#endif