#ifndef _ROS_wpi_jaco_msgs_ExecutePickupActionGoal_h
#define _ROS_wpi_jaco_msgs_ExecutePickupActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "wpi_jaco_msgs/ExecutePickupGoal.h"

namespace wpi_jaco_msgs
{

  class ExecutePickupActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      wpi_jaco_msgs::ExecutePickupGoal goal;

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

    const char * getType(){ return "wpi_jaco_msgs/ExecutePickupActionGoal"; };
    const char * getMD5(){ return "3f6e35d11893685d976376cfaf509909"; };

  };

}
#endif