#ifndef _ROS_concert_msgs_Strings_h
#define _ROS_concert_msgs_Strings_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace concert_msgs
{

  class Strings : public ros::Msg
  {
    public:
      enum { PARAM_ROCON_SCREEN =  /rocon/screen };
      enum { SCHEDULER_UNALLOCATED_RESOURCE =  unallocated };
      enum { CONCERT_CLIENTS =  /concert/conductor/concert_clients };
      enum { SERVICE_NAMESPACE =  /services };

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

    const char * getType(){ return "concert_msgs/Strings"; };
    const char * getMD5(){ return "052d6ae2889cb83de07b62147238913a"; };

  };

}
#endif