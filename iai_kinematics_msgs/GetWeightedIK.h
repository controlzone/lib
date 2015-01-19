#ifndef _ROS_SERVICE_GetWeightedIK_h
#define _ROS_SERVICE_GetWeightedIK_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/PoseStamped.h"
#include "sensor_msgs/JointState.h"
#include "iai_kinematics_msgs/KDLWeights.h"
#include "iai_kinematics_msgs/ErrorCodes.h"

namespace iai_kinematics_msgs
{

static const char GETWEIGHTEDIK[] = "iai_kinematics_msgs/GetWeightedIK";

  class GetWeightedIKRequest : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped pose;
      geometry_msgs::Pose tool_frame;
      sensor_msgs::JointState ik_seed;
      iai_kinematics_msgs::KDLWeights weights;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->tool_frame.serialize(outbuffer + offset);
      offset += this->ik_seed.serialize(outbuffer + offset);
      offset += this->weights.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->tool_frame.deserialize(inbuffer + offset);
      offset += this->ik_seed.deserialize(inbuffer + offset);
      offset += this->weights.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETWEIGHTEDIK; };
    const char * getMD5(){ return "53b781873d4bc97a81274c9247a551d9"; };

  };

  class GetWeightedIKResponse : public ros::Msg
  {
    public:
      sensor_msgs::JointState solution;
      iai_kinematics_msgs::ErrorCodes error_code;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->solution.serialize(outbuffer + offset);
      offset += this->error_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->solution.deserialize(inbuffer + offset);
      offset += this->error_code.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETWEIGHTEDIK; };
    const char * getMD5(){ return "26703d3aa2f94a5367558f4749423a09"; };

  };

  class GetWeightedIK {
    public:
    typedef GetWeightedIKRequest Request;
    typedef GetWeightedIKResponse Response;
  };

}
#endif
