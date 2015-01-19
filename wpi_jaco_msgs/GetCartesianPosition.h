#ifndef _ROS_SERVICE_GetCartesianPosition_h
#define _ROS_SERVICE_GetCartesianPosition_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Twist.h"

namespace wpi_jaco_msgs
{

static const char GETCARTESIANPOSITION[] = "wpi_jaco_msgs/GetCartesianPosition";

  class GetCartesianPositionRequest : public ros::Msg
  {
    public:

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return GETCARTESIANPOSITION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetCartesianPositionResponse : public ros::Msg
  {
    public:
      geometry_msgs::Twist pos;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pos.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pos.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETCARTESIANPOSITION; };
    const char * getMD5(){ return "90eff4f5bd7896007c2525f114434660"; };

  };

  class GetCartesianPosition {
    public:
    typedef GetCartesianPositionRequest Request;
    typedef GetCartesianPositionResponse Response;
  };

}
#endif
