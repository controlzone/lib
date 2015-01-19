#ifndef _ROS_wpi_jaco_msgs_ExecuteGraspActionResult_h
#define _ROS_wpi_jaco_msgs_ExecuteGraspActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "wpi_jaco_msgs/ExecuteGraspResult.h"

namespace wpi_jaco_msgs
{

  class ExecuteGraspActionResult : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      wpi_jaco_msgs::ExecuteGraspResult result;

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

    const char * getType(){ return "wpi_jaco_msgs/ExecuteGraspActionResult"; };
    const char * getMD5(){ return "fe80f49ef603fed4f268a3de69778e5c"; };

  };

}
#endif