#ifndef _ROS_sr_robot_msgs_MotorSystemControls_h
#define _ROS_sr_robot_msgs_MotorSystemControls_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_robot_msgs
{

  class MotorSystemControls : public ros::Msg
  {
    public:
      int8_t motor_id;
      bool enable_backlash_compensation;
      bool increase_sgl_tracking;
      bool decrease_sgl_tracking;
      bool increase_sgr_tracking;
      bool decrease_sgr_tracking;
      bool initiate_jiggling;
      bool write_config_to_eeprom;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_motor_id;
      u_motor_id.real = this->motor_id;
      *(outbuffer + offset + 0) = (u_motor_id.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor_id);
      union {
        bool real;
        uint8_t base;
      } u_enable_backlash_compensation;
      u_enable_backlash_compensation.real = this->enable_backlash_compensation;
      *(outbuffer + offset + 0) = (u_enable_backlash_compensation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable_backlash_compensation);
      union {
        bool real;
        uint8_t base;
      } u_increase_sgl_tracking;
      u_increase_sgl_tracking.real = this->increase_sgl_tracking;
      *(outbuffer + offset + 0) = (u_increase_sgl_tracking.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->increase_sgl_tracking);
      union {
        bool real;
        uint8_t base;
      } u_decrease_sgl_tracking;
      u_decrease_sgl_tracking.real = this->decrease_sgl_tracking;
      *(outbuffer + offset + 0) = (u_decrease_sgl_tracking.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->decrease_sgl_tracking);
      union {
        bool real;
        uint8_t base;
      } u_increase_sgr_tracking;
      u_increase_sgr_tracking.real = this->increase_sgr_tracking;
      *(outbuffer + offset + 0) = (u_increase_sgr_tracking.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->increase_sgr_tracking);
      union {
        bool real;
        uint8_t base;
      } u_decrease_sgr_tracking;
      u_decrease_sgr_tracking.real = this->decrease_sgr_tracking;
      *(outbuffer + offset + 0) = (u_decrease_sgr_tracking.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->decrease_sgr_tracking);
      union {
        bool real;
        uint8_t base;
      } u_initiate_jiggling;
      u_initiate_jiggling.real = this->initiate_jiggling;
      *(outbuffer + offset + 0) = (u_initiate_jiggling.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->initiate_jiggling);
      union {
        bool real;
        uint8_t base;
      } u_write_config_to_eeprom;
      u_write_config_to_eeprom.real = this->write_config_to_eeprom;
      *(outbuffer + offset + 0) = (u_write_config_to_eeprom.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->write_config_to_eeprom);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_motor_id;
      u_motor_id.base = 0;
      u_motor_id.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->motor_id = u_motor_id.real;
      offset += sizeof(this->motor_id);
      union {
        bool real;
        uint8_t base;
      } u_enable_backlash_compensation;
      u_enable_backlash_compensation.base = 0;
      u_enable_backlash_compensation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable_backlash_compensation = u_enable_backlash_compensation.real;
      offset += sizeof(this->enable_backlash_compensation);
      union {
        bool real;
        uint8_t base;
      } u_increase_sgl_tracking;
      u_increase_sgl_tracking.base = 0;
      u_increase_sgl_tracking.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->increase_sgl_tracking = u_increase_sgl_tracking.real;
      offset += sizeof(this->increase_sgl_tracking);
      union {
        bool real;
        uint8_t base;
      } u_decrease_sgl_tracking;
      u_decrease_sgl_tracking.base = 0;
      u_decrease_sgl_tracking.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->decrease_sgl_tracking = u_decrease_sgl_tracking.real;
      offset += sizeof(this->decrease_sgl_tracking);
      union {
        bool real;
        uint8_t base;
      } u_increase_sgr_tracking;
      u_increase_sgr_tracking.base = 0;
      u_increase_sgr_tracking.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->increase_sgr_tracking = u_increase_sgr_tracking.real;
      offset += sizeof(this->increase_sgr_tracking);
      union {
        bool real;
        uint8_t base;
      } u_decrease_sgr_tracking;
      u_decrease_sgr_tracking.base = 0;
      u_decrease_sgr_tracking.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->decrease_sgr_tracking = u_decrease_sgr_tracking.real;
      offset += sizeof(this->decrease_sgr_tracking);
      union {
        bool real;
        uint8_t base;
      } u_initiate_jiggling;
      u_initiate_jiggling.base = 0;
      u_initiate_jiggling.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->initiate_jiggling = u_initiate_jiggling.real;
      offset += sizeof(this->initiate_jiggling);
      union {
        bool real;
        uint8_t base;
      } u_write_config_to_eeprom;
      u_write_config_to_eeprom.base = 0;
      u_write_config_to_eeprom.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->write_config_to_eeprom = u_write_config_to_eeprom.real;
      offset += sizeof(this->write_config_to_eeprom);
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/MotorSystemControls"; };
    const char * getMD5(){ return "0686822f46acfde0133711bd613a20f1"; };

  };

}
#endif