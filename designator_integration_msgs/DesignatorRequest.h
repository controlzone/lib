#ifndef _ROS_designator_integration_msgs_DesignatorRequest_h
#define _ROS_designator_integration_msgs_DesignatorRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "designator_integration_msgs/Designator.h"

namespace designator_integration_msgs
{

  class DesignatorRequest : public ros::Msg
  {
    public:
      designator_integration_msgs::Designator designator;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->designator.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->designator.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "designator_integration_msgs/DesignatorRequest"; };
    const char * getMD5(){ return "c367325726a30afcb0b453e4b00230f2"; };

  };

}
#endif