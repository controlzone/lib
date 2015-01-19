#ifndef _ROS_carl_moveit_MoveToPoseAction_h
#define _ROS_carl_moveit_MoveToPoseAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "carl_moveit/MoveToPoseActionGoal.h"
#include "carl_moveit/MoveToPoseActionResult.h"
#include "carl_moveit/MoveToPoseActionFeedback.h"

namespace carl_moveit
{

  class MoveToPoseAction : public ros::Msg
  {
    public:
      carl_moveit::MoveToPoseActionGoal action_goal;
      carl_moveit::MoveToPoseActionResult action_result;
      carl_moveit::MoveToPoseActionFeedback action_feedback;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "carl_moveit/MoveToPoseAction"; };
    const char * getMD5(){ return "8f3153a4ecc671203bcd56901eeb8221"; };

  };

}
#endif