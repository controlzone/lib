#ifndef _ROS_wpi_jaco_msgs_HomeArmActionGoal_h
#define _ROS_wpi_jaco_msgs_HomeArmActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "wpi_jaco_msgs/HomeArmGoal.h"

namespace wpi_jaco_msgs
{

  class HomeArmActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      wpi_jaco_msgs::HomeArmGoal goal;

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

    const char * getType(){ return "wpi_jaco_msgs/HomeArmActionGoal"; };
    const char * getMD5(){ return "a38d61e5642492ea0b4a3112c013073a"; };

  };

}
#endif