#ifndef _ROS_saphari_msgs_PerceivedEquipment_h
#define _ROS_saphari_msgs_PerceivedEquipment_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "saphari_msgs/Equipment.h"

namespace saphari_msgs
{

  class PerceivedEquipment : public ros::Msg
  {
    public:
      uint8_t perceived_length;
      saphari_msgs::Equipment st_perceived;
      saphari_msgs::Equipment * perceived;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = perceived_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < perceived_length; i++){
      offset += this->perceived[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t perceived_lengthT = *(inbuffer + offset++);
      if(perceived_lengthT > perceived_length)
        this->perceived = (saphari_msgs::Equipment*)realloc(this->perceived, perceived_lengthT * sizeof(saphari_msgs::Equipment));
      offset += 3;
      perceived_length = perceived_lengthT;
      for( uint8_t i = 0; i < perceived_length; i++){
      offset += this->st_perceived.deserialize(inbuffer + offset);
        memcpy( &(this->perceived[i]), &(this->st_perceived), sizeof(saphari_msgs::Equipment));
      }
     return offset;
    }

    const char * getType(){ return "saphari_msgs/PerceivedEquipment"; };
    const char * getMD5(){ return "9505c5a9dd72ab9b89b42b2241fbbd9f"; };

  };

}
#endif