#ifndef _ROS_cob_object_detection_msgs_AcquireObjectImageActionFeedback_h
#define _ROS_cob_object_detection_msgs_AcquireObjectImageActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "cob_object_detection_msgs/AcquireObjectImageFeedback.h"

namespace cob_object_detection_msgs
{

  class AcquireObjectImageActionFeedback : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      cob_object_detection_msgs::AcquireObjectImageFeedback feedback;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_object_detection_msgs/AcquireObjectImageActionFeedback"; };
    const char * getMD5(){ return "25bfb21ced59f4f9490772d56f6961f4"; };

  };

}
#endif