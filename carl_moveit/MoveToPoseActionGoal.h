#ifndef _ROS_carl_moveit_MoveToPoseActionGoal_h
#define _ROS_carl_moveit_MoveToPoseActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "carl_moveit/MoveToPoseGoal.h"

namespace carl_moveit
{

  class MoveToPoseActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      carl_moveit::MoveToPoseGoal goal;

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

    const char * getType(){ return "carl_moveit/MoveToPoseActionGoal"; };
    const char * getMD5(){ return "83a5003608bfe9186a54ce300336432e"; };

  };

}
#endif