#ifndef _ROS_wpi_jaco_msgs_HomeArmAction_h
#define _ROS_wpi_jaco_msgs_HomeArmAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "wpi_jaco_msgs/HomeArmActionGoal.h"
#include "wpi_jaco_msgs/HomeArmActionResult.h"
#include "wpi_jaco_msgs/HomeArmActionFeedback.h"

namespace wpi_jaco_msgs
{

  class HomeArmAction : public ros::Msg
  {
    public:
      wpi_jaco_msgs::HomeArmActionGoal action_goal;
      wpi_jaco_msgs::HomeArmActionResult action_result;
      wpi_jaco_msgs::HomeArmActionFeedback action_feedback;

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

    const char * getType(){ return "wpi_jaco_msgs/HomeArmAction"; };
    const char * getMD5(){ return "f1dd10e2922ecb7fda7a9e73292a38a3"; };

  };

}
#endif