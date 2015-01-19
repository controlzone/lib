#ifndef _ROS_iai_robosherlock_actions_SimplePerceiveObjectActionResult_h
#define _ROS_iai_robosherlock_actions_SimplePerceiveObjectActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "iai_robosherlock_actions/SimplePerceiveObjectResult.h"

namespace iai_robosherlock_actions
{

  class SimplePerceiveObjectActionResult : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      iai_robosherlock_actions::SimplePerceiveObjectResult result;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "iai_robosherlock_actions/SimplePerceiveObjectActionResult"; };
    const char * getMD5(){ return "e632a2fd3bb381967bb062dd34cbb5d4"; };

  };

}
#endif