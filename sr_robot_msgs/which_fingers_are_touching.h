#ifndef _ROS_SERVICE_which_fingers_are_touching_h
#define _ROS_SERVICE_which_fingers_are_touching_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_robot_msgs
{

static const char WHICH_FINGERS_ARE_TOUCHING[] = "sr_robot_msgs/which_fingers_are_touching";

  class which_fingers_are_touchingRequest : public ros::Msg
  {
    public:
      uint8_t force_thresholds_length;
      float st_force_thresholds;
      float * force_thresholds;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = force_thresholds_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < force_thresholds_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->force_thresholds[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t force_thresholds_lengthT = *(inbuffer + offset++);
      if(force_thresholds_lengthT > force_thresholds_length)
        this->force_thresholds = (float*)realloc(this->force_thresholds, force_thresholds_lengthT * sizeof(float));
      offset += 3;
      force_thresholds_length = force_thresholds_lengthT;
      for( uint8_t i = 0; i < force_thresholds_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_force_thresholds));
        memcpy( &(this->force_thresholds[i]), &(this->st_force_thresholds), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return WHICH_FINGERS_ARE_TOUCHING; };
    const char * getMD5(){ return "f0fd736c3daac04fcc02a89421c67ccd"; };

  };

  class which_fingers_are_touchingResponse : public ros::Msg
  {
    public:
      uint8_t touch_forces_length;
      float st_touch_forces;
      float * touch_forces;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = touch_forces_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < touch_forces_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->touch_forces[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t touch_forces_lengthT = *(inbuffer + offset++);
      if(touch_forces_lengthT > touch_forces_length)
        this->touch_forces = (float*)realloc(this->touch_forces, touch_forces_lengthT * sizeof(float));
      offset += 3;
      touch_forces_length = touch_forces_lengthT;
      for( uint8_t i = 0; i < touch_forces_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_touch_forces));
        memcpy( &(this->touch_forces[i]), &(this->st_touch_forces), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return WHICH_FINGERS_ARE_TOUCHING; };
    const char * getMD5(){ return "f9d8b7193733b8133389d5ada08e713d"; };

  };

  class which_fingers_are_touching {
    public:
    typedef which_fingers_are_touchingRequest Request;
    typedef which_fingers_are_touchingResponse Response;
  };

}
#endif
