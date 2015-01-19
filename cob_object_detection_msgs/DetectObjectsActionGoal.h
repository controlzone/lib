#ifndef _ROS_cob_object_detection_msgs_DetectObjectsActionGoal_h
#define _ROS_cob_object_detection_msgs_DetectObjectsActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "cob_object_detection_msgs/DetectObjectsGoal.h"

namespace cob_object_detection_msgs
{

  class DetectObjectsActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      cob_object_detection_msgs::DetectObjectsGoal goal;

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

    const char * getType(){ return "cob_object_detection_msgs/DetectObjectsActionGoal"; };
    const char * getMD5(){ return "0c8437c7152cb7af8e0ed1d26a22075f"; };

  };

}
#endif