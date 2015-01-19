#ifndef _ROS_wpi_jaco_msgs_ExecuteGraspAction_h
#define _ROS_wpi_jaco_msgs_ExecuteGraspAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "wpi_jaco_msgs/ExecuteGraspActionGoal.h"
#include "wpi_jaco_msgs/ExecuteGraspActionResult.h"
#include "wpi_jaco_msgs/ExecuteGraspActionFeedback.h"

namespace wpi_jaco_msgs
{

  class ExecuteGraspAction : public ros::Msg
  {
    public:
      wpi_jaco_msgs::ExecuteGraspActionGoal action_goal;
      wpi_jaco_msgs::ExecuteGraspActionResult action_result;
      wpi_jaco_msgs::ExecuteGraspActionFeedback action_feedback;

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

    const char * getType(){ return "wpi_jaco_msgs/ExecuteGraspAction"; };
    const char * getMD5(){ return "bc053be2ff76452867c0c04a69520573"; };

  };

}
#endif