#ifndef _ROS_iai_robosherlock_actions_SimplePerceiveObjectGoal_h
#define _ROS_iai_robosherlock_actions_SimplePerceiveObjectGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "designator_integration_msgs/Designator.h"

namespace iai_robosherlock_actions
{

  class SimplePerceiveObjectGoal : public ros::Msg
  {
    public:
      uint8_t requests_length;
      designator_integration_msgs::Designator st_requests;
      designator_integration_msgs::Designator * requests;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = requests_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < requests_length; i++){
      offset += this->requests[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t requests_lengthT = *(inbuffer + offset++);
      if(requests_lengthT > requests_length)
        this->requests = (designator_integration_msgs::Designator*)realloc(this->requests, requests_lengthT * sizeof(designator_integration_msgs::Designator));
      offset += 3;
      requests_length = requests_lengthT;
      for( uint8_t i = 0; i < requests_length; i++){
      offset += this->st_requests.deserialize(inbuffer + offset);
        memcpy( &(this->requests[i]), &(this->st_requests), sizeof(designator_integration_msgs::Designator));
      }
     return offset;
    }

    const char * getType(){ return "iai_robosherlock_actions/SimplePerceiveObjectGoal"; };
    const char * getMD5(){ return "06595ddac8022d0c005322ef8c4186c9"; };

  };

}
#endif