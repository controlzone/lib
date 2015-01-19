#ifndef _ROS_cob_msgs_SiteSurvey_h
#define _ROS_cob_msgs_SiteSurvey_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "cob_msgs/Network.h"

namespace cob_msgs
{

  class SiteSurvey : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t networks_length;
      cob_msgs::Network st_networks;
      cob_msgs::Network * networks;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = networks_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < networks_length; i++){
      offset += this->networks[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t networks_lengthT = *(inbuffer + offset++);
      if(networks_lengthT > networks_length)
        this->networks = (cob_msgs::Network*)realloc(this->networks, networks_lengthT * sizeof(cob_msgs::Network));
      offset += 3;
      networks_length = networks_lengthT;
      for( uint8_t i = 0; i < networks_length; i++){
      offset += this->st_networks.deserialize(inbuffer + offset);
        memcpy( &(this->networks[i]), &(this->st_networks), sizeof(cob_msgs::Network));
      }
     return offset;
    }

    const char * getType(){ return "cob_msgs/SiteSurvey"; };
    const char * getMD5(){ return "f1063b16bb121ef190ae5edfe09d94ec"; };

  };

}
#endif