#ifndef _ROS_SERVICE_DetectObjects_h
#define _ROS_SERVICE_DetectObjects_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/RegionOfInterest.h"
#include "std_msgs/String.h"
#include "cob_object_detection_msgs/DetectionArray.h"

namespace cob_object_detection_msgs
{

static const char DETECTOBJECTS[] = "cob_object_detection_msgs/DetectObjects";

  class DetectObjectsRequest : public ros::Msg
  {
    public:
      std_msgs::String object_name;
      sensor_msgs::RegionOfInterest roi;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->object_name.serialize(outbuffer + offset);
      offset += this->roi.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->object_name.deserialize(inbuffer + offset);
      offset += this->roi.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return DETECTOBJECTS; };
    const char * getMD5(){ return "8d651fac3fa327d154d291de842e3994"; };

  };

  class DetectObjectsResponse : public ros::Msg
  {
    public:
      cob_object_detection_msgs::DetectionArray object_list;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->object_list.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->object_list.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return DETECTOBJECTS; };
    const char * getMD5(){ return "6da5c76956a10a2b2a7e649614ba9504"; };

  };

  class DetectObjects {
    public:
    typedef DetectObjectsRequest Request;
    typedef DetectObjectsResponse Response;
  };

}
#endif
