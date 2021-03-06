#ifndef _ROS_posedetection_msgs_Curve1D_h
#define _ROS_posedetection_msgs_Curve1D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace posedetection_msgs
{

  class Curve1D : public ros::Msg
  {
    public:
      uint8_t pts_length;
      float st_pts;
      float * pts;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = pts_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pts_length; i++){
      union {
        float real;
        uint32_t base;
      } u_ptsi;
      u_ptsi.real = this->pts[i];
      *(outbuffer + offset + 0) = (u_ptsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ptsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ptsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ptsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pts[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t pts_lengthT = *(inbuffer + offset++);
      if(pts_lengthT > pts_length)
        this->pts = (float*)realloc(this->pts, pts_lengthT * sizeof(float));
      offset += 3;
      pts_length = pts_lengthT;
      for( uint8_t i = 0; i < pts_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pts;
      u_st_pts.base = 0;
      u_st_pts.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pts.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pts.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pts.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pts = u_st_pts.real;
      offset += sizeof(this->st_pts);
        memcpy( &(this->pts[i]), &(this->st_pts), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "posedetection_msgs/Curve1D"; };
    const char * getMD5(){ return "e5367ca89dc9a58670f8f288e2c52f5d"; };

  };

}
#endif