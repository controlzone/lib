#ifndef _ROS_sr_robot_msgs_cartesian_data_h
#define _ROS_sr_robot_msgs_cartesian_data_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sr_robot_msgs/cartesian_position.h"

namespace sr_robot_msgs
{

  class cartesian_data : public ros::Msg
  {
    public:
      int8_t cartesian_positions_length;
      uint8_t cartesian_positions_length;
      sr_robot_msgs::cartesian_position st_cartesian_positions;
      sr_robot_msgs::cartesian_position * cartesian_positions;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_cartesian_positions_length;
      u_cartesian_positions_length.real = this->cartesian_positions_length;
      *(outbuffer + offset + 0) = (u_cartesian_positions_length.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cartesian_positions_length);
      *(outbuffer + offset++) = cartesian_positions_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < cartesian_positions_length; i++){
      offset += this->cartesian_positions[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_cartesian_positions_length;
      u_cartesian_positions_length.base = 0;
      u_cartesian_positions_length.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cartesian_positions_length = u_cartesian_positions_length.real;
      offset += sizeof(this->cartesian_positions_length);
      uint8_t cartesian_positions_lengthT = *(inbuffer + offset++);
      if(cartesian_positions_lengthT > cartesian_positions_length)
        this->cartesian_positions = (sr_robot_msgs::cartesian_position*)realloc(this->cartesian_positions, cartesian_positions_lengthT * sizeof(sr_robot_msgs::cartesian_position));
      offset += 3;
      cartesian_positions_length = cartesian_positions_lengthT;
      for( uint8_t i = 0; i < cartesian_positions_length; i++){
      offset += this->st_cartesian_positions.deserialize(inbuffer + offset);
        memcpy( &(this->cartesian_positions[i]), &(this->st_cartesian_positions), sizeof(sr_robot_msgs::cartesian_position));
      }
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/cartesian_data"; };
    const char * getMD5(){ return "0efe699b2863e30a84ffabfdca8dfb19"; };

  };

}
#endif