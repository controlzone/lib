#ifndef _ROS_carl_navigation_MoveCarlAction_h
#define _ROS_carl_navigation_MoveCarlAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "carl_navigation/MoveCarlActionGoal.h"
#include "carl_navigation/MoveCarlActionResult.h"
#include "carl_navigation/MoveCarlActionFeedback.h"

namespace carl_navigation
{

  class MoveCarlAction : public ros::Msg
  {
    public:
      carl_navigation::MoveCarlActionGoal action_goal;
      carl_navigation::MoveCarlActionResult action_result;
      carl_navigation::MoveCarlActionFeedback action_feedback;

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

    const char * getType(){ return "carl_navigation/MoveCarlAction"; };
    const char * getMD5(){ return "1993b3473ebc427ad08f4443dfe5f063"; };

  };

}
#endif