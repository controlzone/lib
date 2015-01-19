#ifndef _ROS_iai_kinematics_msgs_RobotState_h
#define _ROS_iai_kinematics_msgs_RobotState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/JointState.h"
#include "iai_kinematics_msgs/MultiDOFJointState.h"

namespace iai_kinematics_msgs
{

  class RobotState : public ros::Msg
  {
    public:
      sensor_msgs::JointState joint_state;
      iai_kinematics_msgs::MultiDOFJointState multi_dof_joint_state;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->joint_state.serialize(outbuffer + offset);
      offset += this->multi_dof_joint_state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->joint_state.deserialize(inbuffer + offset);
      offset += this->multi_dof_joint_state.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "iai_kinematics_msgs/RobotState"; };
    const char * getMD5(){ return "970d46b2ca41b9686adbdaeb592d97a7"; };

  };

}
#endif