#ifndef _ROS_carl_moveit_MoveToPoseActionFeedback_h
#define _ROS_carl_moveit_MoveToPoseActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "carl_moveit/MoveToPoseFeedback.h"

namespace carl_moveit
{

  class MoveToPoseActionFeedback : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      carl_moveit::MoveToPoseFeedback feedback;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "carl_moveit/MoveToPoseActionFeedback"; };
    const char * getMD5(){ return "86cfd50d5ec6a9ce6ffde931acdc45c7"; };

  };

}
#endif