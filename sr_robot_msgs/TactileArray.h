#ifndef _ROS_sr_robot_msgs_TactileArray_h
#define _ROS_sr_robot_msgs_TactileArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sr_robot_msgs/Tactile.h"

namespace sr_robot_msgs
{

  class TactileArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t data_length;
      sr_robot_msgs::Tactile st_data;
      sr_robot_msgs::Tactile * data;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < data_length; i++){
      offset += this->data[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t data_lengthT = *(inbuffer + offset++);
      if(data_lengthT > data_length)
        this->data = (sr_robot_msgs::Tactile*)realloc(this->data, data_lengthT * sizeof(sr_robot_msgs::Tactile));
      offset += 3;
      data_length = data_lengthT;
      for( uint8_t i = 0; i < data_length; i++){
      offset += this->st_data.deserialize(inbuffer + offset);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(sr_robot_msgs::Tactile));
      }
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/TactileArray"; };
    const char * getMD5(){ return "294a763b90cb1a333d263f2097d3254e"; };

  };

}
#endif