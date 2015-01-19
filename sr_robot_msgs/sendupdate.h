#ifndef _ROS_sr_robot_msgs_sendupdate_h
#define _ROS_sr_robot_msgs_sendupdate_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sr_robot_msgs/joint.h"

namespace sr_robot_msgs
{

  class sendupdate : public ros::Msg
  {
    public:
      int8_t sendupdate_length;
      uint8_t sendupdate_list_length;
      sr_robot_msgs::joint st_sendupdate_list;
      sr_robot_msgs::joint * sendupdate_list;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_sendupdate_length;
      u_sendupdate_length.real = this->sendupdate_length;
      *(outbuffer + offset + 0) = (u_sendupdate_length.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sendupdate_length);
      *(outbuffer + offset++) = sendupdate_list_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < sendupdate_list_length; i++){
      offset += this->sendupdate_list[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_sendupdate_length;
      u_sendupdate_length.base = 0;
      u_sendupdate_length.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sendupdate_length = u_sendupdate_length.real;
      offset += sizeof(this->sendupdate_length);
      uint8_t sendupdate_list_lengthT = *(inbuffer + offset++);
      if(sendupdate_list_lengthT > sendupdate_list_length)
        this->sendupdate_list = (sr_robot_msgs::joint*)realloc(this->sendupdate_list, sendupdate_list_lengthT * sizeof(sr_robot_msgs::joint));
      offset += 3;
      sendupdate_list_length = sendupdate_list_lengthT;
      for( uint8_t i = 0; i < sendupdate_list_length; i++){
      offset += this->st_sendupdate_list.deserialize(inbuffer + offset);
        memcpy( &(this->sendupdate_list[i]), &(this->st_sendupdate_list), sizeof(sr_robot_msgs::joint));
      }
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/sendupdate"; };
    const char * getMD5(){ return "43a45fe046127fe123dc7e38e3ffdc36"; };

  };

}
#endif