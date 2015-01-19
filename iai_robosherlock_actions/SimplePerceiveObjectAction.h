#ifndef _ROS_iai_robosherlock_actions_SimplePerceiveObjectAction_h
#define _ROS_iai_robosherlock_actions_SimplePerceiveObjectAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "iai_robosherlock_actions/SimplePerceiveObjectActionGoal.h"
#include "iai_robosherlock_actions/SimplePerceiveObjectActionResult.h"
#include "iai_robosherlock_actions/SimplePerceiveObjectActionFeedback.h"

namespace iai_robosherlock_actions
{

  class SimplePerceiveObjectAction : public ros::Msg
  {
    public:
      iai_robosherlock_actions::SimplePerceiveObjectActionGoal action_goal;
      iai_robosherlock_actions::SimplePerceiveObjectActionResult action_result;
      iai_robosherlock_actions::SimplePerceiveObjectActionFeedback action_feedback;

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

    const char * getType(){ return "iai_robosherlock_actions/SimplePerceiveObjectAction"; };
    const char * getMD5(){ return "8f31425161a201d6766dadec2193614f"; };

  };

}
#endif