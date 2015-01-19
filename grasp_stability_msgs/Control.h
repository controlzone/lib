#ifndef _ROS_SERVICE_Control_h
#define _ROS_SERVICE_Control_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace grasp_stability_msgs
{

static const char CONTROL[] = "grasp_stability_msgs/Control";

  class ControlRequest : public ros::Msg
  {
    public:
      int32_t command;
      const char* measurement_context_id;
      enum { CTRL_START = 0 };
      enum { CTRL_STOP = 1 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_command;
      u_command.real = this->command;
      *(outbuffer + offset + 0) = (u_command.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_command.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_command.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_command.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->command);
      uint32_t length_measurement_context_id = strlen(this->measurement_context_id);
      memcpy(outbuffer + offset, &length_measurement_context_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->measurement_context_id, length_measurement_context_id);
      offset += length_measurement_context_id;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_command;
      u_command.base = 0;
      u_command.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_command.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_command.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_command.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->command = u_command.real;
      offset += sizeof(this->command);
      uint32_t length_measurement_context_id;
      memcpy(&length_measurement_context_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_measurement_context_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_measurement_context_id-1]=0;
      this->measurement_context_id = (char *)(inbuffer + offset-1);
      offset += length_measurement_context_id;
     return offset;
    }

    const char * getType(){ return CONTROL; };
    const char * getMD5(){ return "3e8c36ca9a454fdd1d9690e53d57a07c"; };

  };

  class ControlResponse : public ros::Msg
  {
    public:
      int32_t result;
      enum { FAILURE = 0 };
      enum { SUCCESS = 1 };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_result.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_result.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_result.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_result.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_result.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_result.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return CONTROL; };
    const char * getMD5(){ return "0d9206728848e73f5b28b05b46562257"; };

  };

  class Control {
    public:
    typedef ControlRequest Request;
    typedef ControlResponse Response;
  };

}
#endif
