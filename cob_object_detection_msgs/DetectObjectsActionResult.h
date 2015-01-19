#ifndef _ROS_cob_object_detection_msgs_DetectObjectsActionResult_h
#define _ROS_cob_object_detection_msgs_DetectObjectsActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "cob_object_detection_msgs/DetectObjectsResult.h"

namespace cob_object_detection_msgs
{

  class DetectObjectsActionResult : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      cob_object_detection_msgs::DetectObjectsResult result;

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

    const char * getType(){ return "cob_object_detection_msgs/DetectObjectsActionResult"; };
    const char * getMD5(){ return "5bc0a069eaf70d7034626185f3759add"; };

  };

}
#endif