#ifndef _ROS_jsk_footstep_msgs_PlanFootstepsResult_h
#define _ROS_jsk_footstep_msgs_PlanFootstepsResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_footstep_msgs/FootstepArray.h"

namespace jsk_footstep_msgs
{

  class PlanFootstepsResult : public ros::Msg
  {
    public:
      jsk_footstep_msgs::FootstepArray result;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "jsk_footstep_msgs/PlanFootstepsResult"; };
    const char * getMD5(){ return "1426f0d48a517cdd5671a3f8259f5390"; };

  };

}
#endif