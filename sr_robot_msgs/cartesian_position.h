#ifndef _ROS_sr_robot_msgs_cartesian_position_h
#define _ROS_sr_robot_msgs_cartesian_position_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_robot_msgs
{

  class cartesian_position : public ros::Msg
  {
    public:
      const char* tip_name;
      float tip_pos_x;
      float tip_pos_y;
      float tip_pos_z;
      float tip_orientation_rho;
      float tip_orientation_theta;
      float tip_orientation_sigma;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_tip_name = strlen(this->tip_name);
      memcpy(outbuffer + offset, &length_tip_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->tip_name, length_tip_name);
      offset += length_tip_name;
      union {
        float real;
        uint32_t base;
      } u_tip_pos_x;
      u_tip_pos_x.real = this->tip_pos_x;
      *(outbuffer + offset + 0) = (u_tip_pos_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tip_pos_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tip_pos_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tip_pos_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tip_pos_x);
      union {
        float real;
        uint32_t base;
      } u_tip_pos_y;
      u_tip_pos_y.real = this->tip_pos_y;
      *(outbuffer + offset + 0) = (u_tip_pos_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tip_pos_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tip_pos_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tip_pos_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tip_pos_y);
      union {
        float real;
        uint32_t base;
      } u_tip_pos_z;
      u_tip_pos_z.real = this->tip_pos_z;
      *(outbuffer + offset + 0) = (u_tip_pos_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tip_pos_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tip_pos_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tip_pos_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tip_pos_z);
      union {
        float real;
        uint32_t base;
      } u_tip_orientation_rho;
      u_tip_orientation_rho.real = this->tip_orientation_rho;
      *(outbuffer + offset + 0) = (u_tip_orientation_rho.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tip_orientation_rho.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tip_orientation_rho.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tip_orientation_rho.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tip_orientation_rho);
      union {
        float real;
        uint32_t base;
      } u_tip_orientation_theta;
      u_tip_orientation_theta.real = this->tip_orientation_theta;
      *(outbuffer + offset + 0) = (u_tip_orientation_theta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tip_orientation_theta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tip_orientation_theta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tip_orientation_theta.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tip_orientation_theta);
      union {
        float real;
        uint32_t base;
      } u_tip_orientation_sigma;
      u_tip_orientation_sigma.real = this->tip_orientation_sigma;
      *(outbuffer + offset + 0) = (u_tip_orientation_sigma.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tip_orientation_sigma.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tip_orientation_sigma.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tip_orientation_sigma.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tip_orientation_sigma);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_tip_name;
      memcpy(&length_tip_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_tip_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_tip_name-1]=0;
      this->tip_name = (char *)(inbuffer + offset-1);
      offset += length_tip_name;
      union {
        float real;
        uint32_t base;
      } u_tip_pos_x;
      u_tip_pos_x.base = 0;
      u_tip_pos_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tip_pos_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tip_pos_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tip_pos_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tip_pos_x = u_tip_pos_x.real;
      offset += sizeof(this->tip_pos_x);
      union {
        float real;
        uint32_t base;
      } u_tip_pos_y;
      u_tip_pos_y.base = 0;
      u_tip_pos_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tip_pos_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tip_pos_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tip_pos_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tip_pos_y = u_tip_pos_y.real;
      offset += sizeof(this->tip_pos_y);
      union {
        float real;
        uint32_t base;
      } u_tip_pos_z;
      u_tip_pos_z.base = 0;
      u_tip_pos_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tip_pos_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tip_pos_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tip_pos_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tip_pos_z = u_tip_pos_z.real;
      offset += sizeof(this->tip_pos_z);
      union {
        float real;
        uint32_t base;
      } u_tip_orientation_rho;
      u_tip_orientation_rho.base = 0;
      u_tip_orientation_rho.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tip_orientation_rho.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tip_orientation_rho.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tip_orientation_rho.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tip_orientation_rho = u_tip_orientation_rho.real;
      offset += sizeof(this->tip_orientation_rho);
      union {
        float real;
        uint32_t base;
      } u_tip_orientation_theta;
      u_tip_orientation_theta.base = 0;
      u_tip_orientation_theta.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tip_orientation_theta.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tip_orientation_theta.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tip_orientation_theta.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tip_orientation_theta = u_tip_orientation_theta.real;
      offset += sizeof(this->tip_orientation_theta);
      union {
        float real;
        uint32_t base;
      } u_tip_orientation_sigma;
      u_tip_orientation_sigma.base = 0;
      u_tip_orientation_sigma.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tip_orientation_sigma.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tip_orientation_sigma.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tip_orientation_sigma.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tip_orientation_sigma = u_tip_orientation_sigma.real;
      offset += sizeof(this->tip_orientation_sigma);
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/cartesian_position"; };
    const char * getMD5(){ return "cfc3f1750a36a668eb93288ed1128f42"; };

  };

}
#endif