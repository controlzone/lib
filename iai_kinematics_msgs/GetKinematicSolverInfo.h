#ifndef _ROS_SERVICE_GetKinematicSolverInfo_h
#define _ROS_SERVICE_GetKinematicSolverInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "iai_kinematics_msgs/KinematicSolverInfo.h"

namespace iai_kinematics_msgs
{

static const char GETKINEMATICSOLVERINFO[] = "iai_kinematics_msgs/GetKinematicSolverInfo";

  class GetKinematicSolverInfoRequest : public ros::Msg
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

    const char * getType(){ return GETKINEMATICSOLVERINFO; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetKinematicSolverInfoResponse : public ros::Msg
  {
    public:
      iai_kinematics_msgs::KinematicSolverInfo kinematic_solver_info;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->kinematic_solver_info.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->kinematic_solver_info.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETKINEMATICSOLVERINFO; };
    const char * getMD5(){ return "9b591d98efeb66095c1b33a70221cab5"; };

  };

  class GetKinematicSolverInfo {
    public:
    typedef GetKinematicSolverInfoRequest Request;
    typedef GetKinematicSolverInfoResponse Response;
  };

}
#endif
