#ifndef _ROS_sr_robot_msgs_Tactile_h
#define _ROS_sr_robot_msgs_Tactile_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Int16.h"

namespace sr_robot_msgs
{

  class Tactile : public ros::Msg
  {
    public:
      uint8_t data_length;
      std_msgs::Int16 st_data;
      std_msgs::Int16 * data;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
      uint8_t data_lengthT = *(inbuffer + offset++);
      if(data_lengthT > data_length)
        this->data = (std_msgs::Int16*)realloc(this->data, data_lengthT * sizeof(std_msgs::Int16));
      offset += 3;
      data_length = data_lengthT;
      for( uint8_t i = 0; i < data_length; i++){
      offset += this->st_data.deserialize(inbuffer + offset);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(std_msgs::Int16));
      }
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/Tactile"; };
    const char * getMD5(){ return "0f9585f47779b9607f760bef85a254c0"; };

  };

}
#endif