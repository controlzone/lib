#ifndef _ROS_carl_navigation_MoveCarlActionGoal_h
#define _ROS_carl_navigation_MoveCarlActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "carl_navigation/MoveCarlGoal.h"

namespace carl_navigation
{

  class MoveCarlActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      carl_navigation::MoveCarlGoal goal;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "carl_navigation/MoveCarlActionGoal"; };
    const char * getMD5(){ return "d5059af95bd7e5ac8b2ac9722737ce6f"; };

  };

}
#endif