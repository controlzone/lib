#ifndef _ROS_SERVICE_getJointState_h
#define _ROS_SERVICE_getJointState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/JointState.h"

namespace sr_utilities
{

static const char GETJOINTSTATE[] = "sr_utilities/getJointState";

  class getJointStateRequest : public ros::Msg
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

    const char * getType(){ return GETJOINTSTATE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class getJointStateResponse : public ros::Msg
  {
    public:
      sensor_msgs::JointState joint_state;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->joint_state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->joint_state.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETJOINTSTATE; };
    const char * getMD5(){ return "9ca061465ef0ed08771ed240c43789f5"; };

  };

  class getJointState {
    public:
    typedef getJointStateRequest Request;
    typedef getJointStateResponse Response;
  };

}
#endif
