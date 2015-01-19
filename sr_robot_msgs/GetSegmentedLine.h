#ifndef _ROS_SERVICE_GetSegmentedLine_h
#define _ROS_SERVICE_GetSegmentedLine_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud2.h"

namespace sr_robot_msgs
{

static const char GETSEGMENTEDLINE[] = "sr_robot_msgs/GetSegmentedLine";

  class GetSegmentedLineRequest : public ros::Msg
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

    const char * getType(){ return GETSEGMENTEDLINE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetSegmentedLineResponse : public ros::Msg
  {
    public:
      sensor_msgs::PointCloud2 line_cloud;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->line_cloud.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->line_cloud.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETSEGMENTEDLINE; };
    const char * getMD5(){ return "e52f6bd605c2394bdcc68a7000875e0c"; };

  };

  class GetSegmentedLine {
    public:
    typedef GetSegmentedLineRequest Request;
    typedef GetSegmentedLineResponse Response;
  };

}
#endif
