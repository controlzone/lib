#ifndef _ROS_sr_robot_msgs_JointMuscleValveControllerCommand_h
#define _ROS_sr_robot_msgs_JointMuscleValveControllerCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_robot_msgs
{

  class JointMuscleValveControllerCommand : public ros::Msg
  {
    public:
      int8_t cmd_valve_muscle[2];
      uint64_t cmd_duration_ms[2];

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 2; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_cmd_valve_musclei;
      u_cmd_valve_musclei.real = this->cmd_valve_muscle[i];
      *(outbuffer + offset + 0) = (u_cmd_valve_musclei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cmd_valve_muscle[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_cmd_duration_msi;
      u_cmd_duration_msi.real = this->cmd_duration_ms[i];
      *(outbuffer + offset + 0) = (u_cmd_duration_msi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cmd_duration_msi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cmd_duration_msi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cmd_duration_msi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cmd_duration_ms[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 2; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_cmd_valve_musclei;
      u_cmd_valve_musclei.base = 0;
      u_cmd_valve_musclei.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cmd_valve_muscle[i] = u_cmd_valve_musclei.real;
      offset += sizeof(this->cmd_valve_muscle[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_cmd_duration_msi;
      u_cmd_duration_msi.base = 0;
      u_cmd_duration_msi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cmd_duration_msi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cmd_duration_msi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cmd_duration_msi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cmd_duration_ms[i] = u_cmd_duration_msi.real;
      offset += sizeof(this->cmd_duration_ms[i]);
      }
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/JointMuscleValveControllerCommand"; };
    const char * getMD5(){ return "1a35a9f185150fc2bca2640471eeb55f"; };

  };

}
#endif