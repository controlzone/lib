#ifndef _ROS_sr_robot_msgs_EthercatDebug_h
#define _ROS_sr_robot_msgs_EthercatDebug_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sr_robot_msgs/FromMotorDataType.h"

namespace sr_robot_msgs
{

  class EthercatDebug : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t sensors_length;
      int16_t st_sensors;
      int16_t * sensors;
      sr_robot_msgs::FromMotorDataType motor_data_type;
      int16_t which_motors;
      int32_t which_motor_data_arrived;
      int32_t which_motor_data_had_errors;
      uint8_t motor_data_packet_torque_length;
      int16_t st_motor_data_packet_torque;
      int16_t * motor_data_packet_torque;
      uint8_t motor_data_packet_misc_length;
      int16_t st_motor_data_packet_misc;
      int16_t * motor_data_packet_misc;
      int32_t tactile_data_type;
      int16_t tactile_data_valid;
      uint8_t tactile_length;
      int16_t st_tactile;
      int16_t * tactile;
      int16_t idle_time_us;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = sensors_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < sensors_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_sensorsi;
      u_sensorsi.real = this->sensors[i];
      *(outbuffer + offset + 0) = (u_sensorsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sensorsi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sensors[i]);
      }
      offset += this->motor_data_type.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_which_motors;
      u_which_motors.real = this->which_motors;
      *(outbuffer + offset + 0) = (u_which_motors.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_which_motors.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->which_motors);
      union {
        int32_t real;
        uint32_t base;
      } u_which_motor_data_arrived;
      u_which_motor_data_arrived.real = this->which_motor_data_arrived;
      *(outbuffer + offset + 0) = (u_which_motor_data_arrived.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_which_motor_data_arrived.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_which_motor_data_arrived.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_which_motor_data_arrived.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->which_motor_data_arrived);
      union {
        int32_t real;
        uint32_t base;
      } u_which_motor_data_had_errors;
      u_which_motor_data_had_errors.real = this->which_motor_data_had_errors;
      *(outbuffer + offset + 0) = (u_which_motor_data_had_errors.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_which_motor_data_had_errors.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_which_motor_data_had_errors.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_which_motor_data_had_errors.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->which_motor_data_had_errors);
      *(outbuffer + offset++) = motor_data_packet_torque_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < motor_data_packet_torque_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_motor_data_packet_torquei;
      u_motor_data_packet_torquei.real = this->motor_data_packet_torque[i];
      *(outbuffer + offset + 0) = (u_motor_data_packet_torquei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_data_packet_torquei.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->motor_data_packet_torque[i]);
      }
      *(outbuffer + offset++) = motor_data_packet_misc_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < motor_data_packet_misc_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_motor_data_packet_misci;
      u_motor_data_packet_misci.real = this->motor_data_packet_misc[i];
      *(outbuffer + offset + 0) = (u_motor_data_packet_misci.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_data_packet_misci.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->motor_data_packet_misc[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_tactile_data_type;
      u_tactile_data_type.real = this->tactile_data_type;
      *(outbuffer + offset + 0) = (u_tactile_data_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tactile_data_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tactile_data_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tactile_data_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tactile_data_type);
      union {
        int16_t real;
        uint16_t base;
      } u_tactile_data_valid;
      u_tactile_data_valid.real = this->tactile_data_valid;
      *(outbuffer + offset + 0) = (u_tactile_data_valid.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tactile_data_valid.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->tactile_data_valid);
      *(outbuffer + offset++) = tactile_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < tactile_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_tactilei;
      u_tactilei.real = this->tactile[i];
      *(outbuffer + offset + 0) = (u_tactilei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tactilei.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->tactile[i]);
      }
      union {
        int16_t real;
        uint16_t base;
      } u_idle_time_us;
      u_idle_time_us.real = this->idle_time_us;
      *(outbuffer + offset + 0) = (u_idle_time_us.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_idle_time_us.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->idle_time_us);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t sensors_lengthT = *(inbuffer + offset++);
      if(sensors_lengthT > sensors_length)
        this->sensors = (int16_t*)realloc(this->sensors, sensors_lengthT * sizeof(int16_t));
      offset += 3;
      sensors_length = sensors_lengthT;
      for( uint8_t i = 0; i < sensors_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_sensors;
      u_st_sensors.base = 0;
      u_st_sensors.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_sensors.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_sensors = u_st_sensors.real;
      offset += sizeof(this->st_sensors);
        memcpy( &(this->sensors[i]), &(this->st_sensors), sizeof(int16_t));
      }
      offset += this->motor_data_type.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_which_motors;
      u_which_motors.base = 0;
      u_which_motors.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_which_motors.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->which_motors = u_which_motors.real;
      offset += sizeof(this->which_motors);
      union {
        int32_t real;
        uint32_t base;
      } u_which_motor_data_arrived;
      u_which_motor_data_arrived.base = 0;
      u_which_motor_data_arrived.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_which_motor_data_arrived.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_which_motor_data_arrived.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_which_motor_data_arrived.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->which_motor_data_arrived = u_which_motor_data_arrived.real;
      offset += sizeof(this->which_motor_data_arrived);
      union {
        int32_t real;
        uint32_t base;
      } u_which_motor_data_had_errors;
      u_which_motor_data_had_errors.base = 0;
      u_which_motor_data_had_errors.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_which_motor_data_had_errors.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_which_motor_data_had_errors.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_which_motor_data_had_errors.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->which_motor_data_had_errors = u_which_motor_data_had_errors.real;
      offset += sizeof(this->which_motor_data_had_errors);
      uint8_t motor_data_packet_torque_lengthT = *(inbuffer + offset++);
      if(motor_data_packet_torque_lengthT > motor_data_packet_torque_length)
        this->motor_data_packet_torque = (int16_t*)realloc(this->motor_data_packet_torque, motor_data_packet_torque_lengthT * sizeof(int16_t));
      offset += 3;
      motor_data_packet_torque_length = motor_data_packet_torque_lengthT;
      for( uint8_t i = 0; i < motor_data_packet_torque_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_motor_data_packet_torque;
      u_st_motor_data_packet_torque.base = 0;
      u_st_motor_data_packet_torque.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_motor_data_packet_torque.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_motor_data_packet_torque = u_st_motor_data_packet_torque.real;
      offset += sizeof(this->st_motor_data_packet_torque);
        memcpy( &(this->motor_data_packet_torque[i]), &(this->st_motor_data_packet_torque), sizeof(int16_t));
      }
      uint8_t motor_data_packet_misc_lengthT = *(inbuffer + offset++);
      if(motor_data_packet_misc_lengthT > motor_data_packet_misc_length)
        this->motor_data_packet_misc = (int16_t*)realloc(this->motor_data_packet_misc, motor_data_packet_misc_lengthT * sizeof(int16_t));
      offset += 3;
      motor_data_packet_misc_length = motor_data_packet_misc_lengthT;
      for( uint8_t i = 0; i < motor_data_packet_misc_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_motor_data_packet_misc;
      u_st_motor_data_packet_misc.base = 0;
      u_st_motor_data_packet_misc.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_motor_data_packet_misc.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_motor_data_packet_misc = u_st_motor_data_packet_misc.real;
      offset += sizeof(this->st_motor_data_packet_misc);
        memcpy( &(this->motor_data_packet_misc[i]), &(this->st_motor_data_packet_misc), sizeof(int16_t));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_tactile_data_type;
      u_tactile_data_type.base = 0;
      u_tactile_data_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tactile_data_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tactile_data_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tactile_data_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tactile_data_type = u_tactile_data_type.real;
      offset += sizeof(this->tactile_data_type);
      union {
        int16_t real;
        uint16_t base;
      } u_tactile_data_valid;
      u_tactile_data_valid.base = 0;
      u_tactile_data_valid.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tactile_data_valid.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tactile_data_valid = u_tactile_data_valid.real;
      offset += sizeof(this->tactile_data_valid);
      uint8_t tactile_lengthT = *(inbuffer + offset++);
      if(tactile_lengthT > tactile_length)
        this->tactile = (int16_t*)realloc(this->tactile, tactile_lengthT * sizeof(int16_t));
      offset += 3;
      tactile_length = tactile_lengthT;
      for( uint8_t i = 0; i < tactile_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_tactile;
      u_st_tactile.base = 0;
      u_st_tactile.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_tactile.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_tactile = u_st_tactile.real;
      offset += sizeof(this->st_tactile);
        memcpy( &(this->tactile[i]), &(this->st_tactile), sizeof(int16_t));
      }
      union {
        int16_t real;
        uint16_t base;
      } u_idle_time_us;
      u_idle_time_us.base = 0;
      u_idle_time_us.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_idle_time_us.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->idle_time_us = u_idle_time_us.real;
      offset += sizeof(this->idle_time_us);
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/EthercatDebug"; };
    const char * getMD5(){ return "ed9e30784a7d4571ecf4d526e7ff529f"; };

  };

}
#endif