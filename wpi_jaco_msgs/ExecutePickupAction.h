#ifndef _ROS_wpi_jaco_msgs_ExecutePickupAction_h
#define _ROS_wpi_jaco_msgs_ExecutePickupAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "wpi_jaco_msgs/ExecutePickupActionGoal.h"
#include "wpi_jaco_msgs/ExecutePickupActionResult.h"
#include "wpi_jaco_msgs/ExecutePickupActionFeedback.h"

namespace wpi_jaco_msgs
{

  class ExecutePickupAction : public ros::Msg
  {
    public:
      wpi_jaco_msgs::ExecutePickupActionGoal action_goal;
      wpi_jaco_msgs::ExecutePickupActionResult action_result;
      wpi_jaco_msgs::ExecutePickupActionFeedback action_feedback;

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

    const char * getType(){ return "wpi_jaco_msgs/ExecutePickupAction"; };
    const char * getMD5(){ return "781340f4dc3019405a75c33ba0a78494"; };

  };

}
#endif