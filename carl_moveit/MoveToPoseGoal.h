#ifndef _ROS_carl_moveit_MoveToPoseGoal_h
#define _ROS_carl_moveit_MoveToPoseGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace carl_moveit
{

  class MoveToPoseGoal : public ros::Msg
  {
    public:
      geometry_msgs::Pose pose;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "carl_moveit/MoveToPoseGoal"; };
    const char * getMD5(){ return "f192399f711a48924df9a394d37edd67"; };

  };

}
#endif