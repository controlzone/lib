#ifndef _ROS_iai_kinematics_msgs_KDLWeights_h
#define _ROS_iai_kinematics_msgs_KDLWeights_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace iai_kinematics_msgs
{

  class KDLWeights : public ros::Msg
  {
    public:
      int8_t mode;
      float weight_ts[36];
      uint8_t weight_js_length;
      float st_weight_js;
      float * weight_js;
      float lambda;
      enum { INVALID_MODE =  0 };
      enum { SET_TS =  1 };
      enum { SET_JS =  2 };
      enum { SET_LAMBDA =  4 };
      enum { SET_TS_JS =  3 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_mode;
      u_mode.real = this->mode;
      *(outbuffer + offset + 0) = (u_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      for( uint8_t i = 0; i < 36; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->weight_ts[i]);
      }
      *(outbuffer + offset++) = weight_js_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < weight_js_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->weight_js[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->lambda);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_mode;
      u_mode.base = 0;
      u_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mode = u_mode.real;
      offset += sizeof(this->mode);
      for( uint8_t i = 0; i < 36; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->weight_ts[i]));
      }
      uint8_t weight_js_lengthT = *(inbuffer + offset++);
      if(weight_js_lengthT > weight_js_length)
        this->weight_js = (float*)realloc(this->weight_js, weight_js_lengthT * sizeof(float));
      offset += 3;
      weight_js_length = weight_js_lengthT;
      for( uint8_t i = 0; i < weight_js_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_weight_js));
        memcpy( &(this->weight_js[i]), &(this->st_weight_js), sizeof(float));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->lambda));
     return offset;
    }

    const char * getType(){ return "iai_kinematics_msgs/KDLWeights"; };
    const char * getMD5(){ return "986315cd29a99987092b708377dfd2ce"; };

  };

}
#endif