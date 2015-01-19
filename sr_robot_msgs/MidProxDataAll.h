#ifndef _ROS_sr_robot_msgs_MidProxDataAll_h
#define _ROS_sr_robot_msgs_MidProxDataAll_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sr_robot_msgs/MidProxData.h"

namespace sr_robot_msgs
{

  class MidProxDataAll : public ros::Msg
  {
    public:
      std_msgs::Header header;
      sr_robot_msgs::MidProxData sensors[5];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 5; i++){
      offset += this->sensors[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 5; i++){
      offset += this->sensors[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/MidProxDataAll"; };
    const char * getMD5(){ return "1e9012ec0a19b9d9e5a6680de1b6d873"; };

  };

}
#endif