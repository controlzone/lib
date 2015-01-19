#ifndef _ROS_graft_GraftState_h
#define _ROS_graft_GraftState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Vector3.h"

namespace graft
{

  class GraftState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Pose pose;
      geometry_msgs::Twist twist;
      geometry_msgs::Vector3 acceleration;
      geometry_msgs::Vector3 gyro_bias;
      geometry_msgs::Vector3 accel_bias;
      float covariance[324];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->twist.serialize(outbuffer + offset);
      offset += this->acceleration.serialize(outbuffer + offset);
      offset += this->gyro_bias.serialize(outbuffer + offset);
      offset += this->accel_bias.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 324; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->covariance[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->twist.deserialize(inbuffer + offset);
      offset += this->acceleration.deserialize(inbuffer + offset);
      offset += this->gyro_bias.deserialize(inbuffer + offset);
      offset += this->accel_bias.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 324; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->covariance[i]));
      }
     return offset;
    }

    const char * getType(){ return "graft/GraftState"; };
    const char * getMD5(){ return "4744aac037427813b68053f3a09da177"; };

  };

}
#endif