#ifndef _ROS_wpi_jaco_msgs_ExecuteGraspFeedback_h
#define _ROS_wpi_jaco_msgs_ExecuteGraspFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace wpi_jaco_msgs
{

  class ExecuteGraspFeedback : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return "wpi_jaco_msgs/ExecuteGraspFeedback"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif