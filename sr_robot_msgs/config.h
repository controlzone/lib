#ifndef _ROS_sr_robot_msgs_config_h
#define _ROS_sr_robot_msgs_config_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sr_robot_msgs
{

  class config : public ros::Msg
  {
    public:
      const char* node_name;
      uint8_t list_of_parameters_length;
      char* st_list_of_parameters;
      char* * list_of_parameters;
      uint8_t length_of_list;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_node_name = strlen(this->node_name);
      memcpy(outbuffer + offset, &length_node_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->node_name, length_node_name);
      offset += length_node_name;
      *(outbuffer + offset++) = list_of_parameters_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < list_of_parameters_length; i++){
      uint32_t length_list_of_parametersi = strlen(this->list_of_parameters[i]);
      memcpy(outbuffer + offset, &length_list_of_parametersi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->list_of_parameters[i], length_list_of_parametersi);
      offset += length_list_of_parametersi;
      }
      *(outbuffer + offset + 0) = (this->length_of_list >> (8 * 0)) & 0xFF;
      offset += sizeof(this->length_of_list);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_node_name;
      memcpy(&length_node_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_node_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_node_name-1]=0;
      this->node_name = (char *)(inbuffer + offset-1);
      offset += length_node_name;
      uint8_t list_of_parameters_lengthT = *(inbuffer + offset++);
      if(list_of_parameters_lengthT > list_of_parameters_length)
        this->list_of_parameters = (char**)realloc(this->list_of_parameters, list_of_parameters_lengthT * sizeof(char*));
      offset += 3;
      list_of_parameters_length = list_of_parameters_lengthT;
      for( uint8_t i = 0; i < list_of_parameters_length; i++){
      uint32_t length_st_list_of_parameters;
      memcpy(&length_st_list_of_parameters, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_list_of_parameters; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_list_of_parameters-1]=0;
      this->st_list_of_parameters = (char *)(inbuffer + offset-1);
      offset += length_st_list_of_parameters;
        memcpy( &(this->list_of_parameters[i]), &(this->st_list_of_parameters), sizeof(char*));
      }
      this->length_of_list =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->length_of_list);
     return offset;
    }

    const char * getType(){ return "sr_robot_msgs/config"; };
    const char * getMD5(){ return "aad3efafb735fbac1153457b0e7c6e24"; };

  };

}
#endif