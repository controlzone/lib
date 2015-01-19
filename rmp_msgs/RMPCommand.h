#ifndef _ROS_rmp_msgs_RMPCommand_h
#define _ROS_rmp_msgs_RMPCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rmp_msgs
{

  class RMPCommand : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint32_t cmd_id;
      float arg1;
      float arg2;
      float arg3;
      enum { RMP_MOTION_CMD_ID =  1280 };
      enum { RMP_OMNI_MOTION_CMD_ID =  1536 };
      enum { RMP_CFG_CMD_ID =  1281 };
      enum { RMP_CMD_SET_OPERATIONAL_MODE =  32 };
      enum { RMP_CMD_NONE =  0 };
      enum { DISABLE_REQUEST =  1 };
      enum { POWERDOWN_REQUEST =  2 };
      enum { DTZ_REQUEST =  3 };
      enum { STANDBY_REQUEST =  4 };
      enum { TRACTOR_REQUEST =  5 };
      enum { BALANCE_REQUEST =  6 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->cmd_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cmd_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cmd_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cmd_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cmd_id);
      union {
        float real;
        uint32_t base;
      } u_arg1;
      u_arg1.real = this->arg1;
      *(outbuffer + offset + 0) = (u_arg1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_arg1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_arg1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_arg1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->arg1);
      union {
        float real;
        uint32_t base;
      } u_arg2;
      u_arg2.real = this->arg2;
      *(outbuffer + offset + 0) = (u_arg2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_arg2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_arg2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_arg2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->arg2);
      union {
        float real;
        uint32_t base;
      } u_arg3;
      u_arg3.real = this->arg3;
      *(outbuffer + offset + 0) = (u_arg3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_arg3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_arg3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_arg3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->arg3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->cmd_id =  ((uint32_t) (*(inbuffer + offset)));
      this->cmd_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->cmd_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->cmd_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->cmd_id);
      union {
        float real;
        uint32_t base;
      } u_arg1;
      u_arg1.base = 0;
      u_arg1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_arg1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_arg1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_arg1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->arg1 = u_arg1.real;
      offset += sizeof(this->arg1);
      union {
        float real;
        uint32_t base;
      } u_arg2;
      u_arg2.base = 0;
      u_arg2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_arg2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_arg2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_arg2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->arg2 = u_arg2.real;
      offset += sizeof(this->arg2);
      union {
        float real;
        uint32_t base;
      } u_arg3;
      u_arg3.base = 0;
      u_arg3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_arg3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_arg3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_arg3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->arg3 = u_arg3.real;
      offset += sizeof(this->arg3);
     return offset;
    }

    const char * getType(){ return "rmp_msgs/RMPCommand"; };
    const char * getMD5(){ return "84cde9e1758addb56d2d271a15c091bc"; };

  };

}
#endif