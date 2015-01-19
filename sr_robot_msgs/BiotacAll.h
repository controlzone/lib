#ifndef _ROS_sr_robot_msgs_BiotacAll_h
#define _ROS_sr_robot_msgs_BiotacAll_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sr_robot_msgs/Biotac.h"

namespace sr_robot_msgs
{

  class BiotacAll : public ros::Msg
  {
    public:
      std_msgs::Header header;
      sr_robot_msgs::Biotac tactiles[5];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 5; i++){
      offset += this->tactiles[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 5; i++){
      offset += this->tactiles[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/BiotacAll"; };
    const char * getMD5(){ return "47a346cfb98ba8199f53056f3ea612f1"; };

  };

}
#endif