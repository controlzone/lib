#ifndef _ROS_nao_msgs_SpeechWithFeedbackAction_h
#define _ROS_nao_msgs_SpeechWithFeedbackAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nao_msgs/SpeechWithFeedbackActionGoal.h"
#include "nao_msgs/SpeechWithFeedbackActionResult.h"
#include "nao_msgs/SpeechWithFeedbackActionFeedback.h"

namespace nao_msgs
{

  class SpeechWithFeedbackAction : public ros::Msg
  {
    public:
      nao_msgs::SpeechWithFeedbackActionGoal action_goal;
      nao_msgs::SpeechWithFeedbackActionResult action_result;
      nao_msgs::SpeechWithFeedbackActionFeedback action_feedback;

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

    const char * getType(){ return "nao_msgs/SpeechWithFeedbackAction"; };
    const char * getMD5(){ return "3a7530648ec5a63553b8765e8b88e951"; };

  };

}
#endif