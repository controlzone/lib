#ifndef _ROS_designator_integration_msgs_DesignatorResponse_h
#define _ROS_designator_integration_msgs_DesignatorResponse_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "designator_integration_msgs/Designator.h"

namespace designator_integration_msgs
{

  class DesignatorResponse : public ros::Msg
  {
    public:
      uint8_t designators_length;
      designator_integration_msgs::Designator st_designators;
      designator_integration_msgs::Designator * designators;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = designators_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < designators_length; i++){
      offset += this->designators[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t designators_lengthT = *(inbuffer + offset++);
      if(designators_lengthT > designators_length)
        this->designators = (designator_integration_msgs::Designator*)realloc(this->designators, designators_lengthT * sizeof(designator_integration_msgs::Designator));
      offset += 3;
      designators_length = designators_lengthT;
      for( uint8_t i = 0; i < designators_length; i++){
      offset += this->st_designators.deserialize(inbuffer + offset);
        memcpy( &(this->designators[i]), &(this->st_designators), sizeof(designator_integration_msgs::Designator));
      }
     return offset;
    }

    const char * getType(){ return "designator_integration_msgs/DesignatorResponse"; };
    const char * getMD5(){ return "1072edc4b857216bfa13f1a8e6e3b196"; };

  };

}
#endif