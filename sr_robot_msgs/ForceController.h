#ifndef _ROS_SERVICE_ForceController_h
#define _ROS_SERVICE_ForceController_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_robot_msgs
{

static const char FORCECONTROLLER[] = "sr_robot_msgs/ForceController";

  class ForceControllerRequest : public ros::Msg
  {
    public:
      int16_t maxpwm;
      int16_t sgleftref;
      int16_t sgrightref;
      int16_t f;
      int16_t p;
      int16_t i;
      int16_t d;
      int16_t imax;
      int16_t deadband;
      int16_t sign;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_maxpwm;
      u_maxpwm.real = this->maxpwm;
      *(outbuffer + offset + 0) = (u_maxpwm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_maxpwm.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->maxpwm);
      union {
        int16_t real;
        uint16_t base;
      } u_sgleftref;
      u_sgleftref.real = this->sgleftref;
      *(outbuffer + offset + 0) = (u_sgleftref.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sgleftref.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sgleftref);
      union {
        int16_t real;
        uint16_t base;
      } u_sgrightref;
      u_sgrightref.real = this->sgrightref;
      *(outbuffer + offset + 0) = (u_sgrightref.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sgrightref.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sgrightref);
      union {
        int16_t real;
        uint16_t base;
      } u_f;
      u_f.real = this->f;
      *(outbuffer + offset + 0) = (u_f.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_f.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->f);
      union {
        int16_t real;
        uint16_t base;
      } u_p;
      u_p.real = this->p;
      *(outbuffer + offset + 0) = (u_p.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_p.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->p);
      union {
        int16_t real;
        uint16_t base;
      } u_i;
      u_i.real = this->i;
      *(outbuffer + offset + 0) = (u_i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_i.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->i);
      union {
        int16_t real;
        uint16_t base;
      } u_d;
      u_d.real = this->d;
      *(outbuffer + offset + 0) = (u_d.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_d.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->d);
      union {
        int16_t real;
        uint16_t base;
      } u_imax;
      u_imax.real = this->imax;
      *(outbuffer + offset + 0) = (u_imax.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imax.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->imax);
      union {
        int16_t real;
        uint16_t base;
      } u_deadband;
      u_deadband.real = this->deadband;
      *(outbuffer + offset + 0) = (u_deadband.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_deadband.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->deadband);
      union {
        int16_t real;
        uint16_t base;
      } u_sign;
      u_sign.real = this->sign;
      *(outbuffer + offset + 0) = (u_sign.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sign.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sign);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_maxpwm;
      u_maxpwm.base = 0;
      u_maxpwm.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_maxpwm.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->maxpwm = u_maxpwm.real;
      offset += sizeof(this->maxpwm);
      union {
        int16_t real;
        uint16_t base;
      } u_sgleftref;
      u_sgleftref.base = 0;
      u_sgleftref.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sgleftref.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sgleftref = u_sgleftref.real;
      offset += sizeof(this->sgleftref);
      union {
        int16_t real;
        uint16_t base;
      } u_sgrightref;
      u_sgrightref.base = 0;
      u_sgrightref.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sgrightref.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sgrightref = u_sgrightref.real;
      offset += sizeof(this->sgrightref);
      union {
        int16_t real;
        uint16_t base;
      } u_f;
      u_f.base = 0;
      u_f.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_f.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->f = u_f.real;
      offset += sizeof(this->f);
      union {
        int16_t real;
        uint16_t base;
      } u_p;
      u_p.base = 0;
      u_p.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_p.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->p = u_p.real;
      offset += sizeof(this->p);
      union {
        int16_t real;
        uint16_t base;
      } u_i;
      u_i.base = 0;
      u_i.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_i.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->i = u_i.real;
      offset += sizeof(this->i);
      union {
        int16_t real;
        uint16_t base;
      } u_d;
      u_d.base = 0;
      u_d.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_d.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->d = u_d.real;
      offset += sizeof(this->d);
      union {
        int16_t real;
        uint16_t base;
      } u_imax;
      u_imax.base = 0;
      u_imax.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imax.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->imax = u_imax.real;
      offset += sizeof(this->imax);
      union {
        int16_t real;
        uint16_t base;
      } u_deadband;
      u_deadband.base = 0;
      u_deadband.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_deadband.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->deadband = u_deadband.real;
      offset += sizeof(this->deadband);
      union {
        int16_t real;
        uint16_t base;
      } u_sign;
      u_sign.base = 0;
      u_sign.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sign.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sign = u_sign.real;
      offset += sizeof(this->sign);
     return offset;
    }

    const char * getType(){ return FORCECONTROLLER; };
    const char * getMD5(){ return "8bb059ffa85c4df492f2694e40ee3541"; };

  };

  class ForceControllerResponse : public ros::Msg
  {
    public:
      bool configured;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_configured;
      u_configured.real = this->configured;
      *(outbuffer + offset + 0) = (u_configured.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->configured);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_configured;
      u_configured.base = 0;
      u_configured.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->configured = u_configured.real;
      offset += sizeof(this->configured);
     return offset;
    }

    const char * getType(){ return FORCECONTROLLER; };
    const char * getMD5(){ return "d3b1a74026985b10664594fe60a8c3eb"; };

  };

  class ForceController {
    public:
    typedef ForceControllerRequest Request;
    typedef ForceControllerResponse Response;
  };

}
#endif
