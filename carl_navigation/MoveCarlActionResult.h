#ifndef _ROS_carl_navigation_MoveCarlActionResult_h
#define _ROS_carl_navigation_MoveCarlActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "carl_navigation/MoveCarlResult.h"

namespace carl_navigation
{

  class MoveCarlActionResult : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      carl_navigation::MoveCarlResult result;

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

    const char * getType(){ return "carl_navigation/MoveCarlActionResult"; };
    const char * getMD5(){ return "1eb06eeff08fa7ea874431638cb52332"; };

  };

}
#endif