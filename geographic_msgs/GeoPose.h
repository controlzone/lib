#ifndef _ROS_geographic_msgs_GeoPose_h
#define _ROS_geographic_msgs_GeoPose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geographic_msgs/GeoPoint.h"
#include "geometry_msgs/Quaternion.h"

namespace geographic_msgs
{

  class GeoPose : public ros::Msg
  {
    public:
      geographic_msgs::GeoPoint position;
      geometry_msgs::Quaternion orientation;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->position.serialize(outbuffer + offset);
      offset += this->orientation.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->orientation.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "geographic_msgs/GeoPose"; };
    const char * getMD5(){ return "778680b5172de58b7c057d973576c784"; };

  };

}
#endif