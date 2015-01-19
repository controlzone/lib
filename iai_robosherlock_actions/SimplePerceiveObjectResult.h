#ifndef _ROS_iai_robosherlock_actions_SimplePerceiveObjectResult_h
#define _ROS_iai_robosherlock_actions_SimplePerceiveObjectResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "designator_integration_msgs/Designator.h"

namespace iai_robosherlock_actions
{

  class SimplePerceiveObjectResult : public ros::Msg
  {
    public:
      uint8_t percepts_length;
      designator_integration_msgs::Designator st_percepts;
      designator_integration_msgs::Designator * percepts;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = percepts_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < percepts_length; i++){
      offset += this->percepts[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t percepts_lengthT = *(inbuffer + offset++);
      if(percepts_lengthT > percepts_length)
        this->percepts = (designator_integration_msgs::Designator*)realloc(this->percepts, percepts_lengthT * sizeof(designator_integration_msgs::Designator));
      offset += 3;
      percepts_length = percepts_lengthT;
      for( uint8_t i = 0; i < percepts_length; i++){
      offset += this->st_percepts.deserialize(inbuffer + offset);
        memcpy( &(this->percepts[i]), &(this->st_percepts), sizeof(designator_integration_msgs::Designator));
      }
     return offset;
    }

    const char * getType(){ return "iai_robosherlock_actions/SimplePerceiveObjectResult"; };
    const char * getMD5(){ return "099799b0bfb36952af24ffb7c9a736b9"; };

  };

}
#endif