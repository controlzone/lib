#ifndef _ROS_graft_GraftControl_h
#define _ROS_graft_GraftControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Twist.h"

namespace graft
{

  class GraftControl : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Point position;
      geometry_msgs::Vector3 rotation;
      geometry_msgs::Twist twist;
      geometry_msgs::Vector3 acceleration;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->position.serialize(outbuffer + offset);
      offset += this->rotation.serialize(outbuffer + offset);
      offset += this->twist.serialize(outbuffer + offset);
      offset += this->acceleration.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->rotation.deserialize(inbuffer + offset);
      offset += this->twist.deserialize(inbuffer + offset);
      offset += this->acceleration.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "graft/GraftControl"; };
    const char * getMD5(){ return "f41b0858f042a487e729d7efdbffed39"; };

  };

}
#endif