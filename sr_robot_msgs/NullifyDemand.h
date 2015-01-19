#ifndef _ROS_SERVICE_NullifyDemand_h
#define _ROS_SERVICE_NullifyDemand_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_robot_msgs
{

static const char NULLIFYDEMAND[] = "sr_robot_msgs/NullifyDemand";

  class NullifyDemandRequest : public ros::Msg
  {
    public:
      bool nullify_demand;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_nullify_demand;
      u_nullify_demand.real = this->nullify_demand;
      *(outbuffer + offset + 0) = (u_nullify_demand.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->nullify_demand);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_nullify_demand;
      u_nullify_demand.base = 0;
      u_nullify_demand.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->nullify_demand = u_nullify_demand.real;
      offset += sizeof(this->nullify_demand);
     return offset;
    }

    const char * getType(){ return NULLIFYDEMAND; };
    const char * getMD5(){ return "e776288d81b4da212263a7a8b3f035b3"; };

  };

  class NullifyDemandResponse : public ros::Msg
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

    const char * getType(){ return NULLIFYDEMAND; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class NullifyDemand {
    public:
    typedef NullifyDemandRequest Request;
    typedef NullifyDemandResponse Response;
  };

}
#endif
