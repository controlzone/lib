#ifndef _ROS_carl_moveit_MoveToPoseFeedback_h
#define _ROS_carl_moveit_MoveToPoseFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace carl_moveit
{

  class MoveToPoseFeedback : public ros::Msg
  {
    public:
      float progress;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_progress;
      u_progress.real = this->progress;
      *(outbuffer + offset + 0) = (u_progress.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_progress.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_progress.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_progress.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->progress);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_progress;
      u_progress.base = 0;
      u_progress.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_progress.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_progress.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_progress.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->progress = u_progress.real;
      offset += sizeof(this->progress);
     return offset;
    }

    const char * getType(){ return "carl_moveit/MoveToPoseFeedback"; };
    const char * getMD5(){ return "70805092fd20e110765c7b79e8efb737"; };

  };

}
#endif