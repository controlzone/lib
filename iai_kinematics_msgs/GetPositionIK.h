#ifndef _ROS_SERVICE_GetPositionIK_h
#define _ROS_SERVICE_GetPositionIK_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "iai_kinematics_msgs/PositionIKRequest.h"
#include "iai_kinematics_msgs/ErrorCodes.h"
#include "ros/duration.h"
#include "iai_kinematics_msgs/RobotState.h"

namespace iai_kinematics_msgs
{

static const char GETPOSITIONIK[] = "iai_kinematics_msgs/GetPositionIK";

  class GetPositionIKRequest : public ros::Msg
  {
    public:
      iai_kinematics_msgs::PositionIKRequest ik_request;
      ros::Duration timeout;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->ik_request.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->timeout.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeout.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timeout.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timeout.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout.sec);
      *(outbuffer + offset + 0) = (this->timeout.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeout.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timeout.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timeout.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->ik_request.deserialize(inbuffer + offset);
      this->timeout.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timeout.sec);
      this->timeout.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timeout.nsec);
     return offset;
    }

    const char * getType(){ return GETPOSITIONIK; };
    const char * getMD5(){ return "bf9ee33930d9eaff390b8af4a213ba62"; };

  };

  class GetPositionIKResponse : public ros::Msg
  {
    public:
      iai_kinematics_msgs::RobotState solution;
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

    const char * getType(){ return GETPOSITIONIK; };
    const char * getMD5(){ return "5a8bbc4eb2775fe00cbd09858fd3dc65"; };

  };

  class GetPositionIK {
    public:
    typedef GetPositionIKRequest Request;
    typedef GetPositionIKResponse Response;
  };

}
#endif
