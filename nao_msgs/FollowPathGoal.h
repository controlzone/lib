#ifndef _ROS_nao_msgs_FollowPathGoal_h
#define _ROS_nao_msgs_FollowPathGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nav_msgs/Path.h"

namespace nao_msgs
{

  class FollowPathGoal : public ros::Msg
  {
    public:
      nav_msgs::Path path;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->path.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->path.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "nao_msgs/FollowPathGoal"; };
    const char * getMD5(){ return "58d6f138c7de7ef47c75d4b7e5df5472"; };

  };

}
#endif