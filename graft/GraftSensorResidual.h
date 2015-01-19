#ifndef _ROS_graft_GraftSensorResidual_h
#define _ROS_graft_GraftSensorResidual_h

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

  class GraftSensorResidual : public ros::Msg
  {
    public:
      std_msgs::Header header;
      const char* name;
      geometry_msgs::Pose pose;
      geometry_msgs::Twist twist;
      geometry_msgs::Vector3 accel;
      float pose_covariance[36];
      float twist_covariance[36];
      float accel_covariance[9];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->twist.serialize(outbuffer + offset);
      offset += this->accel.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 36; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->pose_covariance[i]);
      }
      for( uint8_t i = 0; i < 36; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->twist_covariance[i]);
      }
      for( uint8_t i = 0; i < 9; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->accel_covariance[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->twist.deserialize(inbuffer + offset);
      offset += this->accel.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 36; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pose_covariance[i]));
      }
      for( uint8_t i = 0; i < 36; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->twist_covariance[i]));
      }
      for( uint8_t i = 0; i < 9; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->accel_covariance[i]));
      }
     return offset;
    }

    const char * getType(){ return "graft/GraftSensorResidual"; };
    const char * getMD5(){ return "f75937e1c71e90285875737addd2c780"; };

  };

}
#endif