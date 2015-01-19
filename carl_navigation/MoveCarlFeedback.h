#ifndef _ROS_carl_navigation_MoveCarlFeedback_h
#define _ROS_carl_navigation_MoveCarlFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace carl_navigation
{

  class MoveCarlFeedback : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped base_position;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->base_position.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->base_position.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "carl_navigation/MoveCarlFeedback"; };
    const char * getMD5(){ return "3fb824c456a757373a226f6d08071bf0"; };

  };

}
#endif