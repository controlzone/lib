#ifndef _ROS_nao_msgs_SpeechWithFeedbackFeedback_h
#define _ROS_nao_msgs_SpeechWithFeedbackFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nao_msgs
{

  class SpeechWithFeedbackFeedback : public ros::Msg
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

    const char * getType(){ return "nao_msgs/SpeechWithFeedbackFeedback"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif