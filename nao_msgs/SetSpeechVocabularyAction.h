#ifndef _ROS_nao_msgs_SetSpeechVocabularyAction_h
#define _ROS_nao_msgs_SetSpeechVocabularyAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nao_msgs/SetSpeechVocabularyActionGoal.h"
#include "nao_msgs/SetSpeechVocabularyActionResult.h"
#include "nao_msgs/SetSpeechVocabularyActionFeedback.h"

namespace nao_msgs
{

  class SetSpeechVocabularyAction : public ros::Msg
  {
    public:
      nao_msgs::SetSpeechVocabularyActionGoal action_goal;
      nao_msgs::SetSpeechVocabularyActionResult action_result;
      nao_msgs::SetSpeechVocabularyActionFeedback action_feedback;

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

    const char * getType(){ return "nao_msgs/SetSpeechVocabularyAction"; };
    const char * getMD5(){ return "737441a71b3375ccf5219f84239ade13"; };

  };

}
#endif