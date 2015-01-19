#ifndef _ROS_lighting_msgs_DmxCommand_h
#define _ROS_lighting_msgs_DmxCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "lighting_msgs/DmxFrame.h"

namespace lighting_msgs
{

  class DmxCommand : public ros::Msg
  {
    public:
      int8_t action;
      const char* name;
      uint8_t layers_length;
      lighting_msgs::DmxFrame st_layers;
      lighting_msgs::DmxFrame * layers;
      bool loop;
      const char* next;
      enum { DISPLAY = 0      };
      enum { PLAY = 1         };
      enum { STOP = 2         };
      enum { REMOVE = 3       };
      enum { STORE = 4        };
      enum { LOAD = 5         };

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_action;
      u_action.real = this->action;
      *(outbuffer + offset + 0) = (u_action.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->action);
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset++) = layers_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < layers_length; i++){
      offset += this->layers[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_loop;
      u_loop.real = this->loop;
      *(outbuffer + offset + 0) = (u_loop.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->loop);
      uint32_t length_next = strlen(this->next);
      memcpy(outbuffer + offset, &length_next, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->next, length_next);
      offset += length_next;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_action;
      u_action.base = 0;
      u_action.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->action = u_action.real;
      offset += sizeof(this->action);
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint8_t layers_lengthT = *(inbuffer + offset++);
      if(layers_lengthT > layers_length)
        this->layers = (lighting_msgs::DmxFrame*)realloc(this->layers, layers_lengthT * sizeof(lighting_msgs::DmxFrame));
      offset += 3;
      layers_length = layers_lengthT;
      for( uint8_t i = 0; i < layers_length; i++){
      offset += this->st_layers.deserialize(inbuffer + offset);
        memcpy( &(this->layers[i]), &(this->st_layers), sizeof(lighting_msgs::DmxFrame));
      }
      union {
        bool real;
        uint8_t base;
      } u_loop;
      u_loop.base = 0;
      u_loop.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->loop = u_loop.real;
      offset += sizeof(this->loop);
      uint32_t length_next;
      memcpy(&length_next, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_next; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_next-1]=0;
      this->next = (char *)(inbuffer + offset-1);
      offset += length_next;
     return offset;
    }

    const char * getType(){ return "lighting_msgs/DmxCommand"; };
    const char * getMD5(){ return "7a8beef39da2352041dd0af2417e2173"; };

  };

}
#endif